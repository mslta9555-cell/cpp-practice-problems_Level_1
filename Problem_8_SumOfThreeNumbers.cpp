// Problem_8: Sum of Three Positive Numbers
#include <iostream>
#include <ios>
#include <cctype>
#include <limits>
#include <string> 

// ---------------------------
// Helper function: clears the input buffer
// ---------------------------
void ClearInputLine() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// ---------------------------
// Struct to hold three numbers
// ---------------------------
struct Numbers {
    int FirstNumber{};
    int SecondNumber{};
    int ThirdNumber{};
};

// ---------------------------
// Reads a positive number from user
// Keeps asking until a valid number is entered
// ---------------------------
int ReadPositiveNumber(const std::string& Prompt)
{
    int number;
    while (true)
    {
        std::cout << Prompt;
        std::cin >> number;

        if (std::cin.fail())
        {
            std::cout << "❌ Invalid Input! Please enter a valid number.\n";
            ClearInputLine();
            continue;
        }
        else if (number <= 0)
        {
            std::cout << "❌ Invalid Input! Please enter a positive number.\n";
            ClearInputLine();
            continue;
        }
        else
        {
            ClearInputLine();
            return number; // valid number
        }
    }
}

// ---------------------------
// Reads three numbers from the user
// ---------------------------
Numbers ReadNumbers()
{
    Numbers number;

    number.FirstNumber = ReadPositiveNumber("\nPlease enter the first number: ");
    number.SecondNumber = ReadPositiveNumber("Please enter the second number: ");
    number.ThirdNumber = ReadPositiveNumber("Please enter the third number: ");

    return number;
}

// ---------------------------
// Calculates the sum of three numbers
// ---------------------------
int CalculateSum(const Numbers& number)
{
    return number.FirstNumber + number.SecondNumber + number.ThirdNumber;
}

// ---------------------------
// Prints the sum result
// ---------------------------
void PrintSum(const Numbers& number)
{
    std::cout << "\n✅ The sum of ("
              << number.FirstNumber << ", "
              << number.SecondNumber << ", "
              << number.ThirdNumber << ") = "
              << CalculateSum(number) << "\n";
}

// ---------------------------
// Asks user if they want to repeat
// ---------------------------
bool DoYouWantToRepeat()
{
    char answer;

    do
    {
        std::cout << "\n🔁 Do you want to calculate another sum? (y/n): ";
        std::cin >> answer;
        ClearInputLine();

        answer = static_cast<char>(std::tolower(static_cast<unsigned char>(answer)));

        if (answer == 'y') return true;
        if (answer == 'n') return false;

        std::cout << "❌ Invalid input! Please enter y or n.\n";

    } while (true);
}

// ---------------------------
// Main program loop
// ---------------------------
void RunProgram()
{
    do
    {
        std::cout << "\n--- 🧮 Sum Calculation Program ---\n";
        PrintSum(ReadNumbers());
    } while (DoYouWantToRepeat());
}

// ---------------------------
// Program entry point
// ---------------------------
int main()
{
    RunProgram();
    std::cout << "\nThanks for using this program 🙏\n";
    return 0;
}
