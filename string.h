#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

/*
Returns the length of a string

IN: the string
OUT: the size of the string, 0 if empty
*/
int string_length(const char string[]);

/*
Returns if haystack contains needle

NOTE: searching for \0 will return -1

OUT:
- haystack contains needle: position in haystack
- otherwise: -1
*/
int string_contains(const char haystack[], char needle);

/*
Returns wether haystack contains any char in needle

OUT:
- if haystack contains any char in needle: 1
- otherwise: 0
*/
int string_contains_array(const char haystack[], const char needles[]);

/*
Return wether string contains any char twice

OUT:
- string contains any char twice: 1
- otherwise: 0
*/
int string_double(const char string[]);

/*
Include letter at beginning of string multiple times
*/
char* string_leftpad(const char string[], char letter, int times);

/*
Appends letter to string multiple times
*/
int string_append(char* string, char letter, int times);

#endif
