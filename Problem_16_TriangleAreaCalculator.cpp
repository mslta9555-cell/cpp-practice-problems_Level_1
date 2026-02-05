// Problem_16: Triangle Area Calculator

#include <iostream>
#include <limits>
#include <cctype>
#include <string>

// Clears any invalid input from the input buffer
void clearInputLine() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Struct to group triangle dimensions together
struct triangle
{
    float base{};
    float height{};
};

// Reads a positive number with input validation
float readPositiveNumber(const std::string& prompt)
{
    float value{};
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        // Validate input (non-numeric or non-positive)
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

// Reads triangle base and height from the user
triangle readDimensions()
{
    return
    {
        readPositiveNumber("Please enter the Base: "),
        readPositiveNumber("Please enter the Height: ")
    };
}

// Calculates the area of the triangle
float CalculateArea(const triangle& Triangle)
{
    return 0.5f * Triangle.base * Triangle.height;
}

// Prints the calculated area
void printArea(float area)
{
    std::cout << "\n✅ The area of the triangle is: "
              << area << " units²\n"; 
}

// Asks the user whether to repeat the program
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

// Controls the program flow
void runProgram()
{
    do
    {
        triangle dimensions = readDimensions();
        float area = CalculateArea(dimensions);
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
