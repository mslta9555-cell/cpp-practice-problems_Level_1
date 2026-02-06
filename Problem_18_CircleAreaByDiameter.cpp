// Problem_18_CircleAreaByDiameter.cpp
// Calculates the area of a circle using its diameter
// Includes input validation and repeat option

#include <iostream>
#include <limits>
#include <string>
#include <cctype>

// Clears invalid input from the buffer
void clearInputLine()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Groups circle data
struct Circle
{
    float diameter{};
};

// Reads a positive number safely from user
float readPositiveNumber(const std::string& prompt)
{
    float value{};
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail() || value <= 0)
        {
            std::cout << "❌ Please enter a valid positive number.\n";
            clearInputLine();
            continue;
        }

        clearInputLine();
        return value;
    }
}

// Reads circle dimensions
Circle readCircle()
{
    return { readPositiveNumber("Please enter the diameter of the circle: ") };
}

// Calculates circle area using diameter
float calculateArea(const Circle& circle)
{
    constexpr float PI = 3.14159265359f;
    float radius = circle.diameter / 2.0f;
    return PI * radius * radius;
}

// Prints result to the user
void printArea(float area)
{
    std::cout << "\n✅ The area of the circle is: " << area << '\n';
}

// Asks user whether to repeat the program
bool shouldRepeat()
{
    char choice{};
    while (true)
    {
        std::cout << "\n🔁 Repeat program? (y/n): ";
        std::cin >> choice;
        clearInputLine();

        choice = static_cast<char>(std::tolower(static_cast<unsigned char>(choice)));
        if (choice == 'y') return true;
        if (choice == 'n') return false;

        std::cout << "❌ Invalid choice. Enter y or n.\n";
    }
}

// Controls program flow
void runProgram()
{
    do
    {
        Circle circle = readCircle();
        float area = calculateArea(circle);
        printArea(area);

    } while (shouldRepeat());
}

// Program entry point
int main()
{
    runProgram();
    std::cout << "\nThanks for using this program 🙏\n";
    return 0;
}
