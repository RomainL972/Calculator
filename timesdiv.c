#include "timesdiv.h"
#include "calculate.h"
#include "string.h"
#include "addsub.h"
#include <stdlib.h>
#include <stdio.h>

/*TODO optimize this function*/
int timesdiv_times(Element* num1, Element* num2, const char* digits) {
    int i, j;
    Element total = {Number, 0, 1, NULL, 1, NULL}, somme = {Number, 0, 1, NULL, 1, NULL}, *totalPtr=&total, *sommePtr=&somme;
    total.digits = malloc(1);
    somme.digits = malloc(1);
    total.digits[0] = somme.digits[0] = '\0';
    for(i = num2->size-2; i >= 0; i--) {
        for(j = 0; j < string_contains(digits, num2->digits[i]); j++) {
            addsub_prepare(&somme, num1, digits);
            string_append(somme.digits, digits[0], num2->size-2-i);
            somme.size += num2->size-2-i;
            calculate_minmax(&totalPtr, &sommePtr, digits);
            addsub_prepare(totalPtr, sommePtr, digits);
            timesdiv_copy(&total, totalPtr);
            sommePtr = &somme;
            totalPtr = &total;
            somme.digits[0] = '\0';
            somme.size = 1;
    }} num1->digits = total.digits;
    num1->size = total.size;
    num1->sign = !(num1->sign ^ num2->sign);
    return 0;
}

int timesdiv_div(Element* num1, Element* num2, const char* digits) {
    return 0;
}

int timesdiv_copy(Element *num1, Element *num2) {
    int i;
    if(num1 == num2) return 0;
    num1->size = num2->size;
    num1->digits = realloc(num1->digits, sizeof(char)*num1->size);
    for(i = 0; i < num1->size; i++) num1->digits[i] = num2->digits[i];
    num1->sign = num2->sign;
    return 0;
}
