#include "Stack.h"
#include <unordered_map>
#include <ctype.h>

class InfixTranslator {
private:
    Stack<std::string> stack;
    std::unordered_map<char, int> precedence;

public:
    std::string entryExpression;
        InfixTranslator(std::string entryExpression) {
            this->entryExpression = entryExpression;
            precedence['^'] = 4;
            precedence['*'] = 3;
            precedence['/'] = 3;
            precedence['+'] = 2;
            precedence['-'] = 2;
            precedence['('] = 1;
    };

    
    /*
    Precedence:
        high
        ^ (pow)
        *, /
        +, -
        (
        =
        low

    All operands are written until an operator is met.
    If operator is met: put it onto a stack.
    If we meet lower or same precedence operator, 
    We pop the previous operator and write it down, then we can push the lower one onto the stack.
    If its higher, we push it no problem.
    If right bracket is met, empty the stack until left is met and write everything down (left bracket included)
    a + b * (c - d)
    ab*cd-+
    */

   void formatExpression() {
        std::string formated = "";
        for (char c : this->entryExpression) {
            if (c != ' ') {
                formated += c;
            }
        }
        this->entryExpression = formated;
   }
   
    bool isOperator(char c) {
        return precedence.count(c) > 0;
    }
 
    // a * b + c / d
    // res ab*cd
    // stk +/

   std::string translate() {
    std::string result = "";
    formatExpression();
        for (char c : this->entryExpression) {
            std::string op{c};
            if (isalnum(c)) {
                result += c;
            } else if (c == '(') {
                stack.push(op);
            } else if (c == ')') {
                while (!stack.isEmpty() && stack.top()[0] != '(') {
                    result += stack.pop();
                }
                stack.pop();
            } else if (isOperator(c)) {
                while (!stack.isEmpty() && isOperator(stack.top()[0]) && precedence[c] <= precedence[stack.top()[0]]) {
                    result += stack.pop();
                }
                stack.push(op);
            }
        }
        while (!stack.isEmpty()) {
            result += stack.pop();
        }
        return result;
    }
};