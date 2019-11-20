#ifndef STRUCTS_ENUMS_H_INCLUDED
#define STRUCTS_ENUMS_H_INCLUDED

typedef struct SubExpression SubExpression;
typedef struct Floor Floor;
typedef struct Expression Expression;
typedef struct String String;

/*
Different element types
*/
typedef enum {
    Number,
    Operator,
    Reference
} ElementType;

/*
Struct for any element in SubExpression
*/
typedef struct {
    ElementType type;
    char operator;
    String* digits;
    int sign; /*1:positive, 0:negative*/
    SubExpression* child;
} Element;

/*
Stores a subexpression
*/
struct SubExpression {
    int size;
    Element** elements;
    SubExpression* parent;
    Element* refParent;
    Floor* floor;
};

/*
Stores a priority floor of the expression
*/
struct Floor {
    int size;
    SubExpression** expressions;
    int priority;
    Expression *parent;
};

/*
Stores the whole expression
*/
struct Expression {
    int size;
    Floor** floors;
    const String *digits;
};

/*
String type containing char array and length
*/
struct String {
    int length;
    char* str;
};

#endif
