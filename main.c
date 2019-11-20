#include "args.h"
#include "parse_stdin.h"
#include "structs_enums.h"
#include "calculate.h"
#include "string_struct.h"
#include <stdlib.h>
#include <stdio.h>

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
    String *digits = malloc(sizeof(String));
    Expression* tree = malloc(sizeof(Expression));
    if(args_check(argc, argv)) return 1;
    string_struct_from_chars(digits, argv[1]);
    if((error = parse_stdin_init(tree, digits))) return error;
    if((error = calculate_start(tree))) return error;
    if(!tree->floors[0]->expressions[0]->elements[0]->sign) printf("-%s\n", tree->floors[0]->expressions[0]->elements[0]->digits->str);
    else printf("%s\n", tree->floors[0]->expressions[0]->elements[0]->digits->str);
    return 0;
}
