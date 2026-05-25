#include <stdlib.h>
#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    int carry = 0, sum;
    Dlist *t1 = *tail1;
    Dlist *t2 = *tail2;

    *headR = *tailR = NULL;

    while (t1 != NULL || t2 != NULL) {
        sum = carry;
        if (t1) { sum += t1->data; t1 = t1->prev; }
        if (t2) { sum += t2->data; t2 = t2->prev; }

        carry = sum / 10;
        insert_front(headR, tailR, sum % 10);
    }

    if (carry)  insert_front(headR, tailR, carry);
    return SUCCESS;
}

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *t1 = *tail1;
    Dlist *t2 = *tail2;
    int borrow = 0;

    *headR = *tailR = NULL;
    while (t1) {
        int sub = t1->data - (t2 ? t2->data : 0) - borrow;                     // if t2 is null then substract with zero

        if (sub < 0) {
            sub += 10;
            borrow = 1;
        }
        else borrow = 0;

        insert_front(headR, tailR, sub); 

        t1 = t1->prev;
        if (t2) t2 = t2->prev;
    }
    remove_leading_zeros(headR, tailR);
    return SUCCESS;
}

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR) 
{
    Dlist *t1 = *head1, *t2 = *head2;
    if (is_zero(t1) || is_zero(t2)) {                                          // for any one operand is 0
        *headR = *tailR = NULL;
        insert_front(headR, tailR, 0);
        return SUCCESS;
    }

    Dlist *resultH = NULL, *resultT = NULL;
    insert_front(&resultH, &resultT, 0);

    int shift = 0;
    for (Dlist *d2 = *tail2; d2; d2 = d2->prev) {
        Dlist *tempH = NULL, *tempT = NULL;
        int carry = 0;

        for (int i = 0; i < shift; i++)     insert_front(&tempH, &tempT, 0);   // adding zeros in lsd

        for (Dlist *d1 = *tail1; d1; d1 = d1->prev) {
            int prod = d1->data * d2->data + carry;
            carry = prod / 10;
            insert_front(&tempH, &tempT, prod % 10);
        }

        if (carry)      insert_front(&tempH, &tempT, carry);

        addition(&resultH, &resultT, &tempH, &tempT, &resultH, &resultT);      // adding each partial result
        shift++;
    }
    *headR = resultH;
    *tailR = resultT;
    return SUCCESS;
}
