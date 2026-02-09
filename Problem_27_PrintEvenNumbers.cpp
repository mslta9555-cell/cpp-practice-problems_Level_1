// Problem_27 - Print Even Numbers and Their Sum

#include <iostream>
#include <limits>
#include <string>
#include <cctype>

// ✅ Clears any invalid input from the input buffer
void clearInputBuffer() {
    std::cin.clear(); // Reset error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore leftover input
}

// ✅ Struct to hold the user-entered number
struct NumberInfo {
    int value = 0;
};

// ✅ Reads a positive integer from the user with validation
int readPositiveNumber(const std::string& prompt) {
    int number = 0;

    while (true) {
        std::cout << prompt;
        std::cin >> number;

        // Check if input is valid
        if (std::cin.fail()) {
            std::cout << "❌ Invalid input! Please enter a valid number.\n";
            clearInputBuffer();
            continue;
        }

        // Check if number is greater than zero
        if (number <= 0) {
            std::cout << "❌ Invalid input! Please enter a number greater than 0.\n";
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();
        return number; // Return valid number
    }
}

// ✅ Checks if a number is even
bool isEven(int number) {
    return number % 2 == 0;
}

// ✅ Prints all even numbers up to the user's number and calculates their sum
void printEvenNumbers(const NumberInfo& num) {
    std::cout << "\n--- Even Numbers up to " << num.value << " ---\n";
    int sum = 0;

    for (int i = 1; i < num.value; ++i) {
        if (isEven(i)) {
            std::cout << i << " "; // Print even number
            sum += i;              // Add to sum
        }
    }

    std::cout << "\n✅ Sum of Even numbers: " << sum << "\n"; // Print sum
}

// ✅ Asks the user if they want to repeat the program
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

// ✅ Main program loop
void runProgram() {
    do {
        NumberInfo num{ readPositiveNumber("🔢 Please enter a number: ") }; // Read user input
        printEvenNumbers(num); // Print even numbers and sum
    } while (askToRepeat());
}

// ✅ Program entry point
int main() {
    runProgram(); // Start program
    std::cout << "\n🙏 Thanks for using this program!\n";
    return 0;
}
