#ifndef STACKADT_LINKEDLIST_H
#define STACKADT_LINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int elem;
    struct node * next;
}*Stack;

void initialize(Stack * top);
void push(Stack * top, int x);
void pop(Stack * top);
int top(Stack top);
int isEmpty(Stack top);
int isFull(Stack top);
void print(Stack * top);
void insertBottom(Stack * top, int x);

#endif