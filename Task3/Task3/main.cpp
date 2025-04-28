#include "../Library/Rectangle.h"
#include <iostream>

/**
 * @brief function for input
 * @param message - message for user
 * @return user input
*/
int input(const char* message);

/**
 * @brief function for input point
 * @param message - message for user
 * @return user input
 */
Point inputPoint(const char* message);

/**
 * @brief enum for variants of rectangle input
 */
enum {
    /**
     * @brief variant that use top left and bottom right angles
     */
    ANGLES2 = 0,
    /**
     * @brief variant that use top left angle, width and height
     */
    AngleAndWidthHeight = 1,
    /**
     * @brief variant that use keyboard
     */
    KEYBOARD = 2,
};

/**
 * @brief main function
 * @return 0
 */
int main(void)
{
    std::cout << "Input number of variant:"<<
        ANGLES2<<", "<<KEYBOARD<<" "<<AngleAndWidthHeight << std::endl;
    int var;
    std::cin >> var;

    Rectangle rect1;
    switch (var)
    {
        case ANGLES2 :
            {
                Point topLeft = inputPoint("Input top left point");
                Point bottomRight = inputPoint("Input bottom right point");
                Rectangle rect1(topLeft, bottomRight);
                break;
            }
        case AngleAndWidthHeight:
            {
                Point topLeft = inputPoint("Input top left point");
                int width = input("Input width");
                int height = input("Input height");
                Rectangle rect1(topLeft, width, height);
                break;
            }
        case KEYBOARD:
            {
                Rectangle rect1;
                std::cin >> rect1;
                break;
            }
        default:
            {
                std::cout << "Incorrect input" << std::endl;
                throw;
            }
    }
    rect1.draw(std::cout);
    return 0;
}

int input(const char* message)
{
    int input;
    if (message != nullptr)
    {
        std::cout << message << std::endl;
    }
    std::cin >> input;
    if (std::cin.fail())
    {
        std::cout << "Incorrect input" << std::endl;
        throw;
    }
    return input;
}

Point inputPoint(const char* message)
{
    Point point;
    if (message != nullptr)
    {
        std::cout << message << std::endl;
    }
    std::cin >> point;
    if (std::cin.fail())
    {
        std::cout << "Incorrect input" << std::endl;
        throw;
    }
    return point;
}

