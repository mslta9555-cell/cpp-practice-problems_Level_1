// Problem_29 - Calculate Powers (2, 3, 4) of a Number

#include <iostream>
#include <limits>
#include <cctype>
#include <string>

// Clears any invalid or leftover input from the buffer
void clearInputBuffer() {
    std::cin.clear(); 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Struct to store the user input number
struct Number
{
    int value{};
};

// Allowed input range
constexpr int MIN_VALUE = 1;
constexpr int MAX_VALUE = 20;

// Reads a positive number from the user with validation
int readPositiveNumber(const std::string& prompt) {
    int number{};

    while (true) {
        std::cout << prompt;
        std::cin >> number;

        // Check for non-numeric input
        if (std::cin.fail()) {
            std::cout << "❌ Invalid input! Please enter a valid number.\n";
            clearInputBuffer();
            continue;
        }

        // Check if number is within allowed range
        if (number < MIN_VALUE || number > MAX_VALUE) {
            std::cout << "❌ Invalid input! Please enter a number between 1 and 20.\n";
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();
        return number; // Return valid number
    }
}

// Struct to store exponentiation results
struct ExponentiationResult
{
    long long powerOf2{};
    long long powerOf3{};
    long long powerOf4{};
};

// Calculates powers of the number (2, 3, and 4)
ExponentiationResult calculatePowers(const Number& number)
{
    return {
        number.value * number.value,                             // n^2
        number.value * number.value * number.value,              // n^3
        number.value * number.value * number.value * number.value // n^4
    };
}

// Prints the calculated results
void printExponentiationResult(const ExponentiationResult& result)
{
    std::cout << "\nThe result of raising the number to the power of 2: " << result.powerOf2 << '\n';
    std::cout << "The result of raising the number to the power of 3: " << result.powerOf3 << '\n';
    std::cout << "The result of raising the number to the power of 4: " << result.powerOf4 << '\n';
}

// Asks the user if they want to repeat the program
bool askToRepeat()
{
    char choice{};
    while (true)
    {
        std::cout << "\n🔁 Do you want to repeat the program? (y/n): ";
        std::cin >> choice;
        clearInputBuffer();

        choice = static_cast<char>(std::tolower(static_cast<unsigned char>(choice)));

        if (choice == 'y') return true;  // Repeat program
        if (choice == 'n') return false; // Exit program

        std::cout << "❌ Invalid choice. Please enter y or n.\n";
    }
}

// Controls the program flow
void runProgram()
{
    do
    {
        Number number{ readPositiveNumber("\nPlease enter a positive number: ") };
        ExponentiationResult result = calculatePowers(number);
        printExponentiationResult(result);

    } while (askToRepeat());
}

// Program entry point
int main()
{
    runProgram();
    std::cout << "\nThanks for using this program.\n";
    return 0;
}
