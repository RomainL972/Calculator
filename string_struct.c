#include "string_struct.h"
#include "string.h"
#include <string.h>
#include <stdlib.h>

int string_struct_from_chars(String *string, const char* char_array) {
    string->length = string_length(char_array)+1;
    string->str = realloc(string->str, string->length * sizeof(char));
    memcpy(string->str, char_array, string->length*sizeof(char));
    return 0;
}

int string_struct_add_chars(String *string, char toAdd, int times) {
    int i;
    string->length += times;
    string->str = realloc(string->str, sizeof(char)*string->length);
    if(!string->str) return 2;
    for(i = 0; i < times; i++) {
        string->str[string->length-times-1+i] = toAdd;
    }
    string->str[string->length-1] = '\0';
    return 0;
}

int string_struct_init(String *string) {
    string->length = 1;
    if(!string->str) {
        if(!(string->str = malloc(sizeof(char)))) return 2;
    }
    else if (!(string->str = realloc(string->str, sizeof(char)))) return 2;
    string->str[0] = '\0';
    return 0;
}

int string_struct_copy(const String *origin, String *dest) {
    if(!dest) if(!(dest = malloc(sizeof(String)))) return 2;
    dest->length = origin->length;
    dest->str = realloc(dest->str, sizeof(char)*origin->length);
    if(!dest->str) return 2;
    memcpy(dest->str, origin->str, dest->length*sizeof(char));
    return 0;
}

int string_struct_prepend_chars(String *string, char toAdd, int times) {
    String tmp = {0, NULL};
    int i;
    if(string_struct_init(&tmp)) return 2;
    tmp.length = string->length + times;
    tmp.str = realloc(tmp.str, sizeof(char)*(tmp.length));
    for(i=0; i<times; i++) tmp.str[i] = toAdd;
    memcpy(tmp.str+sizeof(char)*times, string->str, string->length*sizeof(char));
    if(string_struct_copy(&tmp, string)) return 2;
    free(tmp.str);
    return 0;
}
