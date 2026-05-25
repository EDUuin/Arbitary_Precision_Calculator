#include <stdio.h>
#include <stdlib.h>
#include "apc.h"

int str_to_list(char **argv, Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2)
{
    int i = 0;
    if (argv[1][0] == '+' || argv[1][0] == '-')     i = 1;

    Dlist *new1 = (Dlist *)malloc(sizeof(Dlist));
    if (!new1) return FAILURE;

    *head1 = *tail1 = new1;
    new1->prev = NULL;
    new1->next = NULL;
    new1->data = argv[1][i++] - '0';                                 // storing 1st digit char in list

    Dlist *temp = *head1;
    for (; argv[1][i]; i++) {
        new1 = (Dlist *)malloc(sizeof(Dlist));
        if (!new1) return FAILURE;

        temp->next = new1;
        new1->prev = temp;
        new1->next = NULL;
        new1->data = argv[1][i] - '0';                               // storing digits in list

        temp = new1;
        *tail1 = new1;
    }

    int j = 0;
    if (argv[3][0] == '+' || argv[3][0] == '-') j = 1;

    Dlist *new2 = (Dlist *)malloc(sizeof(Dlist));
    if (!new2) return FAILURE;

    *head2 = *tail2 = new2;
    new2->prev = NULL;
    new2->next = NULL;
    new2->data = argv[3][j++]- '0';                                 // storing 1st digit char in list

    temp = *head2;
    for (; argv[3][j]; j++) {
        new2 = (Dlist *)malloc(sizeof(Dlist));
        if (!new2) return FAILURE;

        temp->next = new2;
        new2->prev = temp;
        new2->next = NULL;
        new2->data = argv[3][j] - '0';                               // storing digits in list

        temp = new2;
        *tail2 = new2;
    }
    return SUCCESS;
}

int compare_lists(Dlist *h1, Dlist *h2)
{
    int len1 = 0, len2 = 0;
    Dlist *t1 = h1, *t2 = h2;

    while (t1) { len1++; t1 = t1->next; }                            // taking no. of nodes in each list
    while (t2) { len2++; t2 = t2->next; }

    if (len1 > len2) return 1;                                       // comparing length wise
    if (len1 < len2) return -1;

    while (h1 && h2) {                                               // if both lengh r same then compare digit from head to tail
        if (h1->data > h2->data) return 1;
        if (h1->data < h2->data) return -1;
        h1 = h1->next;
        h2 = h2->next;
    }
    return 0;                                                        // if both num are same 
}

void add_sign_node(Dlist **headR, Dlist **tailR)
{
    if (*headR == NULL)     return;                                  // list empty

    Dlist *new = (Dlist *)malloc(sizeof(Dlist));
    new->data = -1;                                                  // adding sign node data as -1
    new->prev = NULL;
    new->next = *headR;

    (*headR)->prev = new;
    *headR = new;
}

void insert_front(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = (Dlist *)malloc(sizeof(Dlist));
    new->data = data;                                                // adding data at head node
    new->prev = NULL;
    new->next = *head;

    if (*head)      (*head)->prev = new;                             // if head is not null
    else            *tail = new;

    *head = new;
}

int is_zero(Dlist *head)
{
    while (head) {                                                   // check all list data is 0
        if (head->data != 0)    return 0;
        head = head->next;
    }
    return 1;
}

void copy_list(Dlist *src, Dlist **head, Dlist **tail)
{
    *head = *tail = NULL;
    while (src) {                                                    // src is a head node bascially creating a copy of list 
        Dlist *new = malloc(sizeof(Dlist));
        new->data = src->data;
        new->next = NULL;
        new->prev = *tail;

        if (*tail)  (*tail)->next = new;
        else        *head = new;

        *tail = new;
        src = src->next;
    }
}

void increment_by_one(Dlist **head, Dlist **tail)
{
    Dlist *oneH = NULL, *oneT = NULL;
    insert_front(&oneH, &oneT, 1);                                   // creating a list with only 1 as data and one node
    addition(head, tail, &oneH, &oneT, head, tail);                  // adding 1 
}

void remove_leading_zeros(Dlist **head, Dlist **tail)
{
    while (*head && (*head)->data == 0 && *head != *tail) {          // remove meaning less zeros
        Dlist *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
}

void print_list(Dlist *headR)
{
    if (!headR) {
        printf("INFO : List is empty\n");
        return;
    }

    if (headR->data == -1) {                                         // print sign 
        printf("-");
        headR = headR->next;
    }

    while (headR) {
        printf("%d", headR->data);                                   // print data
        headR = headR->next;
    }
    printf("\n");
}
