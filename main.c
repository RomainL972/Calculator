#include "args.h"
#include "parse_stdin.h"
#include "structs_enums.h"
#include "calculate.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
OUT:
- Incorrect args: 1
- Malloc fail: 2
- Incorrect stdin: 3
- Decimal division: 4
- Unknown error: 255
*/
int main(int argc, char const *argv[]) {
    int error;
    char sign='\0';
    Expression* tree = malloc(sizeof(Expression));
    if(args_check(argc, argv)) return 1;
    error = parse_stdin_init(tree, argv[1]);
    if(error) return error;
    error = calculate_start(tree, argv[1]);
    if(error) return error;
    if(!tree->floors[0]->expressions[0]->elements[0]->sign) sign = '-';
    printf("%c%s\n", sign, tree->floors[0]->expressions[0]->elements[0]->digits);
    return 0;
}
