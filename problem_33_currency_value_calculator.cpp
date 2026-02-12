// ===========================================================
// Problem_33 - Currency Calculator (Senior-Level Refactor)
// ===========================================================

#include <iostream>
#include <limits>
#include <string>
#include <cctype>
#include <iomanip>

// ===========================================================
// 📌 Configuration & Constants
// ===========================================================

namespace CurrencyValue
{
    constexpr int PENNY   = 1;
    constexpr int NICKEL  = 5;
    constexpr int DIME    = 10;
    constexpr int QUARTER = 25;
    constexpr int DOLLAR  = 100;
}

// ===========================================================
// 🧾 Domain Models
// ===========================================================

struct Currencies
{
    int pennies{};
    int nickels{};
    int dimes{};
    int quarters{};
    int dollars{};
};

struct CurrencyTotals
{
    long long totalPennies{};
    double totalDollars{};
};

// ===========================================================
// 🔧 Utility Functions
// ===========================================================

void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int readNonNegativeInt(const std::string& prompt)
{
    int value{};

    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail())
        {
            std::cout << "❌ Invalid input! Please enter a valid number.\n";
            clearInputBuffer();
            continue;
        }

        if (value < 0)
        {
            std::cout << "❌ Invalid input! Please enter a non-negative number.\n";
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();
        return value;
    }
}

// ===========================================================
// 📥 Input Layer
// ===========================================================

Currencies readCurrencies()
{
    return {
        readNonNegativeInt("Please enter the number of pennies: "),
        readNonNegativeInt("Please enter the number of nickels: "),
        readNonNegativeInt("Please enter the number of dimes: "),
        readNonNegativeInt("Please enter the number of quarters: "),
        readNonNegativeInt("Please enter the number of dollars: ")
    };
}

// ===========================================================
// 🧠 Business Logic
// ===========================================================

CurrencyTotals calculateTotals(const Currencies& currencies)
{
    using namespace CurrencyValue;

    CurrencyTotals totals{};

    totals.totalPennies =
          currencies.pennies  * PENNY
        + currencies.nickels  * NICKEL
        + currencies.dimes    * DIME
        + currencies.quarters * QUARTER
        + currencies.dollars  * DOLLAR;

    totals.totalDollars = totals.totalPennies / 100.0;

    return totals;
}

// ===========================================================
// 🖨️ Presentation Layer
// ===========================================================

void printTotals(const CurrencyTotals& totals)
{
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "\n----------------------------------------\n";
    std::cout << "💰 Currency Summary\n";
    std::cout << "----------------------------------------\n";
    std::cout << "Total Pennies : " << totals.totalPennies << "\n";
    std::cout << "Total Dollars : $" << totals.totalDollars << "\n";
    std::cout << "----------------------------------------\n";
}

// ===========================================================
// 🔁 Control Flow
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

        std::cerr << "❌ Invalid selection. Please enter 'y' or 'n'.\n";
    }
}

void runApplication()
{
    do
    {
        Currencies currencies = readCurrencies();
        CurrencyTotals totals = calculateTotals(currencies);
        printTotals(totals);

    } while (shouldRepeat());
}

// ===========================================================
// 🚀 Entry Point
// ===========================================================

int main()
{
    runApplication();
    std::cout << "\n🙏 Thanks for using this program!\n";
    return 0;
}
