#ifndef STRING_STRUCT_H_INCLUDED
#define STRING_STRUCT_H_INCLUDED

#include "structs_enums.h"

/*
Creates a string from a char array
*/
int string_struct_from_chars(String *string, const char* char_array);

/*
Adds a char to string
*/
int string_struct_add_char(String *string, char toAdd);

/*
Sets default values to string
*/
int string_struct_init(String *string);

/*
Sets origin to destination
*/
int string_struct_copy(const String *origin, String *dest);

/*
Prepends a char to string, possibly multiple times
*/
int string_struct_prepend_chars(String *string, char toAdd, int times);

#endif
