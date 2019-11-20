#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED

#include "structs_enums.h"

/*
Add an element to expression

FAILURE:
- Malloc fail: 2
*/
int element_add(SubExpression *expression, Element *element);

/*
Add an element a number to expression

FAILURE:
- Malloc fail: 2
*/
int element_add_number(SubExpression *expression, char digit, int sign);

/*
Add an operator to expression

FAILURE:
- Malloc fail: 2
*/
int element_add_operator(SubExpression *expression, char operator);

/*
Add a reference to expression

FAILURE:
- Malloc fail: 2
*/
int element_add_reference(SubExpression **expression);

#endif
