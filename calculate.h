#ifndef CALCULATE_H_INCLUDED
#define CALCULATE_H_INCLUDED

#include "structs_enums.h"

/*
Calculates the expression
*/
int calculate_start(Expression *tree, const char* digits);

/*
Calculate a sub-expression with multiplications and divisions
*/
int calculate_timesdiv(SubExpression *expression, const char* digits);

/*
Calculate a sub-expression with additions and substractions
*/
int calculate_addsub(SubExpression *expression, const char* digits);

int calculate_minmax(Element **num1, Element **num2, const char* digits);
int calculate_swap(Element **num1, Element **num2);

#endif
