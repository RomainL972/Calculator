#include "number_utils.h"
#include "string_struct.h"

int number_utils_equalize_zeros(Element *num1, Element *num2, const String *digits) {
    if(num1->digits->length > num2->digits->length)
        string_struct_prepend_chars(num2->digits, digits->str[0], num1->digits->length - num2->digits->length);
    else if(num2->digits->length > num1->digits->length)
        string_struct_prepend_chars(num1->digits, digits->str[0], num2->digits->length - num1->digits->length);
    return 0;
}
