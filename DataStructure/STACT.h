#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')');
}
bool isDigit(char c) {
    return c >= '0' && c <= '9';
}
int operatorPrecedence(char c) {
    switch (c)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '^':
        return 3;
        break;
        //case '(':
    case ')':
        return 4;
        break;
    default:
        return 0;
        break;
    }
}

bool isoperatorPop(char top, char c) {
    if (top == '(' || c == '(')
    {
        return false;
    }
    return operatorPrecedence(top) >= operatorPrecedence(c) ? true : false;
}

// 四则表达式 中缀转后缀
string InfixToPostfix(const string& Infix) {
    string Postfix;
    stack<char> STACK;
    for (char c : Infix) {
        if (isDigit(c)) {
            Postfix += c;
        }
        else if (isOperator(c)) {
            Postfix += ' ';
            if (STACK.empty()) {
                STACK.push(c);
            }
            else if (c == ')') {
                while (STACK.top() != '(') {

                    Postfix += STACK.top();
                    STACK.pop();
                    Postfix += ' ';

                }
                STACK.pop();
            }
            else {
                while (isoperatorPop(STACK.top(), c)) {

                    Postfix += STACK.top();
                    STACK.pop();
                    Postfix += ' ';
                    if (STACK.empty()) {
                        break;
                    }
                }
                STACK.push(c);
            }
        }
    }

    Postfix += ' ';
    while (!STACK.empty()) {

        Postfix += STACK.top();
        STACK.pop();
        Postfix += ' ';
    }
    return Postfix;
}

// 通过后缀表达式计算部分
int performOperation(int operand1, int operand2, char op) {
    switch (op) {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        return operand1 / operand2;
    default:
        return 0; // Invalid operator, return a default value (you can handle this differently as needed)
    }
}

int calculate(string& Postfix) {
    stack<int> STACK;
    std::istringstream iss(Postfix);
    std::string token;

    while (iss >> token) {
        //std::cout << "Element: " << token << std::endl;
        if (!isOperator(token[0])) {
            STACK.push(std::stoi(token));
        }
        else {
            int num1 = STACK.top();
            STACK.pop();
            int num2 = STACK.top();
            STACK.pop();
            STACK.push(performOperation(num2, num1, token[0]));
        }
    }
    /*for (char c : Postfix) {
        if (isDigit(c)) {
            STACK.push(c-'0');
        }
        else if (isOperator(c)) {
            int num1 = STACK.top();
            STACK.pop();
            int num2 = STACK.top();
            STACK.pop();
            STACK.push(performOperation(num2, num1, c));
        }
    }*/
    return STACK.top();
}