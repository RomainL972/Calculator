#include "element_utils.h"

int element_utils_copy(const Element *origin, Element *destination) {
    if(destination == origin) return 0;
    destination->type = origin->type;
    switch(origin.type) {
        case Number:
        destination->size = origin->size;
        destination->sign = origin->sign;
        return element_utils_digits_copy(destination, origin->digits);
        break;
        //TODO: Do we ever need to copy anything else?
    }
    return 0;
}

int element_utils_digits_copy(Element *element, char* digits) {
    int i;
    free(element->digits);
    element->digits = malloc(sizeof(char)* element->size);
    if(!element->digits) return 2;
    for(i = 0; i < element->size; i++) element->digits[i] = digits[i];
    return 0;
}
