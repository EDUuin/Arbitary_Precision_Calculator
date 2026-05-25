#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef int data_t;

typedef struct node
{
    struct node *prev;
    data_t data;
    struct node *next;
} Dlist;

int apc_validation(char *argv[], char *operator);

int str_to_list(char **argv, Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2);

void print_list(Dlist *headR);

void insert_front(Dlist **head, Dlist **tail, int data);

int is_zero(Dlist *head);

void copy_list(Dlist *src, Dlist **head, Dlist **tail);

void remove_leading_zeros(Dlist **head, Dlist **tail);

void add_sign_node(Dlist **headR, Dlist **tailR);

void increment_by_one(Dlist **head, Dlist **tail);

int compare_lists(Dlist *h1, Dlist *h2);

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

#endif
