#ifndef ELEMENT_UTILS_H_INCLUDED
#define ELEMENT_UTILS_H_INCLUDED

#include "structs_enums.h"

/*
Copy data from origin to destination

FAILURE:
- Malloc fail: 2
*/
int element_utils_copy(const Element *origin, Element *dest);

/*
Returns 1 if num1>num2,
0 if num1==num2,
-1 if num1<num2
*/
int element_utils_cmp(const Element *num1, const Element *num2, const String *digits);

#endif
