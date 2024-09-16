#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * next;
}*SET;

SET unionSorted (SET A, SET B);
SET intersection(SET A, SET B);
SET difference(SET A, SET B);
void insertEnd(SET * A, int elem);
void printList(SET A);

int main(){
    SET A = NULL;
    SET B = NULL;
    insertEnd(&A, 1);
    insertEnd(&A, 2);
    insertEnd(&A, 3);
    insertEnd(&B, 1);
    insertEnd(&B, 4);
    insertEnd(&B, 5);
    //SET C = unionSorted(A, B);
    //SET C = intersection(A,B);
    SET C = difference(A,B);
    printList(C);
    free(C);
    return 0;
}

void insertEnd(SET * A, int elem){
    SET * trav;
    for(trav=A;(*trav)!=NULL;trav=&(*trav)->next){}
    SET temp = (SET)malloc(sizeof(struct node));
    if(temp!=NULL){
        temp->data=elem;
        temp->next=NULL;
        (*trav)=temp;
    }else{
        printf("Memory Allocation failed");
    }
}

void printList(SET A){
    SET trav;
    for(trav=A;trav!=NULL;trav=trav->next){
        printf("%d ",trav->data);
    }
    printf("\n");
}

SET unionSorted (SET A, SET B) {
    SET C = NULL;
    SET *cptr = &C;
    SET aptr = A, bptr = B;

    while (aptr != NULL && bptr != NULL) {
        *cptr = (SET)malloc(sizeof(struct node));
        if (*cptr != NULL) {
            if (aptr->data < bptr->data) {
                (*cptr)->data = aptr->data;
                 aptr = aptr->next;
            } else {
                if(aptr->data == bptr->data){
                    aptr = aptr->next;
                }
                (*cptr)->data = bptr->data;
                bptr = bptr->next;
            }
            cptr = &(*cptr)->next;
        }
    }

    if (bptr != NULL){
        aptr = bptr;
    }
    while (aptr != NULL) {
        *cptr = (SET)malloc(sizeof(struct node));
        if (*cptr != NULL) {
             (*cptr)->data = aptr->data;
             aptr = aptr->next; 
             cptr = &(*cptr)->next;
    }
    
}
    *cptr = NULL;
    return C;
}

SET intersection(SET A, SET B){
    SET C = NULL;
    SET aptr, bptr;
    SET * cptr = &C;
    for(aptr=A; aptr != NULL; aptr = aptr->next){
        for(bptr = B; bptr != NULL && aptr->data != bptr->data; bptr=bptr->next){} 
        if(bptr != NULL){
            *cptr = (SET)malloc(sizeof(struct node));
            if(*cptr != NULL){
                (*cptr)->data = aptr->data;
                cptr = &(*cptr)->next;
            }    
        }
    }
    *cptr=NULL;
    return C;
}

SET difference(SET A, SET B){
    SET C = NULL;
    SET aptr, bptr;
    SET * cptr = &C;
    for(aptr=A; aptr != NULL; aptr = aptr->next){
        for(bptr = B; bptr != NULL && aptr->data !=bptr->data; bptr=bptr->next){} 
        if(bptr==NULL){
            *cptr = (SET)malloc(sizeof(struct node));
            if(*cptr != NULL){
                (*cptr)->data = aptr->data;
                cptr = &(*cptr)->next;
            }  
        }
    }
    *cptr=NULL;
    return C;
}