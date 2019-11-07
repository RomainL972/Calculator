#ifndef ARGS_H_INCLUDED
#define ARGS_H_INCLUDED

/*
Checks if the digits are included and don't contains:
- ASCII codes below 33 and above 126
- + - * / ( )
- twice the same char

IN:
-number of args
-args

SUCCESS: 0
FAILURE:
- Not enough / Too much args: -1
- Incorrect chars: -2
- Forbidden chars: -3
- Doublons: -4
*/
int args_check(int argc, char const *argv[]);

#endif
