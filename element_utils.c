#include "element_utils.h"
#include "string_struct.h"
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
