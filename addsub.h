#ifndef ADDSUB_H_INCLUDED
#define ADDSUB_H_INCLUDED

#include "structs_enums.h"

/*
Adds or Substracts two numbers depending on their sign
TODO: num1 and num2 const
*/
int addsub_prepare(Element *result, Element *num1, Element *num2, const String* digits);

/*
Sets num1 to num1+num2
*/
int addsub_add(Element *result, Element *num1, Element *num2, const String *digits);

/*
Sets num1 to num1-num2
*/
int addsub_sub(Element *result, Element *num1, Element *num2, const String *digits);

/*
Sets element to -element
*/
int addsub_invert(Element *element);

#endif
