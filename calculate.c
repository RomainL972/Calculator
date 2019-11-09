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
            else if(expression->refParent) calculate_ref_to_number(expression->refParent, expression->elements[0]);
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
        } if(element->type == Number && !num1) num1=element;
        else if(element->type == Number) {
            calculate_minmax(&num1, &element, digits);
            addsub_prepare(num1, element, digits);
        } else if(element->type == Operator && element->operator == '-') {
            invert = 1;
        }} if(expression->refParent) calculate_ref_to_number(expression->refParent, num1);
        else expression->elements[0] = num1;
    return 0;
}

int calculate_minmax(Element** num1, Element** num2, const char* digits) {
    /*Note: compares absolute value, not sign*/
    int i;
    if((*num1)->size > (*num2)->size)
        calculate_swap(num1, num2);
    else if((*num1)->size > (*num2)->size);
    else {
        for(i=0; i<(*num1)->size-1; i++) {
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

int calculate_ref_to_number(Element *reference, Element *number) {
    reference->type = Number;
    reference->sign = number->sign;
    reference->digits = number->digits;
    reference->size = number->size;
}