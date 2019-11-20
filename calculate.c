#include "calculate.h"
#include "timesdiv.h"
#include "addsub.h"
#include "string.h"
#include <stdlib.h>

int calculate_start(Expression *tree, const char *digits) {
    int i, j;
    Floor *floor;
    SubExpression *expression;
    for(i = tree->size-1; i >= 0; i--) {
        floor = tree->floors[i];
        for(j = floor->size-1; j >= 0; j--) {
            expression = floor->expressions[j];
            if(floor->priority % 2 && expression->size > 1) {
                calculate_timesdiv(expression, digits);
            }
            else if(expression->size > 1) calculate_addsub(expression, digits);
            else if(expression->refParent) element_utils_copy(expression->elements[0], expression->refParent);
        }
    }
    return 0;
}

int calculate_timesdiv(SubExpression *expression, const char *digits) {
    int i, operator=0;
    Element *element=NULL, *num1=NULL;
    for(i = 0; i < expression->size; i++) {
        element = expression->elements[i];
        if(element->type == Number && !num1) num1=element;
        else if(element->type == Number) {
            calculate_minmax(&num1, &element, digits);
            if(!operator) timesdiv_times(num1, element, digits);
            else timesdiv_div(num1, element, digits);
        }
        else if(element->type == Operator && element->operator == '*') operator=0;
        else operator=1;
    } if(expression->refParent) element_utils_copy(num1, expression->refParent);
    else expression->elements[0] = num1;
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
        } if(element->type == Number && !num1) num1=element;
        else if(element->type == Number) {
            calculate_minmax(&num1, &element, digits);
            addsub_prepare(num1, element, digits);
        } else if(element->type == Operator && element->operator == '-') {
            invert = 1;
        }} if(expression->refParent) element_utils_copy(num1, expression->refParent);
        else expression->elements[0] = num1;
    return 0;
}

int calculate_minmax(Element** num1, Element** num2, const char* digits) {
    /*Note: compares absolute value, not sign
    Problem: 0001 is considered > 10
    */
    int i;
    if((*num1)->size > (*num2)->size)
        calculate_swap(num1, num2);
    else {
        for(i=0; i<(*num1)->size-2; i++) {
            if(string_contains(digits, (*num1)->digits[i]) >
                string_contains(digits, (*num2)->digits[i])) {
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
