#pragma once
#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "Randomer.h"

class Calculator {
public:
    Calculator() {}
    ~Calculator() {}
    int add(int lhs, int rhs) {return lhs + rhs;}
    int sub(int lhs, int rhs) {return lhs - rhs >= 0 ? lhs - rhs : rhs - lhs;}
    int process(int lhs, char ch, int rhs) {return ch == '+' ? lhs + rhs : lhs - rhs;}
};

#endif // !CALCULATOR_H