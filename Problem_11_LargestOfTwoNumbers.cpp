// Problem_11: Find the larger number between two positive numbers

#include <iostream>
#include <ios>
#include <cctype>
#include <limits>
#include <algorithm>

// Clears invalid input from the input buffer
void ClearInputLine() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Struct to group two related numbers together
struct Numbers
{
    int firstNumber{};
    int secondNumber{};
};

// Reads a positive number with input validation
int ReadPositiveNumber(const std::string& Prompt)
{
    int number;
    while (true)
    {
        std::cout << Prompt;
        std::cin >> number;

        // Check for non-numeric input
        if (std::cin.fail())
        {
            std::cout << "❌ Invalid Input! Please enter a valid number.\n";
            ClearInputLine();
            continue;
        }

        // Check for non-positive numbers
        if (number <= 0)
        {
            std::cout << "❌ Invalid Input! Please enter a positive number.\n";
            ClearInputLine();
            continue;
        }

        ClearInputLine();
        return number;
    }
}

// Reads two positive numbers from the user
Numbers ReadNumbers()
{
    Numbers number;
    number.firstNumber = ReadPositiveNumber("Please enter the first number: ");
    number.secondNumber = ReadPositiveNumber("Please enter the second number: ");
    return number;
}

// Returns the larger number
int GetBignumber(const Numbers& number)
{
    return (number.firstNumber >= number.secondNumber)
        ? number.firstNumber
        : number.secondNumber;
    // Alternative: return std::max(number.firstNumber, number.secondNumber);
}

// Prints the comparison result
void PrintResult(const Numbers& number)
{
    int BigNumber = GetBignumber(number);

    std::cout << "\n--- Comparison Result ---\n";

    if (number.firstNumber == number.secondNumber)
    {
        std::cout << "✅ The two numbers entered (" << BigNumber << ") are equal.\n";
    }
    else
    {
        std::cout << "The larger number between "
                  << number.firstNumber << " and "
                  << number.secondNumber << " is: "
                  << BigNumber << ".\n";
    }
}

// Asks the user if they want to repeat the program
bool DoYouWantToRepeat()
{
    char answer;
    do
    {
        std::cout << "\n🔁 Do you want to repeat the program? (y/n): ";
        std::cin >> answer;
        ClearInputLine();

        answer = static_cast<char>(std::tolower(static_cast<unsigned char>(answer)));
        if (answer == 'y') return true;
        if (answer == 'n') return false;

        std::cout << "❌ Invalid input! Please enter y or n.\n";
    } while (true);
}

// Runs the program loop
void RunProgram()
{
    do
    {
        PrintResult(ReadNumbers());
    } while (DoYouWantToRepeat());
}

// Program entry point
int main()
{
    RunProgram();
    std::cout << "\nThanks for using this program 🙏\n";
    return 0;
}
