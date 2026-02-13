// ===========================================================
// Problem_34 - Calculator (Production-Level Refactor)
// ===========================================================

#include <iostream>
#include <string>
#include <limits>
#include <cctype>

// ===========================================================
// Domain Types
// ===========================================================

enum class Operator
{
    Add,
    Subtract,
    Multiply,
    Divide
};

struct CalculationRequest
{
    int lhs{};
    int rhs{};
    Operator op{};
};

struct CalculationResult
{
    bool success{};
    int value{};
    std::string errorMessage{};
};

// ===========================================================
// Utility
// ===========================================================

void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// ===========================================================
// Input Validation
// ===========================================================

int readNonNegativeInt(const std::string& prompt)
{
    int value{};

    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail() || value < 0)
        {
            std::cout << "❌ Invalid input. Please enter a non-negative number.\n";
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();
        return value;
    }
}

Operator readOperator()
{
    char input{};

    while (true)
    {
        std::cout << "Please enter operator (+ - * /): ";
        std::cin >> input;
        clearInputBuffer();

        switch (input)
        {
            case '+': return Operator::Add;
            case '-': return Operator::Subtract;
            case '*': return Operator::Multiply;
            case '/': return Operator::Divide;
            default:
                std::cout << "❌ Invalid operator.\n";
        }
    }
}

CalculationRequest readCalculationRequest()
{
    return {
        readNonNegativeInt("Please enter first number: "),
        readNonNegativeInt("Please enter second number: "),
        readOperator()
    };
}

// ===========================================================
// Business Logic (Pure & Testable)
// ===========================================================

CalculationResult calculate(const CalculationRequest& request)
{
    switch (request.op)
    {
        case Operator::Add:
            return { true, request.lhs + request.rhs, "" };

        case Operator::Subtract:
            return { true, request.lhs - request.rhs, "" };

        case Operator::Multiply:
            return { true, request.lhs * request.rhs, "" };

        case Operator::Divide:
            if (request.rhs == 0)
                return { false, 0, "Division by zero is not allowed." };
            return { true, request.lhs / request.rhs, "" };
    }

    return { false, 0, "Unknown operation." };
}

// ===========================================================
// Presentation Layer
// ===========================================================

void printResult(const CalculationResult& result)
{
    if (result.success)
        std::cout << "\n✅ Result: " << result.value << "\n";
    else
        std::cout << "\n❌ Error: " << result.errorMessage << "\n";
}

// ===========================================================
// Control Flow
// ===========================================================

bool shouldRepeat()
{
    char choice{};

    while (true)
    {
        std::cout << "\nDo you want to repeat the program? (y/n): ";
        std::cin >> choice;
        clearInputBuffer();

        choice = static_cast<char>(std::tolower(static_cast<unsigned char>(choice)));

        if (choice == 'y') return true;
        if (choice == 'n') return false;

        std::cout << "❌ Invalid selection.\n";
    }
}

void runApplication()
{
    do
    {
        CalculationRequest request = readCalculationRequest();
        CalculationResult result = calculate(request);
        printResult(result);

    } while (shouldRepeat());
}

// ===========================================================
// Entry Point
// ===========================================================

int main()
{
    runApplication();
    std::cout << "\n🙏 Thanks for using this program!\n";
    return 0;
}
