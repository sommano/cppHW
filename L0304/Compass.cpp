#include <iostream>

int main()
{
    // set up enumeration
    enum Direction { North, Northeast, East, Southeast, South, Southwest, West, Northwest };

    // create a variable to hold it
    Direction heading;

    //initialize that variable
    heading = Southeast;

    std::cout << "Moving " << heading << std::endl;
    return 0;
}