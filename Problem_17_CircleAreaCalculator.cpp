// Problem_17
// Program to calculate the area of a circle with input validation
// Allows the user to repeat the program

#include <iostream>
#include <limits>
#include <string>
#include <cmath>

// Clears the input buffer after invalid input
void clearInputLine()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Structure to group circle data
struct Circle
{
    float radius = 0;
};

// Reads a positive number from the user with validation
float readPositiveNumber(const std::string& prompt)
{
    float value{};
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        // Validate input
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
Circle readDimensions()
{
    return {
        readPositiveNumber("Please enter the circle's radius: ")
    };
}

// Calculates the area of the circle
float calculateArea(Circle& circle)
{
    constexpr float PI = 3.14159265359f;
    return PI * pow(circle.radius, 2);
}

// Prints the calculation result
void PrintResult(float Area)
{
    std::cout << "\nThe area of the circle is: " << Area << '\n';
}

// Asks the user if they want to repeat the program
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

// Controls program execution flow
void runProgram()
{
    do
    {
        Circle circle = readDimensions();
        float area = calculateArea(circle);
        PrintResult(area);

    } while (shouldRepeat());
}

// Program entry point
int main()
{
    runProgram();
    std::cout << "\nThanks for using this program 🙏\n";
    return 0;
}
