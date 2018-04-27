#include <iostream>

class SimpleCat{
public:
    SimpleCat(); //constructor
    SimpleCat(SimpleCat&); //copy constructor
    ~SimpleCat(); //destructor
};

SimpleCat::SimpleCat()
{
    std::cout << "Simple Cat Constructor ..." << std::endl;

}

SimpleCat::SimpleCat(SimpleCat&)
{
    std::cout << "Simple Cat Copy Constructor ..." << std::endl;
}

SimpleCat::~SimpleCat()
{
    std::cout << "Simple Cat Destructor ..." << std::endl;

}

SimpleCat FunctionOne(SimpleCat theCat);
SimpleCat* FunctionTwo(SimpleCat *theCat);

int main()
{
    std::cout << "Making a cat ..." << std::endl;
    SimpleCat Frisky;
    std::cout << "Calling FunctionOne ..." << std::endl;
    FunctionOne(Frisky);
    std::cout << "Calling FunctionTwo ..." << std::endl;
    FunctionTwo(&Frisky);
    return 0;
} 

//FunctionOne, pass by value
SimpleCat FunctionOne(SimpleCat theCat)
{
    std::cout << "Function One. Returning ..." << std::endl;
    return theCat;
}

// functionTwo, passes by reference
SimpleCat* FunctionTwo (SimpleCat *theCat)
{
    std::cout << "Function Two. Returning ..." << std::endl;
    return theCat;
}