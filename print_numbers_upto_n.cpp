// Problem_24
// Program that reads a positive number and prints numbers from 1 to that value

#include <iostream>
#include <limits>
#include <string>
#include <cctype>

// Clears any invalid or leftover input from the input buffer
void clearInputLine()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Holds a user-entered number
struct Number
{
    int value{};
};

// Reads a positive integer from the user with validation
int readPositiveNumber(const std::string& prompt)
{
    int value = 0;

    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        // Check for invalid or non-positive input
        if (std::cin.fail() || value <= 0)
        {
            std::cout << "❌ Invalid input! Please enter a valid number.\n";
            clearInputLine();
            continue;
        }

        clearInputLine();
        return value;
    }
}

// Reads the number from the user and stores it in a struct
Number readNumber()
{
    return { readPositiveNumber("🔢 Please enter a number: ") };
}

// Prints numbers from 1 up to the entered number
void printNumbers(const Number& number)
{
    std::cout << "\nNumbers from 1 to " << number.value << ":\n";

    for (int i = 1; i <= number.value; ++i)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";
}

// Asks the user if they want to repeat the program
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

        std::cout << "❌ Invalid choice. Please enter y or n.\n";
    }
}

// Controls the main program flow
void runProgram()
{
    do
    {
        Number value = readNumber();
        printNumbers(value);

    } while (shouldRepeat());
}

// Program entry point
int main()
{
    runProgram();
    std::cout << "\n🙏 Thanks for using this program!\n";
    return 0;
}
