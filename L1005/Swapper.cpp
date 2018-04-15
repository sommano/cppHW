#include <iostream>

int main()
{
    int value1 = 12500;
    int value2 = 1700;
    int *pointer2 = nullptr;

    //give pointer the address of value2
    pointer2 = &value2;

    // dereference the pointer and assign tp value1
    value1 = *pointer2;

    std::cout << "value1 = " << value1 << "\n";

    return 0;
}