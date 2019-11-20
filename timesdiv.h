#ifndef TIMESDIV_H_INCLUDED
#define TIMESDIV_H_INCLUDED

#include "structs_enums.h"

/*
Sets num1 to num1*num2
*/
int timesdiv_times(Element* num1, Element* num2, const String* digits);

/*
Sets num1 to num1/num2
*/
int timesdiv_div(Element* num1, Element* num2, const String* digits);

#endif
