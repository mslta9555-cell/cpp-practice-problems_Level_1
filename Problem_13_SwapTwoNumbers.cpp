// Problem_13: Swap Two Positive Numbers

#include <iostream>
#include <cctype>
#include <limits>
#include <string>
#include <algorithm>

// Clears invalid input from the input buffer
void ClearInputLine() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Struct to store two numbers together
struct Numbers
{
    int firstNumber{}, secondNumber{};
};

// Swaps the two numbers using pass-by-reference
Numbers Swap(Numbers& numbers)
{
    // Using standard library swap function
    std::swap(numbers.firstNumber, numbers.secondNumber);
    return numbers;
}

// Reads a positive number with validation
int ReadPositiveNumber(const std::string& Prompt)
{
    int number;
    while (true)
    {
        std::cout << Prompt;
        std::cin >> number;

        // Check if input is not a number
        if (std::cin.fail())
        {
            std::cout << "❌ Invalid Input! Please enter a valid number.\n";
            ClearInputLine();
            continue;
        }

        // Check if number is positive
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
    number.firstNumber = ReadPositiveNumber("\nPlease enter the first number: ");
    number.secondNumber = ReadPositiveNumber("Please enter the second number: ");
    return number;
}

// Prints numbers before and after swapping
void PrintAfterSwap(const Numbers& original, const Numbers& swapped)
{
    std::cout << "\n==============================\n";
    std::cout << "        🔄 Swap Result\n";
    std::cout << "==============================\n";

    // Display original values
    std::cout << "Before Swap:\n";
    std::cout << "  • First Number:  " << original.firstNumber
              << "\n  • Second Number: " << original.secondNumber << "\n";

    // Display swapped values
    std::cout << "\nAfter Swap:\n";
    std::cout << "  • First Number:  " << swapped.firstNumber
              << "\n  • Second Number: " << swapped.secondNumber << "\n";
}

// Asks user if they want to repeat the program
bool DoYouWantToRepeat()
{
    char Answer;
    do
    {
        std::cout << "\n\n🔁 Do you want to repeat the program? (y/n): ";
        std::cin >> Answer;
        ClearInputLine();

        Answer = static_cast<char>(std::tolower(static_cast<unsigned char>(Answer)));
        if (Answer == 'y') return true;
        if (Answer == 'n') return false;

        std::cout << "❌ Invalid input! Please enter y or n.\n";
    } while (true);
}

// Runs the main program logic
void RunProgram()
{
    do
    {
        Numbers original = ReadNumbers();   // Read input
        Numbers swapped = Swap(original);   // Swap numbers
        PrintAfterSwap(original, swapped);  // Print result
    }
    while (DoYouWantToRepeat());
}

// Program entry point
int main()
{
    RunProgram();
    std::cout << "\nThanks for using this program 🙏\n";
    return 0;
}
