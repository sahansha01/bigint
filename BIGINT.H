#ifndef BIGINT_H
#define BIGINT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct {
    node *head;
    char sign;
    int size;
} BIGINT;

BIGINT *add(BIGINT *num1, BIGINT *num2);
BIGINT *mul(BIGINT *n1, BIGINT *n2);
BIGINT *mod(BIGINT *num1, BIGINT *num2);
BIGINT *subtract(BIGINT *num1, BIGINT *num2);
BIGINT *div1(BIGINT *num1, BIGINT *num2);
int compare(BIGINT *num1, BIGINT *num2, char *c);
BIGINT *initialize();
node *reverse(node *head);
void insert(BIGINT *num, int element);
void display_reverse(node *head);
char cmp(BIGINT *num1, BIGINT *num2);
BIGINT *copy(BIGINT *num1);
int length(node *head);

#endif
