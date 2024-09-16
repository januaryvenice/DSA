#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct cell{
    int data;
    struct cell * link;
}*queueType;

typedef struct{
    queueType front;
    queueType rear;
}Queue;

void initQueue(Queue * );
void display(Queue );
bool isEmpty(Queue );
void enqueue(Queue * , int);
void dequeue(Queue *);

int main(){
    Queue q;
    initQueue(&q);
    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 15);
    display(q);
    dequeue(&q);
    display(q);
    dequeue(&q);
    display(q);
    return 0;
}

void initQueue(Queue * Q){
    Q->front = Q->rear = NULL;
}

bool isEmpty(Queue Q){
    return Q.front == NULL && Q.rear==NULL;
}

void display(Queue Q){
    if(isEmpty(Q)){
        printf("Queue is empty");
    }else{
        queueType trav;
        for(trav = Q.front; trav!=NULL; trav=trav->link){
            printf("%d ", trav->data);
        }
        printf("\n");
    }
}

void enqueue(Queue * Q, int x){
    queueType temp = (queueType)malloc(sizeof(struct cell));
    if(temp != NULL){
        temp->data = x;
        temp->link = NULL;
        if(isEmpty(*Q)){
            Q->front = temp;
        } else {
            Q->rear->link = temp;
        }
        Q->rear = temp;
    } else {
        printf("Memory Allocation failed");
    }
}

void dequeue(Queue * Q){
    if(isEmpty(*Q)){
        printf("Queue is empty");
    } else {
        queueType temp = Q->front;
        if(Q->front == Q->rear){
            Q->rear = NULL;
        }
        Q->front=temp->link;
        free(temp);
    }
}