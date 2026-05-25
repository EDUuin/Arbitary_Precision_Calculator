#include <stdio.h>
#include "apc.h"

int main(int argc, char *argv[])
{
    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *headR = NULL, *tailR = NULL;

    char operator;
    int sign1 = 1, sign2 = 1, signR = 1;                                       //  sign flag

    if (argc != 4) {                                                           //  check 4 arguments is passed or not
        printf("Usage: ./apc <operand1> <operator> <operand2>\n");
        return FAILURE;
    }

    if (apc_validation(argv, &operator))                                       // argv validation & operator updation
        return FAILURE;

    if (argv[1][0] == '-') sign1 = -1;                                         // updating sign flag
    if (argv[3][0] == '-') sign2 = -1;

    if (str_to_list(argv, &head1, &tail1, &head2, &tail2))                     // from argv , operands are stored in list as int
        return FAILURE;

    int cmp;
    switch (operator)
    {
        case '+':
            if (sign1 == sign2) {                                              // if both sign are same do addition
                addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                signR = sign1;
            }
            else {                                                             // else (diffferent sign) cmp operands and do substraction  
                cmp = compare_lists(head1, head2);
                if (cmp == 0) {                                                // if both operand r same
                    printf("0\n");
                    return SUCCESS;
                }
                else if (cmp > 0) {                                            // operand 1 > operand 2 and give sign of oper 1
                    subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                    signR = sign1;
                }
                else {                                                         // if operand 2 > operand 1 and give sign of oper 2
                    subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
                    signR = sign2;
                }
            }
            break;

        case '-':
            sign2 = -sign2;                                                    // becoz when 2nd oper is -ve addition happen
            if (sign1 == sign2) {                                              // now if diff sign then addition and put sign
                addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                signR = sign1;
            }
            else {                                                             // else (same sign) cmp operands and do substraction  
                cmp = compare_lists(head1, head2);
                if (cmp == 0) {                                                // if both operand r same then result is 0 
                    printf("0\n");
                    return SUCCESS;
                }
                else if (cmp > 0) {                                            // operand 1 > operand 2 and give sign of oper 1
                    subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                    signR = sign1;
                }
                else {                                                         // if operand 2 > operand 1 and give sign of oper 2
                    subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
                    signR = sign2;
                }
            }
            break;

        case '*':
            multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            signR = sign1 * sign2;
            break;

        case '/':
            if (division(&head1, &tail1, &head2, &tail2, &headR, &tailR) == FAILURE)
                return FAILURE;
            signR = sign1 * sign2;
            break;

        default:
            printf("Invalid operator\n");
            return FAILURE;
    }

    if (signR == -1 && !is_zero(headR))                                        // if sign is -ve and result is not zero
        add_sign_node(&headR, &tailR);                                         // add sign

    print_list(headR);                                                         // print result

    return SUCCESS;
}
