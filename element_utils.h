#ifndef ELEMENT_UTILS_H_INCLUDED
#define ELEMENT_UTILS_H_INCLUDED

#include "structs_enums.h"

/*
Copy data from origin to destination

FAILURE:
- Malloc fail: 2
*/
int element_utils_copy(const Element *origin, Element *dest);

#endif
