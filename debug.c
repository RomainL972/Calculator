#include "debug.h"
#include "addsub.h"
#include "structs_enums.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    Element num1 = {Number, 0, 1, "1", 1, NULL};
    Element num2 = {Number, 0, 1, "1", 1, NULL};

    addsub_prepare(&num1, &num2, "0123456789");

    printf("Result: %s\n", num1.digits);
    if(!num1.sign) printf("Note: negative\n");
    return 0;
}
