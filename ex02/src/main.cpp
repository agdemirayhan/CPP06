#include <iostream>
#include <ctime>      
#include <cstdlib>    
#include "Base.hpp"

Base* generate();
void identify(Base* p);
void identify(Base& p);

int main() {
    std::srand(std::time(0));  

    for (int i = 0; i < 10; i++) {
        Base *base = generate();
        identify(base);
        identify(*base);
        delete base;
        std::cout << "----------------" << std::endl;
    }

    return 0;
}
