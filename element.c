#include "element.h"
#include "expression.h"
#include <stdlib.h>

int element_add(SubExpression *expression, Element *element) {
    expression->size++;
    expression->elements = realloc(expression->elements,sizeof(Element)*expression->size);
    if(!element) return 2;
    expression->elements[expression->size-1] = element;
    return 0;
}

int element_add_number(SubExpression *expression, char digit, int sign) {
    Element *number = malloc(sizeof(Element));
    if(element_add(expression, number)) return 2;
    number->type = Number;
    number->sign = sign;
    number->digits = NULL;
    number->size = 0;
    if(digit) {
        if(element_number_add_digit(number, digit)) return 2;
    }
    return 0;
}

int element_add_operator(SubExpression *expression, char operatorChar) {
    Element *operator = malloc(sizeof(Element));
    if(element_add(expression, operator)) return 2;
    operator->type = Operator;
    operator->operator = operatorChar;
    return 0;
}

int element_add_reference(SubExpression **expression) {
    Element *reference = malloc(sizeof(Element));
    SubExpression *newExpression = malloc(sizeof(SubExpression));
    Expression *tree = (*expression)->floor->parent;
    if(element_add(*expression, reference)) return 2;
    if((*expression)->floor->priority == tree->size - 1) {if(expression_add_floor(tree, newExpression)) return 2;}
    else if(expression_floor_add_expression(tree->floors[(*expression)->floor->priority + 1], newExpression)) return 2;
    reference->type = Reference;
    reference->child = newExpression;
    newExpression->parent = *expression;
    *expression = newExpression;
    return 0;
}

int element_number_add_digit(Element *number, char digit) {
    number->size++;
    if(number->size == 1) {
        number->size++;
    }
    number->digits = realloc(number->digits, sizeof(char)*number->size);
    if(!number->digits) return 2;
    number->digits[number->size-2] = digit;
    number->digits[number->size-1] = '\0';
    return 0;
}
