#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}
ScalarConverter::~ScalarConverter() {}

template <typename T>
void ScalarConverter::print_convert_value(T value)
{
    // char
    if (std::isnan(value) || value > std::numeric_limits<char>::max() || value < std::numeric_limits<char>::min()) // max: 127, min: -128
        std::cout << "char : impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(value)))
        std::cout << "char : Non displayable" << std::endl;
    else
        std::cout << "char : '" << static_cast<char>(value) << "'" << std::endl;

    // int
    if (std::isnan(value) || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
        std::cout << "int : impossible" << std::endl;
    else
        std::cout << "int : " << static_cast<int>(value) << std::endl;

    // float
    float f = static_cast<float>(value);
    std::cout << "float : " << std::fixed << std::setprecision(1) << f << 'f' << std::endl;

    // double
    std::cout << "double : " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
    // char
    if (literal.size() == 1 && !std::isdigit(literal[0]))
    {
        print_convert_value(literal[0]);
        return;
    }

    // float inf
    if (literal == "nanf" || literal == "-inff" || literal == "+inff")
    {
        float f = literal[0] == '-' ? -INFINITY : literal[0] == '+' ? INFINITY
                                                                    : NAN;
        print_convert_value(f);
        return;
    }

    // double inf
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
    {
        double d = literal[0] == '-' ? -INFINITY : literal[0] == '+' ? INFINITY
                                                                     : NAN;
        print_convert_value(d);
        return;
    }

    // float
    if (literal[literal.size() - 1] == 'f')
    {
        char *end;
        float f = std::strtof(literal.c_str(), &end);
        if (*end != 'f')
            return (std::cout << "Invalid float literal\n", void());
        print_convert_value(f);
        return;
    }

    // int
    char *end;
    long l = std::strtol(literal.c_str(), &end, 10);
    if (*end == '\0')
        return (print_convert_value(l));

    // double
    double d = std::strtod(literal.c_str(), &end);
    if (*end != '\0')
        return (std::cout << "Invalid literal\n", void());
    print_convert_value(d);
}
