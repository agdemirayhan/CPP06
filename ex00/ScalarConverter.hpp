#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
public:
    static void convert(const std::string& literal);

private:
    ScalarConverter() = delete;
    ScalarConverter(const ScalarConverter&) = delete;
    ScalarConverter& operator=(const ScalarConverter&) = delete;
    ~ScalarConverter() = delete;

    static void convertChar(const char &c);
    static void convertInt(const int &i);
    static void convertFloat(const float &f);
};

#endif
