#include "addsub.h"
#include "string.h"
#include "string_struct.h"
#include "number_utils.h"
#include "element_utils.h"

int addsub_prepare(Element *result, Element *num1, Element *num2, const String* digits) {
    number_utils_equalize_zeros(num1, num2, digits);
    if(num1->sign == num2->sign) addsub_add(result, num1, num2, digits);
    else {
        if(element_utils_cmp(num1, num2, digits)>0) addsub_sub(result, num1, num2, digits);
        else addsub_sub(result, num2, num1, digits);
    }
    return 0;
}

int addsub_add(Element *result, Element *num1, Element *num2, const String *digits) {
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
    element_utils_copy(num1, result);
    return 0;
}

int addsub_sub(Element *result, Element *num1, Element *num2, const String *digits) {
    int intNum, i, retenue=0;
    for(i = num1->digits->length-2; i >= 0; i--) {
        intNum = string_contains(digits->str, num1->digits->str[i]) - string_contains(digits->str, num2->digits->str[i]);
        if(retenue && !(retenue=0)) intNum--;
        if(intNum < 0 && (intNum+=digits->length-1)>=0) retenue=1;
        num1->digits->str[i] = digits->str[intNum];
    }
    element_utils_copy(num1, result);
    return 0;
}

int addsub_invert(Element *element) {
    element->sign = !element->sign;
    return 0;
}
