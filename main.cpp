#include <iostream>
#include "infixToRPN.h"

int main() {
    std::string exp = "a+b*(c^d-e)^(f+g*h)-i";
    InfixTranslator lol(exp);

    lol.formatExpression();

    std::cout << lol.translate();
    return 0;
}