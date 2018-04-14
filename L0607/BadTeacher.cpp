#include <iostream>

int main()
{
    char grade;
    std::cout << "Enter your letter grade (ABCDF): ";
    std::cin >> grade;
    switch (grade)
    {
        case 'A':
            std::cout << "Finally!\n";
            break;
        case 'B':
            std::cout << "You can do better!\n";
            break;
        case 'C':
            std::cout << "I'm disappointed in you!\n";
            break;
        case 'D':
            std::cout << "You're not smart!\n";
            break;
        case 'F':
            std::cout << "Get out of my sight!\n";
            break;
        default:
            std::cout << "That's not even a grade!\n";
            break;
    }
    return 0;
}