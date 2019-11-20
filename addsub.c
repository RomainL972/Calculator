#include "addsub.h"
#include "string.h"
#include "calculate.h"
#include "string_struct.h"

/*Flemme*/
int addsub_prepare(Element *num1, Element *num2, const String* digits) {
    string_struct_prepend_chars(num1->digits, digits->str[0], num2->digits->length - num1->digits->length);
    num1->digits->length = num2->digits->length;
    if(num1->sign == num2->sign) addsub_add(num1, num2, digits);
    else {
        addsub_sub(num2, num1, digits);
        addsub_invert(num1);
    }
    return 0;
}

int addsub_add(Element *num1, Element *num2, const String *digits) {
    int intNum=0, i, retenue=0;
    for(i = num1->digits->length-2; i >= 0; i--) {
        intNum = string_contains(digits->str, num1->digits->str[i]) + string_contains(digits->str, num2->digits->str[i]);
        if(retenue && !(retenue=0)) intNum++;
        if(intNum >= digits->length-1 && (intNum-=digits->length-1)<digits->length && (retenue=1)) {
            num1->digits->str[i] = digits->str[intNum];
            if(!i) string_struct_prepend_chars(num1->digits, digits->str[1], 1);
        }
        else num1->digits->str[i] = digits->str[intNum];
    }
    return 0;
}

int addsub_sub(Element *num1, Element *num2, const String *digits) {
    int intNum, i, retenue=0;
    for(i = num1->digits->length-2; i >= 0; i--) {
        intNum = string_contains(digits->str, num1->digits->str[i]) - string_contains(digits->str, num2->digits->str[i]);
        if(retenue && !(retenue=0)) intNum--;
        if(intNum < 0 && (intNum+=digits->length-1)>=0) retenue=1;
        num2->digits->str[i] = digits->str[intNum];
    }
    return 0;
}

int addsub_invert(Element *element) {
    element->sign = !element->sign;
    return 0;
}
