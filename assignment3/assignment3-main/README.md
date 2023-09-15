<h1 align="center">CS311 Programming Assignment 3 </h1>
<h2 align="center">Total points: 10</h2>

In this assignment, you will use a stack data structure to evaluate arithmetic expressions.

## Infix and Postfix
We are used to writing arithmetic expressions with the operator between the two operands, e.g., `(3 + 6) * 2 / 5`. This type of expression is called infix expression. There are other types of different but equivalent ways of writing expressions. For example, postfix expression writes the operator after their operands. The above infix expression would be written as `3 6 + 2 * 5 /`.

More examples of infix vs. postfix expressions:

| Infix              ||  Postfix    |
| ------------------ |---|-------------------:|
| `a + b + c`        || `a b+ c +` |
|`a + b*c	`        || `a b c * +`|
|`(a + b) * (c – d)` || `a b + c d - *`|

## Evaluate Postfix expressions
A stack is an efficient data structure to evaluate a postfix expression. For simplicity, we assume that each operand is a one-digit number (e.g., `2, 3, 4` etc.) and four basic types of operators (i.e., `+, -, *, /`), and there is no space between characters. The basic algorithm to evaluate a postfix expression is as the following:
```
While there are still items left in the expression and no error:  
   1.  get next item (a single character, check for its validity).  
   2.  if it is an operand (number), push it onto the stack
   3.  else if it is an operator,
        	pop the top two operands (check for error here), 
          	apply the operator to the two operands, and push the result.
```
After the loop completes successfully, the result will be the only thing left on the stack so pop and display it. If there are other things still left on the stack, the expression was incomplete, and an error code should be returned. Although the input operands are single-digit integers, we use float for stack data values to store the expression result accurately. For example, `3 6 + 2 * 5 /` would be evaluated to `3.8`. your program must be able to detect and report the expression errors (e.g., incomplete expression, unrecognized operators) and the division by zero error.

In this assignment, you will complete the implementation of a template stack class (You cannot use the stack class in the STL C++ library) in "stack.h". Then you will implement a function in "eval_expr.cpp" to evaluate postfix expressions:
```
bool evalPostfixExpr(string postfix_expr, float &result)
```
If the input expression is valid, this function returns true and the “result” gets the result of evaluation. If the expression is invalid, it returns false.  

## Conversion from Infix to Postfix
Knowing how to evaluate postfix expressions, you can evaluate the standard infix expressions by converting them into equivalent postfix ones. 

In infix expressions, we know that operators have different precedence orders to avoid ambiguous meaning. The operators `+` and `-` have the same precedence. The operators `*` and  `/` also have the same precedence but have higher precedence than `+` and `-`. we must also first evaluate the expression in parentheses. Again, we assume that each operand in the infix expression is a one-digit number (e.g., `2, 3, 4` etc.) and four basic types of operators (i.e., `+, -, *, /`) and parenthesis “`(, )`”, and there is no space between characters. An example expression may be `9*(6-3/(2+8))`.

 The algorithm of converting an infix expression to a postfix expression using a stack is as the following:
 ```
 While there are still items left in the infix expression and no error:  
   1.	get next item (a single character, check for its validity). 
   2.	If it’s a operand (such as 2, 3, and 4), the item is directly appended to the output postfix expression.
   3.	If it’s a left parenthesis, it is pushed onto a stack.
   4.	If it’s a right parenthesis, the symbol on the top of the stack is popped off the stack and appended to the output. This process repeats until the top of the stack is a left parenthesis. When that occurs, both parentheses are discarded. 
   5.	If it’s an operator with a higher precedence than the one on the top of the stack, it is pushed onto the stack. If stack is empty, it’s pushed onto the stack.
   6.	If it’s an operator with a lower or the same precedence than the one at the top of the stack, the one at the top of the stack is popped off and appended to the output. The symbol been scanned will be compared with the new top element on the stack, and the process continues.
```
When the input is empty, the stack is popped to the output until the stack is empty. Then the algorithm terminates.
If the input is empty but the stack still has a left parenthesis, or a right parenthesis is scanned when the stack is empty, the parenthesis of the original expression were unbalanced.

In the "eval_expr.cpp" file, you will implement the conversion algorithm in the following function. 
```
/**
 * @brief Convert an infix expression to an equivalent postfix expression
 * @param infix_expr The input expression in the infix format.
 * @return the converted postfix expression. If the input infix expression is invalid, return an empty string "";
 */
String convertInfixToPostfix (string infix_expr)
```
Then implement a function to evaluate infix expressions by using the `convertInfixToPostfix` and `evalPostfixExpr` functions.
```
bool evalInfixExpr(string infix_expr, float& result);
```
## Submission
You have to upload stack.h, eval_expr.h, and eval_expr.cpp into gradescope for autograding. You don't need to upload anything in canvas.  
