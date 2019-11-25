#include "free_main.h"
#include "element_utils.h"
#include <stdlib.h>

int free_main(Expression *tree, String *digits) {
    element_utils_free(tree->floors[0]->expressions[0]->elements[0]);
    free(tree->floors[0]->expressions[0]->elements);
    free(tree->floors[0]->expressions[0]);
    free(tree->floors[0]->expressions);
    free(tree->floors[0]);
    free(tree->floors);
    free(tree);
    free(digits->str);
    free(digits);
    return 0;
}
