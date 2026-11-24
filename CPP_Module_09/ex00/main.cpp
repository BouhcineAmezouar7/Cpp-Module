#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::cout.precision(10);
    std::map<std::string, double> btcPricesDB;

    loadDatabase(btcPricesDB, "data.csv");  // load the bitcoin prices database from the CSV file
    processInputFile(btcPricesDB, argv[1]); // process the input file provided as a command-line argument, using the loaded database

    return 0;
}