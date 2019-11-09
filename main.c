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
    int error, i, j, k;
    Expression* tree = malloc(sizeof(Expression));
    Floor *floor;
    SubExpression *expression;
    Element *element;
    char string[500];
    char substring[5];
    substring[1] = '\0';
    if(args_check(argc, argv)) return 1;
    error = parse_stdin_init(tree, argv[1]);
    if(error) return error;
    error = calculate_start(tree, argv[1]);
    if(error) return error;
    printf("%s\n", tree->floors[0]->expressions[0]->elements[0]->digits);

    /*
    for(i = 0; i < tree->size; i++) {
        floor = tree->floors[i];
        for(j = 0; j < floor->size; j++) {
            expression = floor->expressions[j];
            string[0] = '\0';
            for(k = 0; k < expression->size; k++) {
                element = expression->elements[k];
                if(element->type == Number) strcat(string, element->digits);
                else if(element->type == Operator){
                    substring[0] = element->operator;
                    strcat(string, substring);
                }
                else strcat(string, "?");
            }
            printf("Floor %d, Expression %d: %s\n", i, j, string);
        }
    }*/
    return 0;
}
