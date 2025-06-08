#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./convert <literal>\n";
        return 1;
    }
    std::cout << "Input: " << argv[1] << std::endl;
    ScalarConverter::convert(argv[1]);
    return 0;
}
