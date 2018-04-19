#include <iostream>

//get an approximate value of Pi
constexpr double getPi() {
    return (double) 22 /7;
}

int main()
{
    float radius;

    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    // the area equals Pi * the radius of the circle: 
    double area = getPi() * (radius * radius);

    std::cout << "\nCircle's area: " << area << std::endl;

    return 0;
}
