#pragma once

#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cfloat>
#include <cmath>

class ScalarConverter
{
private:
    template <typename T>
    static void print_convert_value(T value);

public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();
    static void convert(const std::string &literal);
};