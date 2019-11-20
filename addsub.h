#ifndef ADDSUB_H_INCLUDED
#define ADDSUB_H_INCLUDED

#include "structs_enums.h"

/*
Adds or Substracts two numbers depending on their sign
*/
int addsub_prepare(Element *num1, Element *num2, const char* digits);

/*
Sets num1 to num1+num2
*/
int addsub_add(Element *num1, Element *num2, const char *digits);

/*
Sets num1 to num1-num2
*/
int addsub_sub(Element *num1, Element *num2, const char *digits);

/*
Sets element to -element
*/
int addsub_invert(Element *element);

#endif
