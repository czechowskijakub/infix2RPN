#include <iostream>
#include "infixToRPN.h"

int main() {
    std::string expression = "";
    std::cout << "Input your expression to translate: ";
    std::getline(std::cin, expression);
    
    InfixTranslator test(expression);
    std::cout << test.translate();
    return 0;
}