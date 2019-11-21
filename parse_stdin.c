#include "parse_stdin.h"
#include "expression.h"
#include "structs_enums.h"
#include "string.h"
#include "element.h"
#include <stdio.h>
#include <stdlib.h>

int parse_stdin_init(Expression *tree, const char* digits) {
    SubExpression * subExpression = malloc(sizeof(SubExpression));
    if(!tree) return 2;
    tree->size = 0;
    tree->floors = NULL;
    if(expression_add_floor(tree, subExpression)) return 2;
    return parse_stdin_parse(subExpression, digits);
}

int parse_stdin_parse(SubExpression *rootExpression, const char* digits){
    signed char input;
    int error;
    SubExpression *currentExpression = rootExpression;
    while((input = (signed char)getchar()) != EOF && input != '\n') {
        if(string_contains(digits, input) != -1) {
            error = parse_stdin_add_number(currentExpression, input);
        } else if(string_contains("+-*/()", input) != -1) {
            error = parse_stdin_add_operator(&currentExpression, input);
        } else{
            return 3;
        } if(error) return error;
    }
    if(currentExpression->floor->priority > 1) return 3;
    return 0;
}

int parse_stdin_add_number(SubExpression *expression, char digit) {
    Element *last = NULL;
    if(expression->size)
        last = expression->elements[expression->size-1];
    if(last && last->type == Number) {
        if(element_number_add_digit(last, digit)) return 2;
    }
    else if(!last || last->type == Operator) {
        if(element_add_number(expression, digit, 1)) return 2;
    }
    else {
        return 3;
    }
    return 0;
}

/*Too long*/
int parse_stdin_add_operator(SubExpression **expression, char operator) {
    Element *last = parse_stdin_get_last(*expression);
    if((last && last->type != Operator && string_contains("/+*", operator)!=-1) ||
        ((!last || last->type != Operator) && operator == '-')) {
            if(string_contains("+-", operator)!=-1 && (*expression)->floor->priority % 2) *expression = (*expression)->parent;
            else if(string_contains("*/", operator)!=-1 && !((*expression)->floor->priority % 2)) {
                if(!expression_pop_element(*expression)) return 255;
                if(element_add_reference(expression)) return 2;
                if(element_add(*expression, last)) return 2;
            } if(element_add_operator(*expression, operator)) return 2;
        }
    else if((!last || last->type == Operator) && operator == '(') {
        if(element_add_reference(expression)) return 2;
        if((*expression)->floor->priority % 2) if(element_add_reference(expression)) return 2;
    }
    else if(last && last->type != Operator){
        *expression = (*expression)->parent;
        if(!((*expression)->floor->priority % 2)) *expression = (*expression)->parent;
    }
    else return 3;
    return 0;
}

Element* parse_stdin_get_last(SubExpression *expression) {
    if(expression->size) return expression->elements[expression->size-1];
    else return NULL;
}
