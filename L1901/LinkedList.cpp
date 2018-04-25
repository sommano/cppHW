#include <iostream>

enum { kIsSmaller, kIsLarger, kIsSame };

//any calss in this linked list must support two
//functionss: show (displays the value) and compare
// (returns relative position)

class Data 
{
public:
    Data(int newVal):value(newVal) {}
    ~Data() {}
    int compare(const Data&);
    void show() { std::cout << value << "\n"; }
private:
    int value;
};

//a function that decides where in the list a 
//particular object belongs.

int Data::compare(const Data& otherData)
{
    if (value < otherData.value)
        return kIsSmaller;
    if (value > otherData.value)
        return kIsLarger;
    else
        return kIsSame;
}

//forward class declarations
class Node;
class HeadNode;
class TailNode;
class InternalNode;

//an adt representing the node object in the list.
// every derived class must overrirde insert() and show()
class Node
{
public:
    Node() {}
    virtual ~Node() {}
    virtual Node* insert(Data* data) = 0;
    virtual void show() = 0;
private:
};

//a node to hold objects of type Data.
class InternalNode : public Node
{
public: 
    InternalNode(Data* data, Node* next);
    virtual ~InternalNode() { delete next; delete data; }
    virtual Node* insert(Data* data);
    virtual void show()
        { data->show(); next->show(); } // delegate!

private: 
    Data* data; // the data itself
    Node* next; // points to next node in the linked list
};

//a simple constructor
InternalNode::InternalNode(Data* newData, Node* newNext): 
data(newData), next(newNext)
{
}

//A function to store a new object in the list.
//the object is passed to the node which figures out
//where it goes and inserts it into the list.
Node* InternalNode::insert(Data* otherData)
{
    //is the new object bigger or smaller than me?
    int result = data->compare(*otherData);

    switch (result)
    {
    //if it is the same as me it goes first
    case kIsSame: //fall through
    case kIsLarger: //new data come before me
        {
            InternalNode* dataNode =
                new InternalNode(otherData, this);
            return dataNode;
        }
    //it is bigger, so pass it on to the next
    //node and let it handle it.
    case kIsSmaller: 
        next = next->insert(otherData);
        return this;
    }
    return this; //appease the compiler
}

//the last node in the list
class TailNode : public Node
{
public:
    TailNode() {}
    virtual ~TailNode() {}
    virtual Node* insert(Data* data);
    virtual void show() {}
private: 
};

//if data comes to me, it must be inserted before me
//since nothing goes after the Tail
Node* TailNode::insert(Data* data)
{
    InternalNode* dataNode = new InternalNode(data, this);
    return dataNode;
}

// the head node, which holds no data but instead points
// to the beginning of the list.
class HeadNode : public Node
{
public: 
    HeadNode();
    virtual ~HeadNode() { delete next; }
    virtual Node* insert(Data* data);
    virtual void show() { next->show(); }
private: 
    Node* next;
};

//the first node in the list, which creates the Tail
HeadNode::HeadNode()
{
    next = new TailNode;
}

//since nothing comes before the head, just pass
//the data on to the next node
Node* HeadNode::insert(Data* data)
{
    next = next->insert(data);
    return this;
}

//i get all the credit and do none of the work
class LinkedList
{
public:
    LinkedList();
    ~LinkedList() { delete head; }
    void insert(Data* data);
    void showAll() { head->show(); }
private: 
    HeadNode* head;
};

//at birth, I create the head node, which creates
//the tail node
LinkedList::LinkedList()
{
    head = new HeadNode;
}

//delegate to a head node
void LinkedList::insert(Data* pData)
{
    head->insert(pData);
}

//put in all these classes to the test
int main()
{
    Data* pData;
    int val;
    LinkedList ll;

    //store user values in a linked list
    while (true)
    {
        std::cout << "What value (0 to stop)? ";
        std::cin >> val;
        if (!val)
            break;
        pData = new Data(val);
        ll.insert(pData);
    }

    //display the list
    ll.showAll();
    return 0;

}
