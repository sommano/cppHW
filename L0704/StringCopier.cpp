#include <iostream>
#include <string.h>

int main()
{
    char string1[] = "Free the bound periodicals!";
    char string2[80];

    strcpy(string2, string1);

    std::cout << "String1: " << string1 << std::endl;
    std::cout << "String2: " << string2 << std::endl;
    return 0;
}