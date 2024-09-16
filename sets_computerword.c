/**
BITS ARE INDEXED STARTING AT 0
POSITION STARTS AT 1
 */
#include <stdio.h>

typedef unsigned char SET;

void initSet(SET * A);
void displaySet(SET A, int size);
int member(SET A, int pos, int size);
void insertAtPos(SET * A, int pos, int size);
void deleteAtPos(SET * A, int pos, int size);
SET unionSet(SET A, SET B);
SET intersection(SET A, SET B);
SET difference(SET A, SET B);

int main(){
    SET A;
    int size = sizeof(SET)*8;
    initSet(&A);
    insertAtPos(&A, 8, size);
    insertAtPos(&A, 2, size);
    displaySet(A, size);
    deleteAtPos(&A, 3, size);
    displaySet(A, size);
    int bit = member(A,1,size);
    printf("%d\n", bit);

    SET B;
    initSet(&B);
    insertAtPos(&B, 8, size);
    insertAtPos(&B, 7, size);
    displaySet(B, size);

    SET C = unionSet(A,B);
    displaySet(C, size);
    C = intersection(A,B);
    displaySet(C, size);
    C = difference(B,A);
    displaySet(C, size);
}

void initSet(SET * A){
    *A = 0;
}

void displaySet(SET A, int size){
    int x;
    for(x=size-1;x>=0;x--){
        printf("%u", (A >> x) & 1);
    }
    printf("\n");
}

void insertAtPos(SET * A, int pos, int size){
    if(pos <= size && pos > 0){
        unsigned int mask = 1 << pos-1;
        *A = *A | mask;
    }
}

void deleteAtPos(SET * A, int pos, int size){
    if(pos <= size && pos > 0){
        unsigned int mask = 1 << pos-1;
        *A = *A & ~(mask);
    }
}

int member(SET A, int pos, int size){
    unsigned int mask = 1 << pos-1;
    if(pos <= size && pos > 0){
        A = A & (mask);
    }
    return (A == mask) ? 1 : 0;
}

SET unionSet(SET A, SET B){
    SET C = A | B;
    return C;
}

SET intersection(SET A, SET B){
    SET C = A & B;
    return C;
}

SET difference(SET A, SET B){
    SET C = A & ~B;
    return C;
}

