#ifndef EXPRESSION_H_INCLUDED
#define EXPRESSION_H_INCLUDED

#include "structs_enums.h"

/*
Adds a floor to expression

IN:
- subExpression: the new subExpression to work with

SUCCESS: 0
FAILURE:
- Malloc fail: 2
*/
int expression_add_floor(Expression *expression, SubExpression *subExpression);

/*
add an expression to floor

IN:
- expression: the new subExpression to work with

SUCCESS: 0
FAILURE:
- Malloc fail: 2
*/
int expression_floor_add_expression(Floor *floor, SubExpression *expression);

/*
remove last element from subexpression and return it

FAILURE:
- Malloc fail: NULL
- Empty expression: NULL
*/
Element* expression_pop_element(SubExpression* expression);

#endif
