//
// Created by caroh on 7/9/2023.
//
#include "eval_expr.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    float result;
    evalPostfixExpr("34+5*" ,result);
    cout<<result;
}