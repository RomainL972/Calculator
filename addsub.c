#include "addsub.h"
#include "string.h"
#include "calculate.h"

/*Flemme*/
int addsub_prepare(Element *num1, Element *num2, const char* digits) {
    int i;
    char digit;
    num1->digits = string_leftpad(num1->digits, digits[0], num2->size - num1->size);
    num1->size = num2->size;
    if(num1->sign == num2->sign) addsub_add(num1, num2, digits);
    else {
        addsub_sub(num2, num1, digits);
        addsub_invert(num1);
    }
    return 0;
}

int addsub_add(Element *num1, Element *num2, const char *digits) {
    int intNum=0, length = string_length(digits), i, retenue=0;
    for(i = num1->size-2; i >= 0; i--) {
        intNum = string_contains(digits, num1->digits[i]) + string_contains(digits, num2->digits[i]);
        if(retenue && !(retenue=0)) intNum++;
        if(intNum >= length && (intNum-=length)<length && (retenue=1)) {
            num1->digits[i] = digits[intNum];
            if(!i){
                num1->digits = string_leftpad(num1->digits, '1', 1);
                num1->size++;
            }
        }
        else num1->digits[i] = digits[intNum];
    }
    return 0;
}

int addsub_sub(Element *num1, Element *num2, const char *digits) {
    int intNum, length = string_length(digits), i, retenue=0;
    for(i = num1->size-2; i >= 0; i--) {
        intNum = string_contains(digits, num1->digits[i]) - string_contains(digits, num2->digits[i]);
        if(retenue && !(retenue=0)) intNum--;
        if(intNum < 0 && (intNum+=length)>0 && (retenue=1));
        num2->digits[i] = digits[intNum];
    }
    return 0;
}

int addsub_invert(Element *element) {
    element->sign = !element->sign;
    return 0;
}
