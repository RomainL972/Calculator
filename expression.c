#include "expression.h"
#include "parse_stdin.h"
#include <stdlib.h>

int expression_add_floor(Expression *expression, SubExpression *subExpression) {
    Floor *floor;
    expression->size++;
    expression->floors = realloc(expression->floors, sizeof(Floor) * expression->size);
    if(!expression->floors) return 2;
    floor = malloc(sizeof(Floor));
    if(!floor) return 2;
    expression->floors[expression->size-1] = floor;
    floor->size = 0;
    floor->priority = expression->size-1;
    floor->expressions = NULL;
    floor->parent = expression;
    if(expression_floor_add_expression(floor, subExpression)) return 2;
    return 0;
}

int expression_floor_add_expression(Floor *floor, SubExpression *expression) {
    floor->size++;
    floor->expressions = realloc(floor->expressions, sizeof(SubExpression) * floor->size);
    if(!floor->expressions) return 2;
    if(!expression) return 2;
    floor->expressions[floor->size-1] = expression;
    expression->size = 0;
    expression->elements = NULL;
    expression->parent = NULL;
    expression->floor = floor;
    return 0;
}

Element* expression_pop_element(SubExpression* expression) {
    Element *element;
    if(!expression->size) return NULL;
    expression->size--;
    element = expression->elements[expression->size];
    expression->elements = realloc(expression->elements, sizeof(Element)*expression->size);
    if(!expression->elements && expression->size) return NULL;
    return element;
}
