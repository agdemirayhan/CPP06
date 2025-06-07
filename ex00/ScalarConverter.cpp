#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cctype>

static bool isChar(const std::string& s) {
    return s.length() == 1 && std::isprint(s[0]) && !std::isdigit(s[0]);
}

static bool isInt(const std::string& s) {
    char* end;
    long val = std::strtol(s.c_str(), &end, 10);
    return *end == '\0' && val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max();
}

static bool isFloat(const std::string& s) {
    if (s == "+inff" || s == "-inff" || s == "nanf") return true;
    char* end;
    std::strtof(s.c_str(), &end);
    return *end == 'f' && *(end + 1) == '\0';
}

static bool isDouble(const std::string& s) {
    if (s == "+inf" || s == "-inf" || s == "nan") return true;
    char* end;
    std::strtod(s.c_str(), &end);
    return *end == '\0';
}

void ScalarConverter::convert(const std::string& literal) {
    char c;
    int i;
    float f;
    double d;

    std::cout << std::fixed << std::setprecision(1);

    if (isChar(literal)) {
        c = literal[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    } else if (isInt(literal)) {
        i = std::atoi(literal.c_str());
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
    } else if (isFloat(literal)) {
        f = std::strtof(literal.c_str(), NULL);
        c = static_cast<char>(f);
        i = static_cast<int>(f);
        d = static_cast<double>(f);
    } else if (isDouble(literal)) {
        d = std::strtod(literal.c_str(), NULL);
        c = static_cast<char>(d);
        i = static_cast<int>(d);
        f = static_cast<float>(d);
    } else {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }

    // Char
    if (std::isprint(c))
        std::cout << "char: '" << c << "'\n";
    else if (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "-inf" || literal == "+inff" || literal == "-inff")
        std::cout << "char: impossible\n";
    else
        std::cout << "char: Non displayable\n";

    // Int
    if (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "-inf" || literal == "+inff" || literal == "-inff")
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << i << "\n";

    // Float
    std::cout << "float: " << f << "f\n";

    // Double
    std::cout << "double: " << d << "\n";
}
