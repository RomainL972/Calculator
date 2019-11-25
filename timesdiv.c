#include "timesdiv.h"
#include "calculate.h"
#include "string.h"
#include "addsub.h"
#include "element_utils.h"
#include "string_struct.h"
#include <stdlib.h>

/*TODO optimize this function*/
int timesdiv_times(Element* num1, Element* num2, const String* digits) {
    int i, j;
    Element total = {Number, 0, NULL, 1, NULL}, somme = {Number, 0, NULL, 1, NULL};
    total.digits = malloc(sizeof(String));
    somme.digits = malloc(sizeof(String));
    total.digits->str = NULL;
    somme.digits->str = NULL;
    string_struct_init(total.digits);
    string_struct_init(somme.digits);
    for(i = num1->digits->length-2; i >= 0; i--) {
        for(j = 0; j < string_contains(digits->str, num1->digits->str[i]); j++) {
            addsub_prepare(&somme, &somme, num2, digits);
            if(num1->digits->length-2-i) string_struct_add_chars(somme.digits, digits->str[0], num1->digits->length-2-i);
            addsub_prepare(&total, &total, &somme, digits);
            string_struct_init(somme.digits);
    }} total.sign = !(num1->sign ^ num2->sign);
    element_utils_copy(&total, num1);
    free(total.digits->str);
    free(total.digits);
    free(somme.digits->str);
    free(somme.digits);
    return 0;
}

/*When number of digits in num1 goes up, function becomes VERY slow*/
int timesdiv_div(Element* num1, Element* num2, const String* digits) {
    Element total = {Number, 0, NULL, 1, NULL}, result = {Number, 0, NULL, 1, NULL}, one = {Number, 0, NULL, 1, NULL};
    total.digits = malloc(sizeof(String));
    result.digits = malloc(sizeof(String));
    one.digits = malloc(sizeof(String));
    total.digits->str = NULL;
    result.digits->str = NULL;
    one.digits->str = NULL;
    string_struct_init(total.digits);
    string_struct_init(result.digits);
    string_struct_init(one.digits);
    string_struct_add_chars(one.digits, digits->str[1], 1);
    addsub_prepare(&total, &total, num2, digits);
    while(element_utils_cmp(&total, num1, digits)<=0) {
        addsub_prepare(&result, &result, &one, digits);
        addsub_prepare(&total, &total, num2, digits);
    }
    result.sign = !(num1->sign ^ num2->sign);
    element_utils_copy(&result, num1);
    free(total.digits->str);
    free(total.digits);
    free(result.digits->str);
    free(result.digits);
    free(one.digits->str);
    free(one.digits);
    return 0;
}
