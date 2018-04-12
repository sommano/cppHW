#include <iostream>

int main()
{
    int grade;

    std::cout << "Enter a grade (1-100): ";
    std::cin >> grade;

    if (grade >= 70)
    {
        if (grade >= 90)
        {
            std::cout << "\nYou got an A. Great job!\n";
            return 0;
        }
        if (grade >= 80)
        {
            std::cout << "\nYou got a B. Good work!\n";
        }
        std::cout << "\nYou got a C. Perfectly adequate!\n";

        return 0;

    }
}