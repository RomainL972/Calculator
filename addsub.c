#include "addsub.h"
#include "string.h"
#include "calculate.h"

/*Flemme*/
int addsub_add(Element *num1, Element *num2, const char* digits) {
    int i, retenue, length = string_length(digits);
    char digit;
    calculate_minmax(&num1, &num2, digits);
    if(num1->sign == num2->sign) {
        for(i = num2->size-1; i >= 0; i--) {

            num1->digits[i] = digits[string_contains(digits, num1->digits[i]) + string_contains(digits, num2->digits[i]) + retenue];
            if(num1->digits[i] >= length) {
                num1->digits[i] -= length;
                retenue = 1;
            } else retenue = 0;
        }
    } else {
        for(i = num1->size-1; i >= 0; i--);
    }
}

int addsub_invert(Element *element) {
    element->size = !element->size;
    return 0;
}
