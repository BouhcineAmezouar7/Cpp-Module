#include "BitcoinExchange.hpp"

// trim leading and trailing whitespace from a string
static std::string trim(const std::string &str)
{
    size_t start = str.find_first_not_of(" \t\r\n"); // find first non-whitespace character
    if (start == std::string::npos)                  // string is all whitespace
        return "";
    size_t end = str.find_last_not_of(" \t\r\n"); // find last non-whitespace character
    return str.substr(start, end - start + 1);    // return trimmed substring
}

// check if a year is a leap year
// example: 2000 is a leap year (divisible by 400), 1900 is not (divisible by 100 but not 400), 2020 is a leap year (divisible by 4 but not 100)
static bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); // leap year if divisible by 4 but not 100, or divisible by 400
}

static bool isValidDate(const std::string &date)
{
    if (date.length() != 10) // must be exactly 10 characters (YYYY-MM-DD)
        return false;
    // check - positions
    if (date[4] != '-' || date[7] != '-')
        return false;

    // check that all other characters are digits
    for (size_t i = 0; i < date.length(); i++)
    {
        if (i == 4 || i == 7) // skip the '-' characters
            continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i]))) // cast to unsigned char to avoid undefined behavior with negative char values
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 0 || month < 1 || month > 12 || day < 1)
        return false;

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isLeapYear(year)) // if it's a leap year, February has 29 days
        daysInMonth[2] = 29;

    if (day > daysInMonth[month]) // like April 31st is invalid (April has only 30 days)
        return false;

    return true;
}

static bool isValidValue(const std::string &value, int &flag)
{
    char *end; // pointer to track where the number parsing ends
    double val;
    // use strtod to convert string to double and check for errors
    val = std::strtod(value.c_str(), &end); // convert string to double, end points to the first character after the number

    // no conversion happened like "abc" or empty string
    if (end == value.c_str())
    {
        flag = -1;
        return false;
    }

    // leftover characters like "123abc" (valid number followed by invalid characters)
    if (*end != '\0')
    {
        flag = -1;
        return false;
    }

    if (val < 0)
    {
        flag = -2;
        return false;
    }

    if (val > 1000)
    {
        flag = -3;
        return false;
    }

    return true;
}

static void processLine(std::map<std::string, double> &btcPricesDB, std::string date, std::string value)
{
    std::map<std::string, double>::iterator priceIt;
    int flag = 0;

    date = trim(date);
    value = trim(value);

    if (value.empty() || !isValidDate(date))
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return;
    }

    if (!isValidValue(value, flag))
    {
        if (flag == -1)
            std::cout << "Error: bad value => " << value << std::endl;
        if (flag == -2)
            std::cout << "Error: not a positive number." << std::endl;
        if (flag == -3)
            std::cout << "Error: too large a number." << std::endl;
        return;
    }

    priceIt = btcPricesDB.upper_bound(date); // find the first date in the database that is greater than the input date
    if (priceIt == btcPricesDB.begin())
    {
        std::cout << "Error: date is too early (before bitcoin database starts)" << std::endl;
        return;
    }

    --priceIt; // move back to the last date that is less than or equal to the input date (the most recent price before or on the input date)

    double valueDouble = std::strtod(value.c_str(), NULL); // convert the value string to a double for calculation
    double result = valueDouble * priceIt->second;

    std::cout << date << " => " << value << " = " << result << std::endl;
}

void loadDatabase(std::map<std::string, double> &btcPricesDB, const std::string &filename)
{
    std::ifstream file(filename.c_str()); // open the database file
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database file.");

    std::string line;
    std::getline(file, line); // skip header

    while (std::getline(file, line))
    {
        size_t pos = line.find(',');  // find the comma that separates date and price
        if (pos == std::string::npos) // invalid line format (no comma)
        {
            std::cout << "Error: bad line format => " << trim(line) << std::endl;
            continue;
        }

        std::string date = trim(line.substr(0, pos));      // date is the part before the comma, trim whitespace
        std::string priceStr = trim(line.substr(pos + 1)); // price is the part after the comma, trim whitespace

        if (!isValidDate(date)) // validate date format and values
        {
            std::cout << "Error: bad date format => " << date << std::endl;
            continue;
        }

        double price = std::atof(priceStr.c_str()); // convert price string to double
        btcPricesDB[date] = price;
    }

    file.close();
}

void processInputFile(std::map<std::string, double> &btcPricesDB, const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    std::getline(file, line);   // skip header
    if (line != "date | value") // check header format
    {
        std::cout << "Error: bad header format in input file." << std::endl;
        return;
    }

    while (std::getline(file, line))
    {
        size_t pos = line.find('|');
        if (pos == std::string::npos) // invalid line format (no '|')
        {
            std::cout << "Error: bad input => " << trim(line) << std::endl;
            continue;
        }

        std::string date = line.substr(0, pos);   // date is the part before the '|'
        std::string value = line.substr(pos + 1); // value is the part after the '|'

        processLine(btcPricesDB, date, value);
    }

    file.close();
}
