#include <iostream>

class SimpleCat
{
public:
    SimpleCat (int age, int weight);
    ~SimpleCat() {}
    int GetAge() { return itsAge; }
    int GetWeight() { return itsWeight; }

private:
    int itsAge;
    int itsWeight;
};

SimpleCat::SimpleCat(int age, int weight):
itsAge(age), itsWeight(weight) {}

SimpleCat & TheFunction();

int main()
{
    SimpleCat &rCat = TheFunction();
    int age = rCat.GetAge();
    std::cout << "rCat is " << age << " years old!" << std::endl;
    std::cout << "&rCat: " << &rCat << std::endl;
    //How do you get rid of that memory?
    SimpleCat *pCat = &rCat;
    delete pCat;
    //uh oh, rCat now refers to ??
    return 0;
}

SimpleCat &TheFunction()
{
    SimpleCat *pFrisky = new SimpleCat(5,9);
    std::cout << "pFrisky: " << pFrisky << std::endl;
    return *pFrisky;
}