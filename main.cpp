#include <iostream>
#include "infixToRPN.h"

int main() {
    std::string exp = "";
    std::cout << "Input your expression to translate: ";
    std::getline(std::cin, exp);
    
    InfixTranslator lol(exp);
    std::cout << lol.translate();
    return 0;
}