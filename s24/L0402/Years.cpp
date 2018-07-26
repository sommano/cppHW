#include <iostream>

int main()
{
    int year = 2016;
    std::cout << "The year " << ++year << " passes.\n";
    std::cout << "The year " << ++year << " passes.\n";
    std::cout << "The year " << ++year << " passes.\n";

    std::cout << "\nIt is now " << year << ".";
    std::cout << " Have the chicago Cubs won the World Series yet?\n";

    std::cout << "\nThe year " << year++ << " passes.\n";
    std::cout << "The year " << year++ << " passes.\n";
    std::cout << "The year " << year++ << " passes.\n";

    std::cout << "\nSurely the chicago Cubs won the World Series yet.\n";
    return 0;
}