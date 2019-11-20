#include "timesdiv.h"
#include "calculate.h"
#include "string.h"
#include "addsub.h"
#include "element_utils.h"
#include "string_struct.h"
#include <stdlib.h>
#include <stdio.h>

/*TODO optimize this function*/
int timesdiv_times(Element* num1, Element* num2, const String* digits) {
    int i, j;
    Element total = {Number, 0, NULL, 1, NULL}, somme = {Number, 0, NULL, 1, NULL}, *totalPtr=&total, *sommePtr=&somme;
    total.digits = malloc(sizeof(String));
    somme.digits = malloc(sizeof(String));
    string_struct_init(total.digits);
    string_struct_init(somme.digits);
    for(i = num1->digits->length-2; i >= 0; i--) {
        for(j = 0; j < string_contains(digits->str, num1->digits->str[i]); j++) {
            addsub_prepare(&somme, num2, digits);
            string_append(somme.digits->str, digits->str[0], num1->digits->length-2-i);
            somme.digits->length += num1->digits->length-2-i;
            calculate_minmax(&totalPtr, &sommePtr, digits);
            addsub_prepare(totalPtr, sommePtr, digits);
            element_utils_copy(totalPtr, &total);
            sommePtr = &somme;
            totalPtr = &total;
            somme.digits->str[0] = '\0';
            somme.digits->length = 1;
    }} num1->digits->str = total.digits->str;
    num1->digits->length = total.digits->length;
    num1->sign = !(num1->sign ^ num2->sign);
    return 0;
}

int timesdiv_div(Element* num1, Element* num2, const String* digits) {
    free(num1);
    free(num2);
    if(digits){};
    return 0;
}
