#include "element_utils.h"
#include "string_struct.h"
#include "string.h"
#include <stdlib.h>

int element_utils_copy(const Element *origin, Element *dest) {
    if(dest == origin) return 0;
    dest->type = origin->type;
    switch(origin->type) {
        case Number:
        dest->sign = origin->sign;
        if(!(dest->digits = realloc(dest->digits, sizeof(String)))) return 2;
        return string_struct_copy(origin->digits, dest->digits);
        break;
        default:
        break;
        /*TODO: Do we ever need to copy anything else?*/
    }
    return 0;
}

int element_utils_cmp(const Element *num1, const Element *num2, const String *digits) {
    int i, difference;
    if((difference = num1->digits->length - num2->digits->length)) return difference;
    for(i=0; i<num1->digits->length-1; i++)
        if((difference = string_contains(digits->str, num1->digits->str[i]) - string_contains(digits->str, num2->digits->str[i])))
            return difference;
    return 0;
}
