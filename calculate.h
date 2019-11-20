#ifndef CALCULATE_H_INCLUDED
#define CALCULATE_H_INCLUDED

#include "structs_enums.h"

/*
Calculates the expression
*/
int calculate_start(Expression *tree);

/*
Calculate a sub-expression with multiplications and divisions
*/
int calculate_timesdiv(SubExpression *expression, const String* digits);

/*
Calculate a sub-expression with additions and substractions
*/
int calculate_addsub(SubExpression *expression, const String* digits);

/*
Sets num1 and num2 to the lower and greater number, respectively
*/
int calculate_minmax(Element **num1, Element **num2, const String* digits);

/*
Swaps num1 and num2
*/
int calculate_swap(Element **num1, Element **num2);

#endif
