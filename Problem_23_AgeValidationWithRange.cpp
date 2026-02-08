// Problem_23 - Age Validation Program (Interview-Perfect Version)

#include <iostream>
#include <limits>
#include <string>
#include <cctype>

constexpr int MIN_AGE = 18;
constexpr int MAX_AGE = 45;

// Clears invalid or leftover input from the input buffer
void clearInputLine()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Holds user age information
struct AgeInfo
{
    int age{};
};

// Reads a validated positive integer from the user
int readPositiveNumber(const std::string& prompt)
{
    int value{};

    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail() || value <= 0)
        {
            std::cout << "❌ Invalid input! Please enter a valid positive number.\n";
            clearInputLine();
            continue;
        }

        clearInputLine();
        return value;
    }
}

// Reads user's age
AgeInfo readUserAge()
{
    return { readPositiveNumber("👤 Please enter your age: ") };
}

// Business logic: checks if age is within the valid range
bool isAgeValid(const AgeInfo& info)
{
    return info.age >= MIN_AGE && info.age <= MAX_AGE;
}

// Displays validation result
void printAgeValidationResult(bool isValid)
{
    if (isValid)
        std::cout << "\n✅ Age is valid. You are within the accepted range (18–45).\n";
    else
        std::cout << "\n❌ Invalid age. You must be between 18 and 45.\n";
}

// Keeps asking the user until a valid age is entered
AgeInfo getValidUserAge()
{
    AgeInfo info{};

    do
    {
        info = readUserAge();
        bool isValid = isAgeValid(info);
        printAgeValidationResult(isValid);

    } while (!isAgeValid(info));

    return info;
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

// Controls program execution
void runProgram()
{
    do
    {
        getValidUserAge();
    } while (shouldRepeat());
}

// Entry point
int main()
{
    runProgram();
    std::cout << "\n🙏 Thanks for using this program!\n";
    return 0;
}
