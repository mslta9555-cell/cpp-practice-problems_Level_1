// Problem_15: Calculate rectangle area given one side and diagonal

#include <iostream>
#include <limits>
#include <cctype>
#include <string>
#include <math.h>

// -------------------------
// Clear invalid input from input buffer
// -------------------------
void ClearInputLine()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// -------------------------
// Struct to store rectangle dimensions
// -------------------------
struct Rectangle
{
    float side{};       // One side of rectangle
    float diagonal{};   // Diagonal of rectangle
};

// -------------------------
// Read a positive float from user
// -------------------------
float ReadPositiveNumber(const std::string& prompt)
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
            ClearInputLine();
            continue;
        }

        ClearInputLine();
        return value;
    }
}

// -------------------------
// Read rectangle dimensions from user
// -------------------------
Rectangle ReadDimensions()
{
    return
    {
        ReadPositiveNumber("Please enter the side: "),
        ReadPositiveNumber("Please enter the diagonal: ")
    };
}

// -------------------------
// Calculate rectangle area
// -------------------------
float CalculateArea(const Rectangle& rectangle)
{
    // Check if diagonal is valid
    if (rectangle.diagonal <= rectangle.side)
    {
        return -1; // Invalid rectangle
    }

    // Calculate other side using Pythagoras theorem
    float otherSide = sqrt(pow(rectangle.diagonal, 2) - pow(rectangle.side, 2));
    return rectangle.side * otherSide;
}

// -------------------------
// Print area result
// -------------------------
void PrintArea(float area)
{
    if (area < 0)
    {
        std::cout << "❌ Error: The diagonal cannot be less than or equal to the side length.\n";
    }
    else
    {
        std::cout << "\nRectangle area is: " << area << "\n";
    }
}

// -------------------------
// Ask user if they want to repeat
// -------------------------
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

// -------------------------
// Program loop
// -------------------------
void RunProgram()
{
    do
    {
        Rectangle rect  = ReadDimensions();       // Read input
        float area = CalculateArea(rect);         // Calculate area
        PrintArea(area);                          // Print result
    } while (ShouldRepeat());
}

// -------------------------
// Program entry point
// -------------------------
int main()
{
    RunProgram();
    std::cout << "\nThanks for using this program 🙏\n";
    return 0;
}
