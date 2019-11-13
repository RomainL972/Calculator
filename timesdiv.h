#ifndef TIMESDIV_H_INCLUDED
#define TIMESDIV_H_INCLUDED

#include "structs_enums.h"

int timesdiv_times(Element* num1, Element* num2, const char* digits);
int timesdiv_div(Element* num1, Element* num2, const char* digits);
int timesdiv_minmax(Element** num1, Element** num2, const char* digits);
int timesdiv_copy(Element *num1, Element *num2);

#endif
