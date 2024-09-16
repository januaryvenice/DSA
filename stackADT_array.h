#ifndef STACKADT_ARRAY_H
#define STACKADT_ARRAY_H

#include <stdio.h>
#define MAX 10

typedef struct node{
    int elems[MAX];
    int top;
}Stack;

void initialize(Stack * S);
void push(Stack * S, int x);
void pop(Stack * S);
int top(Stack S);
int isEmpty(Stack S);
int isFull(Stack S);
void print(Stack * S);
void insertBottom(Stack * S, int x);

#endif