#include "string.h"
#include <stdlib.h>

int string_length(const char string[]) {
    int i;
    for(i = 0; string[i] != '\0'; i++);
    return i;
}

int string_contains(const char haystack[], char needle) {
    int i;
    for(i = 0; haystack[i] != '\0' && haystack[i] != needle; i++);
    if(haystack[i] == '\0') return -1;
    return i;
}

int string_contains_array(const char haystack[], const char needles[]) {
    int i;
    for(i = 0; needles[i] != '\0'; i++) {
        if(string_contains(haystack, needles[i]) != -1) return 1;
    }
    return 0;
}

int string_double(const char string[]) {
    int i;
    int array[256] = {0};
    for(i = 0; string[i] != '\0'; i++) {
        array[(unsigned int)string[i]]++;
        if(array[(unsigned int)string[i]] > 1) return 1;
    }
    return 0;
}

/*TODO: error on malloc fail*/
char* string_leftpad(const char string[], char letter, int times) {
    int i, j;
    char *newString = malloc(sizeof(char));
    newString[0] = '\0';
    for(i = 0; i < times; i++) {
        newString = realloc(newString, sizeof(char)*i+1);
        newString[i] = letter;
    }
    for(j = 0; string[j] != '\0'; j++) {
        newString = realloc(newString, sizeof(char)*i+1);
        newString[i] = string[j];
        i++;
    }
    newString = realloc(newString, sizeof(char)*i+1);
    newString[i] = '\0';
    return newString;
}

int string_append(char* string, char letter, int times) {
    int i, length=string_length(string);
    string = realloc(string, sizeof(char)*(length+times));
    for(i = 0; i < times; i++) {
        string[length+i] = letter;
    }
    string[length+times] = '\0';
    return 0;
}
