#include <stdio.h>
#include "apc.h"

int apc_validation(char *argv[], char *operator) 
{
    if (argv[2][0] == '+' || argv[2][0] == '-' || argv[2][0] == '*' || argv[2][0] == '/')    *operator = argv[2][0]; // checking operator and storing 
    else {
        printf("ERROR: Invalid operator '%s'\n", argv[2]);
        return FAILURE;
    }

    for (int i = 0; argv[1][i]; i++) {                                         // checking operand 1 is valid
        if (i == 0 && (argv[1][i] == '+' || argv[1][i] == '-') && argv[1][i+1] != '\0')     continue;  // if 1st char is sign and next not null
        if (argv[1][i] < '0' || argv[1][i] > '9') {
            printf("ERROR: Operand 1 should contain only digits\n");
            return FAILURE;
        }
    }

    for (int i = 0; argv[3][i]; i++) {                                         // checking operand 1 is valid
        if (i == 0 && (argv[3][i] == '+' || argv[3][i] == '-') && argv[3][i+1] != '\0')     continue;  // if 1st char is sign and next not null
        if (argv[3][i] < '0' || argv[3][i] > '9') {
            printf("ERROR: Operand 2 should contain only digits\n");
            return FAILURE;
        }
    }
    return SUCCESS;
}
