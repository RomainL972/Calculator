#ifndef PARSE_STDIN_H_INCLUDED
#define PARSE_STDIN_H_INCLUDED

#include "structs_enums.h"

/*
Init expression tree, first floor and root sub expression

IN:
- tree: will contain expressions tree

FAILURE:
- Incorrect stdin: 3
- Malloc fail: 2
- Unknown Error: 255
*/
int parse_stdin_init(Expression *tree, const String* digits);

/*
Parse stdin

FAILURE:
- Incorrect stdin: 3
- Malloc fail: 2
- Unknown Error: 255
*/
int parse_stdin_parse(SubExpression *rootSubExpression, const String* digits);

/*
Add a digit to current expression

FAILURE:
- Malloc fail: 2
- Unknown Error: 255
*/
int parse_stdin_add_number(SubExpression *expression, char digit);

/*
Add an operator to current expression

FAILURE:
- Malloc fail:2
*/
int parse_stdin_add_operator(SubExpression **expression, char operator);

/*
Get last element from expression

FAILURE:
- Empty expression: NULL
*/
Element* parse_stdin_get_last(SubExpression *expression);

#endif
