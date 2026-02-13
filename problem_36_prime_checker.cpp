// ===========================================================
// Problem_36 - Prime Number Checker (Production-Level)
// ===========================================================

#include <iostream>
#include <limits>
#include <cctype>
#include <cmath>
#include <string>
#include <cstdint>  

// ===========================================================
//  Utility
// ===========================================================
void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// ===========================================================
//  Domain Types
// ===========================================================
struct Number
{
    int value{};
};

struct PrimeCheckResult
{
    int number{};
    bool isPrime{};
};

// ===========================================================
//  Input
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
            std::cout << "❌ Invalid input! Please enter a non-negative integer.\n";
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();
        return value;
    }
}

// ===========================================================
//  Business Logic
// ===========================================================

// Optimized production-level prime checker
bool isPrime(int num)
{
    if (num <= 1) return false;      // 0,1 and negatives are not prime
    if (num <= 3) return true;       // 2,3 are prime
    if (num % 2 == 0 || num % 3 == 0) return false;

    // All primes >3 are of the form 6k ± 1
    for (int i = 5; i * i <= num; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }

    return true;
}

PrimeCheckResult checkPrime(const Number& number)
{
    return { number.value, isPrime(number.value) };
}

// ===========================================================
//  Presentation
// ===========================================================
void printResult(const PrimeCheckResult& result)
{
    if (result.isPrime)
        std::cout << "✅ The number " << result.number << " is a prime number.\n";
    else
        std::cout << "❌ The number " << result.number << " is NOT a prime number.\n";
}

// ===========================================================
//  Control Flow
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

        std::cout << "❌ Invalid selection. Please enter 'y' or 'n'.\n";
    }
}

void runApplication()
{
    do
    {
        Number num{ readNonNegativeInt("Please enter a number: ") };
        PrimeCheckResult result = checkPrime(num);
        printResult(result);
    } while (shouldRepeat());
}

// ===========================================================
//  Entry Point
// ===========================================================
int main()
{
    runApplication();
    std::cout << "\n🙏 Thanks for using this program!\n";
    return 0;
}
