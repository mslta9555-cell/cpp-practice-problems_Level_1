// Problem_31 - Simple Student Grade Evaluator

#include <iostream>
#include <limits>
#include <string>
#include <cctype>

// ----------------------------
// Constants
// ----------------------------
constexpr int MIN_grade = 0;   // Minimum valid grade
constexpr int MAX_grade = 100; // Maximum valid grade

// ----------------------------
// Utility Functions
// ----------------------------

// Clears invalid input from the buffer
void clearInputBuffer() {
    std::cin.clear(); // Reset error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Remove leftover input
}

// ----------------------------
// Data Structures
// ----------------------------
struct Grade {
    int grade = 0; // Stores the student's grade
};

// ----------------------------
// Input Functions
// ----------------------------

// Reads a validated grade from the user
int readGrade(const std::string& prompt) {
    int number{};

    while (true) {
        std::cout << prompt;
        std::cin >> number;

        // Check for invalid input
        if (std::cin.fail()) {
            std::cout << "❌ Invalid input! Please enter a number between " 
                      << MIN_grade << " and " << MAX_grade << "\n";
            clearInputBuffer();
            continue;
        }

        // Check if number is within range
        if (number < MIN_grade || number > MAX_grade) {
            std::cout << "❌ Invalid input! Please enter a number between " 
                      << MIN_grade << " and " << MAX_grade << "\n";
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();
        return number; // Return valid number
    }
}

// Reads a Grade struct from the user
Grade readGrade() {
    Grade grade;
    grade.grade = readGrade("Please enter the student's grade (0–100): ");
    return grade;
}

// ----------------------------
// Business Logic
// ----------------------------

// Determines the grade evaluation letter
char getGradeEvaluation(const Grade& grade) {
    if (grade.grade >= 90) return 'A';
    else if (grade.grade >= 80) return 'B';
    else if (grade.grade >= 70) return 'C';
    else if (grade.grade >= 60) return 'D';
    else if (grade.grade >= 50) return 'E';
    else return 'F';
}

// ----------------------------
// Output Functions
// ----------------------------

// Prints the grade evaluation and a descriptive message
void printEvaluation(char evaluation) {
    std::cout << "\n✅ The student's evaluation is: [" << evaluation << "]\n";

    switch (evaluation) {
        case 'A': std::cout << "Excellent 🌟\n"; break;
        case 'B': std::cout << "Very Good 👍\n"; break;
        case 'C': std::cout << "Good 🙂\n"; break;
        case 'D': std::cout << "Pass 😅\n"; break;
        case 'E': std::cout << "Weak ⚠️\n"; break;
        case 'F': std::cout << "Fail ❌\n"; break;
    }
}

// ----------------------------
// Control Flow
// ----------------------------

// Asks user if they want to repeat the program
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

// ----------------------------
// Program Loop
// ----------------------------
void runProgram() {
    do {
        Grade grade = readGrade();                  // Read student's grade
        char evaluation = getGradeEvaluation(grade); // Determine evaluation
        printEvaluation(evaluation);                // Display evaluation
    } while (askToRepeat());
}

// ----------------------------
// Entry Point
// ----------------------------
int main() {
    runProgram();
    std::cout << "\n🙏 Thanks for using this program!\n";
    return 0;
}
