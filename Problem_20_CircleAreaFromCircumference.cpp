// Problem_20 - Calculate Circle Area from Circumference
#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <cmath>

// Clears invalid input from the input buffer
void clearInputLine()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Represents a circle by its circumference
struct Circle
{
    float circumference{};
};

// Reads a validated positive number from the user
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

// Reads circle's circumference
Circle readCircle()
{
    return { readPositiveNumber("Please enter the circumference of the circle: ") };
}

// Calculates circle area from circumference
float calculateAreaFromCircumference(const Circle& circle)
{
    constexpr float PI = 3.14159265359f;
    return (circle.circumference * circle.circumference) / (4.0f * PI);
}

// Prints the area
void printArea(float area)
{
    std::cout << "\n✅ The area of the circle is: " << area << " units²\n";
}

// Asks user if they want to repeat
bool shouldRepeat()
{
    char choice{};
    while (true)
    {
        std::cout << "\n🔁 Do you want to repeat the program? (y/n): ";
        std::cin >> choice;
        clearInputLine();

        choice = static_cast<char>(std::tolower(static_cast<unsigned char>(choice)));
        if (choice == 'y') return true;
        if (choice == 'n') return false;

        std::cout << "❌ Invalid choice. Enter y or n.\n";
    }
}

// Program controller
void runProgram()
{
    do
    {
        Circle circle = readCircle();
        float area = calculateAreaFromCircumference(circle);
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
