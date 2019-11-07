#include "args.h"
#include "string.h"

int args_check(int argc, char const *argv[]) {
    int i;
    if(argc != 2) return -1;
    for(i = 0; argv[1][i] != '\0' && argv[1][i] > 32 && argv[1][i] < 127; i++);
    if(argv[1][i] != '\0') return -2;
    if(string_contains_array(argv[1], "+-*/()")) return -3;
    if(string_double(argv[1])) return -4;
    return 0;
}
