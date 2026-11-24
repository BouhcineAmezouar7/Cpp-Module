#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>
#include <string>
#include <cstdlib>

void loadDatabase(std::map<std::string, double> &btcPricesDB, const std::string &filename);
void processInputFile(std::map<std::string, double> &btcPricesDB, const std::string &filename);

#endif