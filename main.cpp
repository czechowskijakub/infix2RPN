#include <iostream>
#include "infixToRPN.h"

void testPrimary(InfixTranslator& input) {
    std::string test{ "ab+" };
    if (input.translate() == test) { std::cout << "true" << '\n'; }
    else { std::cout << "false" << '\n'; }
}

int main() {
    InfixTranslator test("a + b");
    testPrimary(test);
    return 0;
}