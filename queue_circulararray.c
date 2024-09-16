#include <stdio.h>
#include <stdbool.h>
#define MAX 5

typedef struct{
    int arr[MAX], front, rear;
}queue;

void initQueue(queue *);
bool isEmpty(queue *); 
bool isFull(queue *);
void displayQueue(queue *);
void enqueue(queue *, int data);
void dequeue(queue *);

int main(){
   queue Q;
   initQueue(&Q);
   enqueue(&Q, 5);
   enqueue(&Q, 10);
   enqueue(&Q, 15);
   enqueue(&Q, 20);
   displayQueue(&Q);
   dequeue(&Q);
   dequeue(&Q);
   dequeue(&Q);
   dequeue(&Q);
   displayQueue(&Q);
   return 0;
}

void initQueue(queue * A){
    A->front = 0;
    A->rear = MAX-1;
}

bool isEmpty(queue * A){
    return A->front == (A->rear + 1)%MAX;
}

bool isFull(queue * A){
    return A->front == (A->rear + 2)%MAX;
}

void displayQueue(queue * A){
    if(isEmpty(A)){
        printf("Queue is empty");
    } else {
        int x;
        for(x=A->front; x!=A->rear; x = (x+1)%MAX){
            printf("%d ", A->arr[x]);
        }
        printf("%d\n", A->arr[A->rear]);
    }
}

void enqueue(queue * A, int data){
    if(isFull(A)){
        printf("Queue is full");
    } else {
        A->rear = (A->rear + 1)%MAX;
        A->arr[A->rear] = data;
    }
}

void dequeue(queue * A){
    if(isEmpty(A)){
        printf("Queue is empty");
    } else {
        if(A->front == A->rear){
            A->front = 0;
            A->rear = MAX-1;
        } else {
            A->front = (A->front + 1)%MAX;
        }
    }
}