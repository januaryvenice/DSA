#include "stackADT_linkedlist.h"

void initialize(Stack * top){
    *top = NULL;
}

void push(Stack * top, int x){
    Stack temp = (Stack)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->elem = x;
        temp->next = *top;
        *top = temp;
    } else {
        printf("Memory Allocation failed.\n");
    }
}

void pop(Stack * top){
    if(isEmpty(*top)==0){
        Stack temp = *top;
        *top = temp->next;
        free(temp);
    } else {
        printf("List is empty.\n");
    }
    
}

int top(Stack top){
    return (isEmpty(top) == 0) ? top->elem : -1;
}

int isEmpty(Stack top){
    return (top == NULL) ? 1 : 0;
}

int isFull(Stack top){
    return 0;
}

void print(Stack * top){
    Stack temp = NULL;
    int elem;
    while(isEmpty(*top)==0){
        push(&temp, (*top)->elem);
        pop(top);
    }

    while(isEmpty(temp)==0){
        printf("%d ", temp->elem);
        push(top, temp->elem);
        pop(&temp);
    }
    printf("\n");
}

void insertBottom(Stack * top, int x){
    Stack temp = NULL;
    int elem;
    while(isEmpty(*top)==0){
        push(&temp, (*top)->elem);
        pop(top);
    }

    push(top, x);

    while(isEmpty(temp)==0){
        push(top, temp->elem);
        pop(&temp);
    }
}