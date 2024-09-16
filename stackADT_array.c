#include "stackADT_array.h"

void initialize(Stack * S){
    S->top = -1;
}

void push(Stack * S, int x){
    if(isFull(*S)== 0){
        S->top++;
        S->elems[S->top] = x;
    } else {
        printf("List is full.\n");
    }
}

void pop(Stack * S){
    if(isEmpty(*S)==0){
        S->top--;
    } else {
        printf("List is empty.\n");
    }
}

int top(Stack S){
    return (isEmpty(S)==0) ? S.elems[S.top] : -1;
}

int isEmpty(Stack S){
    return (S.top == -1) ? 1 : 0;
}

int isFull(Stack S){
    return (S.top == MAX-1) ? 1 : 0;
}

void print(Stack * S){
    Stack temp;
    initialize(&temp);
    while(isEmpty(*S)==0){
        push(&temp, S->elems[S->top]);
        pop(S);
    }

    while(isEmpty(temp)==0){
        printf("%d ", temp.elems[temp.top]);
        push(S, temp.elems[temp.top]);
        pop(&temp);
    }
    printf("\n");
}

void insertBottom(Stack * S, int x){
    Stack temp;
    initialize(&temp);
    while(isEmpty(*S)==0){
        push(&temp, S->elems[S->top]);
        pop(S);
    }

    push(S, x);

    while(isEmpty(temp)==0){
        push(S, temp.elems[temp.top]);
        pop(&temp);
    }
}
