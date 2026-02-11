// Problem_30 - Base and Power Calculator (Senior-Level Version)

#include <iostream>
#include <limits>
#include <string>
#include <cctype>
#include <cmath> // for pow function

// ✅ Utility function: Clears any invalid input from the buffer
void clearInputBuffer() {
    std::cin.clear(); // Reset error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard leftover input
}

// ✅ Struct to hold base and exponent values
struct NumberAndPower {
    int base{};   // The base number
    int power{};  // The exponent
};

// ✅ Struct to store the result of exponentiation
struct ExponentiationResult {
    long long result{}; // Calculated power result
};

// ✅ Define valid input range constants
constexpr int MIN_VALUE = 1;
constexpr int MAX_VALUE = 20;

// ✅ Reads a positive integer within the allowed range with input validation
int readPositiveNumber(const std::string& prompt) {
    int number{};
    while (true) {
        std::cout << prompt;
        std::cin >> number;

        if (std::cin.fail()) {
            std::cout << "❌ Invalid input! Please enter a valid number.\n";
            clearInputBuffer();
            continue;
        }

        if (number < MIN_VALUE || number > MAX_VALUE) {
            std::cout << "❌ Invalid input! Please enter a number between " 
                      << MIN_VALUE << " and " << MAX_VALUE << ".\n";
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();
        return number;
    }
}

// ✅ Reads both base and exponent values from the user
NumberAndPower readBaseAndPower() {
    return {
        readPositiveNumber("\nPlease enter the base number (max 20): "),
        readPositiveNumber("Please enter the power (max 20): ")
    };
}

// ✅ Calculates base^power using pow function
ExponentiationResult calculatePower(const NumberAndPower &data) {
    return { static_cast<long long>(pow(data.base, data.power)) };
}

// ✅ Prints the calculation result
void printExponentiationResult(const NumberAndPower& data, const ExponentiationResult& result) {
    std::cout << "\n✅ " << data.base << " ^ " << data.power << " = " << result.result << "\n";
}

// ✅ Asks user if they want to repeat the program
bool askToRepeat() {
    char choice{};
    while (true) {
        std::cout << "\nDo you want to repeat the program? (y/n): ";
        std::cin >> choice;
        clearInputBuffer();

        choice = static_cast<char>(std::tolower(static_cast<unsigned char>(choice)));

        if (choice == 'y') return true;   // Repeat program
        if (choice == 'n') return false;  // Exit program

        std::cerr << "❌ Invalid selection. Please enter 'y' or 'n'.\n";
    }
}

// ✅ Core program loop
void runProgram() {
    do {
        NumberAndPower data = readBaseAndPower();           // Read user input
        ExponentiationResult result = calculatePower(data); // Compute exponentiation
        printExponentiationResult(data, result);           // Display result
    } while (askToRepeat());
}

// ✅ Program entry point
int main() {
    runProgram();
    std::cout << "\n🙏 Thanks for using this program!\n";
    return 0;
}
