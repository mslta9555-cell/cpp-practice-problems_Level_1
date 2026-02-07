// Problem_22 - Age Range Validation Program

#include <iostream>
#include <limits>
#include <string>
#include <cctype>

// Defines the valid age range
constexpr int MIN_AGE = 18;
constexpr int MAX_AGE = 45;

// Clears any remaining or invalid input from the buffer
void clearInputLine()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Stores user age information
struct AgeInfo
{
    int Age{};
};

// Reads a positive integer value with validation
int readPositiveNumber(const std::string& prompt)
{
    int value = 0;

    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        // Validate input
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

// Reads the user's age
AgeInfo readUserAge()
{
    return {
        readPositiveNumber("👤 Please enter your age: ")
    };
}

// Checks if age is within the allowed range
bool IsAgeValid(const AgeInfo& info)
{
    return (info.Age >= MIN_AGE && info.Age <= MAX_AGE);
}

// Prints the validation result
void printAgeValidationResult(bool isAgeValid)
{
    if (isAgeValid)
        std::cout << "\n✅ Age is valid. You are within the accepted range (18–45).\n";
    else
        std::cout << "\n❌ Invalid age. You must be between 18 and 45.\n";
}

// Asks the user whether to repeat the program
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

// Controls the program execution flow
void runProgram()
{
    do
    {
        AgeInfo info = readUserAge();
        bool isAgeValid = IsAgeValid(info);
        printAgeValidationResult(isAgeValid);

    } while (shouldRepeat());
}

// Program entry point
int main()
{
    runProgram();
    std::cout << "\n🙏 Thanks for using this program!\n";
    return 0;
}
