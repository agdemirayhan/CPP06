#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>

// Helper to count decimal places for double output
static int countDecimalPlaces(const std::string &s)
{
    size_t dotPos = s.find('.');
    if (dotPos == std::string::npos)
        return 0;

    size_t end = s.find_first_not_of("0123456789", dotPos + 1);
    if (end == std::string::npos)
        end = s.length();

    int count = static_cast<int>(end - dotPos - 1);
    return std::min(count, 15); // Cap at 15 decimal digits
}

static bool isChar(const std::string &s)
{
    return s.length() == 1 && std::isprint(s[0]) && !std::isdigit(s[0]);
}

static bool isInt(const std::string &s)
{
    char *end;
    errno = 0;
    long val = std::strtol(s.c_str(), &end, 10);
    return *end == '\0' && errno != ERANGE && val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max();
}

static bool isFloat(const std::string &s)
{
    if (s == "nanf" || s == "+inff" || s == "-inff")
        return true;
    char *end;
    errno = 0;
    std::strtof(s.c_str(), &end);
    return errno != ERANGE && *end == 'f' && *(end + 1) == '\0';
}

static bool isDouble(const std::string &s)
{
    if (s == "nan" || s == "+inf" || s == "-inf")
        return true;
    char *end;
    errno = 0;
    std::strtod(s.c_str(), &end);
    return errno != ERANGE && *end == '\0';
}

void ScalarConverter::convert(const std::string &literal)
{
    int i = 0;
    float f = 0.0f;
    double d = 0.0;

    if (isChar(literal))
    {
        std::cout << "char: '" << literal[0] << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(literal[0]) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(literal[0]) << std::endl;
        return;
    }
    else if (isInt(literal))
    {
        i = std::atoi(literal.c_str());
        f = static_cast<float>(i);
        d = static_cast<double>(i);
    }
    else if (isFloat(literal))
    {
        errno = 0;
        f = std::strtof(literal.c_str(), NULL);
        if (errno == ERANGE)
        {
            std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
            return;
        }
        i = static_cast<int>(f);
        d = static_cast<double>(f);
    }
    else if (isDouble(literal))
    {
        errno = 0;
        d = std::strtod(literal.c_str(), NULL);
        if (errno == ERANGE)
        {
            std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
            return;
        }
        i = static_cast<int>(d);
        f = static_cast<float>(d);
    }
    else
    {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
        return;
    }

    std::cout << std::fixed << std::setprecision(1);

    // Char
    if (std::isnan(d) || std::isinf(d) ||
        d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
        std::cout << "char: impossible\n";
    else if (!std::isprint(static_cast<char>(d)))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << static_cast<char>(d) << "'\n";

    // Int
    if (std::isnan(d) || std::isinf(d) || d > INT_MAX || d < INT_MIN)
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(d) << "\n";

    // Float
    std::cout << std::setprecision(4);
    std::cout << "float: " << f << "f\n";

    // Double
    int doublePrecision = countDecimalPlaces(literal);
    std::cout << std::setprecision(doublePrecision);
    std::cout << "double: " << d << "\n";
}
