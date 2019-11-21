#ifndef NUMBER_UTILS_H_INCLUDED
#define NUMBER_UTILS_H_INCLUDED

#include "structs_enums.h"

/*
Sets num1 and num2 to the same length by padding the smallest number with zeros
*/
int number_utils_equalize_zeros(Element *num1, Element *num2, const String *digits);

#endif
