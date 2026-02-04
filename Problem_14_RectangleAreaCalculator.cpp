// Problem_14: Rectangle Area Calculator

#include <iostream>
#include <limits>
#include <cctype>
#include <string>

// Clears invalid input from input buffer
void ClearInputLine()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Groups rectangle dimensions
struct Rectangle
{
    float length{};
    float width{};
};

// Reads a valid positive number from user
float ReadPositiveNumber(const std::string& prompt)
{
    float value{};
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail() || value <= 0)
        {
            std::cout << "❌ Please enter a valid positive number.\n";
            ClearInputLine();
            continue;
        }

        ClearInputLine();
        return value;
    }
}

// Reads rectangle dimensions
Rectangle ReadDimensions()
{
    return {
        ReadPositiveNumber("Please enter the length: "),
        ReadPositiveNumber("Please enter the width: ")
    };
}

// Calculates rectangle area
float CalculateArea(const Rectangle& rectangle)
{
    return rectangle.length * rectangle.width;
}

// Prints area result
void PrintArea(float area)
{
    std::cout << "\n✅ The area of the rectangle is: "
              << area << " units²\n";
}

// Ask user to repeat program
bool ShouldRepeat()
{
    char choice{};
    while (true)
    {
        std::cout << "\n🔁 Repeat program? (y/n): ";
        std::cin >> choice;
        ClearInputLine();

        choice = static_cast<char>(std::tolower(static_cast<unsigned char>(choice)));
        if (choice == 'y') return true;
        if (choice == 'n') return false;

        std::cout << "❌ Invalid choice. Enter y or n.\n";
    }
}

// Program controller
void RunProgram()
{
    do
    {
        PrintArea(CalculateArea(ReadDimensions()));
    } while (ShouldRepeat());
}

// Entry point
int main()
{
    RunProgram();
    std::cout << "\nThanks for using this program 🙏\n";
    return 0;
}
