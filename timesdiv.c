#include "timesdiv.h"
#include "calculate.h"

/*TODO finish writing those functions*/
int timesdiv_times(Element* num1, Element* num2, const char* digits) {
    int sign=0, i;
    calculate_minmax(&num1, &num2, digits);
    sign = !(num1->sign ^ num2->sign);
    for(i = 0; i < num1->size-1; i++);
    num1->sign = sign;
    return 0;
}

int timesdiv_div(Element* num1, Element* num2, const char* digits) {
    return 0;
}
