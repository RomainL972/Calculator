#include "element_utils.h"
#include "string_struct.h"
#include "string.h"
#include <stdlib.h>

/*Only converts to Number*/
int element_utils_copy(const Element *origin, Element *dest) {
    if(dest == origin) return 0;
    if(dest->type != origin->type) {
        if(!(dest->digits = malloc(sizeof(String)))) return 2;
        dest->digits->str = NULL;
    }
    dest->type = origin->type;
    dest->sign = origin->sign;
    string_struct_init(dest->digits);
    return string_struct_copy(origin->digits, dest->digits);
}

int element_utils_cmp(const Element *num1, const Element *num2, const String *digits) {
    int i, difference;
    if((difference = num1->digits->length - num2->digits->length)) return difference;
    for(i=0; i<num1->digits->length-1; i++)
        if((difference = string_contains(digits->str, num1->digits->str[i]) - string_contains(digits->str, num2->digits->str[i])))
            return difference;
    return 0;
}

int element_utils_free(Element *element) {
    if(element->type == Number) {
        free(element->digits->str);
        free(element->digits);
    }
    free(element);
    return 0;
}
