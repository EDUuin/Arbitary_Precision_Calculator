#include <stdlib.h>
#include <stdio.h>
#include "apc.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    if (*head2 == NULL || is_zero(*head2)) {                          // checking 2nd operand is zero
        printf("ERROR: Division by zero\n");
        return FAILURE;
    }

    *headR = *tailR = NULL;
    insert_front(headR, tailR, 0);                                   // giving 0 as starting value for repeated subtraction

    Dlist *tempH = NULL, *tempT = NULL;
    copy_list(*head1, &tempH, &tempT);                               // copy operand 1 to another list

    while (tempH && compare_lists(tempH, *head2) >= 0) {
        Dlist *aH = NULL, *aT = NULL;
        Dlist *bH = NULL, *bT = NULL;

        copy_list(tempH, &aH, &aT);                                  // copy operand 1 to another list
        copy_list(*head2, &bH, &bT);                                 // copy operand 2 to another list

        Dlist *resH = NULL, *resT = NULL;

        subtraction(&aH, &aT, &bH, &bT, &resH, &resT);
        remove_leading_zeros(&resH, &resT);                          // removing leading zeros

        tempH = resH;
        tempT = resT;

        increment_by_one(headR, tailR);                              // add result with one
    }
    return SUCCESS;
}