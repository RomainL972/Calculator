#include "calculate.h"
#include "timesdiv.h"
#include "addsub.h"
#include "string.h"
#include <stdlib.h>

int calculate_start(Expression *tree, const char *digits) {
    int i, j;
    Floor *floor;
    SubExpression *expression;
    for(i = tree->size; i >= 0; i--) {
        floor = tree->floors[i];
        for(j = floor->size; j > 0; j--) {
            expression = floor->expressions[j];
            if(floor->priority % 2) {
                calculate_timesdiv(expression, digits);
            }
            else calculate_addsub(expression, digits);
        }
    }
    return 0;
}

int calculate_timesdiv(SubExpression *expression, const char *digits) {
    int i, operator;
    Element *element=NULL, *num1=NULL;
    for(i = 0; i < expression->size; i++) {
        element = expression->elements[i];
        if(element->type == Number && !num1) num1=element;
        else if(element->type == Number && !operator) timesdiv_times(num1, element, digits);
        else if(element->type == Number) timesdiv_div(num1, element, digits);
        else if(element->type == Operator && element->operator == '*') operator=0;
        else operator=1;
    }
    return 0;
}

int calculate_addsub(SubExpression *expression, const char* digits) {
    int i, invert = 0;
    Element *element=NULL, *num1=NULL;
    for(i = 0; i < expression->size; i++) {
        element = expression->elements[i];
        if(invert) {
            invert = 0;
            addsub_invert(element);
        }
        if(element->type == Number && !num1) num1=element;
        else if(element->type == Number) addsub_add(num1, element, digits);
        else if(element->type == Operator && element->operator == '-') {
            invert = 1;
        }
    }
    return 0;
}

int calculate_minmax(Element** num1, Element** num2, const char* digits) {
    int i;
    if((*num1)->size > (*num2)->size || ((*num1)->sign && !(*num2)->sign))
        calculate_swap(num1, num2);
    else if((*num1)->size > (*num2)->size || (!(*num1)->sign && (*num2)->sign));
    else {
        for(i=0; i<(*num1)->size-1; i++) {
            if(((*num1)->sign && string_contains(digits, (*num1)->digits[i]) > string_contains(digits, (*num2)->digits[i])) ||
                (!(*num1)->sign && string_contains(digits, (*num1)->digits[i]) < string_contains(digits, (*num2)->digits[i]))) {
                    calculate_swap(num1, num2);
                    break;
                }
        }
    }
    return 0;
}

int calculate_swap(Element **num1, Element **num2) {
    Element *tmp;
    tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
    return 0;
}
