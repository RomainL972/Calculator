#ifndef ELEMENT_UTILS_H_INCLUDED
#define ELEMENT_UTILS_H_INCLUDED

#include "structs_enums.h"

/*
Copy data from origin to destination

FAILURE:
- Malloc fail: 2
*/
int element_utils_copy(const Element *origin, Element *destination);

/*
Set element->digits to digits, correct size should already be set

FAILURE:
- Malloc fail: 2
*/
int element_utils_digits_copy(Element *element, char* digits);

#endif
