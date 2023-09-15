/**
 *Implementation of the functions to evaluate arithmetic expressions
 *The implementation should use the Stack data structure
 */
//You must complete the TODO parts and then complete LinkedList.cpp. Delete "TODO" after you are done.
//You should always comments to each function to describe its PURPOSE and PARAMETERS
#include "stack.h"
#include "eval_expr.h"
#include <string>
#include <ctype.h>
#include <cmath>




int getOperatorPriority(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0; // Lower priority for other characters
}
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

/**
 *@brief Evaluate a postfix expression
 *@param postfix_expr The input expression in the postfix format.
 *@param result gets the evaluated value of the expression (by reference).
 *@return true if expression is a valid postfix expression and evaluation is done without error, otherwise false.
 */


bool evalPostfixExpr(string postfix_expr, float& result) {
    Stack<float> operandStack;
    float res;
    for (char c : postfix_expr) {
        if (isdigit(c)) {
            float operand = c - '0'; // Convert char to float operand
            operandStack.push(operand);
        } else if (isOperator(c)) {
            if (operandStack.size() < 2) {
                // Insufficient operands, invalid postfix expression
                return false;
            }

            float operand2 = operandStack.top();
            operandStack.pop(operand2);
            float operand1 = operandStack.top();
            operandStack.pop(operand1);


            if (c == '+') {
                res = operand1 + operand2;
            } else if (c == '-') {
                res = operand1 - operand2;
            } else if (c == '*') {
                res = operand1 * operand2;
            } else if (c == '/') {
                if (operand2 == 0) {
                    // Division by zero, invalid postfix expression
                    return false;
                }
                res = operand1 / operand2;
            }

            operandStack.push(res);
        } else {
            // Unknown symbol encountered, invalid postfix expression
            return false;
        }
    }

    if (operandStack.size() != 1) {
        // Invalid postfix expression
        return false;
    }
    float unroundedresult;
    operandStack.pop(unroundedresult);

    result = round(unroundedresult*10)/10;
    return true;
}


/**
 *@brief Convert an infix expression to an equivalent postfix expression
 *@param infix_expr The input expression in the infix format.
 *@return the converted postfix expression. If the input infix expression is invalid, return an empty string "";
 */
string convertInfixToPostfix(string infix_expr) {
    Stack<char> operatorStack;
    string postfix;

    for (char c : infix_expr) {
        if (isdigit(c)) {
            postfix += c;
        } else if (c == '(') {
            operatorStack.push(c);
        } else if (c == ')') {
            while (!operatorStack.isEmpty() && operatorStack.top() != '(') {
                char top;
                operatorStack.pop(top);
                postfix += top;
            }

            if (!operatorStack.isEmpty() && operatorStack.top() == '(') {
                char top;
                operatorStack.pop(top);
            } else {
                // Mismatched parentheses, invalid infix expression
                return "";
            }
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int currPriority = getOperatorPriority(c);

            while (!operatorStack.isEmpty() && operatorStack.top() != '(' &&
                   getOperatorPriority(operatorStack.top()) >= currPriority) {
                char top;
                operatorStack.pop(top);
                postfix += top;
            }

            operatorStack.push(c);
        }
    }

    while (!operatorStack.isEmpty()) {
        if (operatorStack.top() == '(' || operatorStack.top() == ')') {
            // Mismatched parentheses, invalid infix expression
            return "";
        }

        char top;
        operatorStack.pop(top);
        postfix += top;
    }

    return postfix;
}

/**
 *@brief Evaluate an infix expression. It's converted to a postfix expression first and then evaluated
 *@param infix_expr The input expression in the infix format.
 *@param result gets the evaluated value of the expression (by reference).
 *@return true if expression is valid and evaluation is done without error, otherwise false.
 */
bool evalInfixExpr(string infix_expr, float &result) {
    string postfix = convertInfixToPostfix(infix_expr);
    float postfixResult = 0;
    bool success = evalPostfixExpr(postfix, postfixResult);
    result = postfixResult;
    if (success) {
          // Assign the result to the passed-in reference variable
        return true;
    }
    return false;
}
