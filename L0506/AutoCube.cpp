#include <iostream>

auto findArea(int length, int width = 20, int height = 12);

auto findArea(int length, int width, int height)
{
    return (length * width * height);
}

int main()
{
    int length = 100;
    int width = 50;
    int height = 2;
    int area;

    area = findArea(length, width, height);
    std::cout << "First area: " << area << "\n\n";

    area = findArea(length, width);
    std::cout << "Second area: " << area << "\n\n";

    area = findArea(length);
    std::cout << "Third area: " << area << "\n\n";
    return 0;
}