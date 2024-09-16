#include <stdio.h>
#define MAX 5

typedef struct{
    int data, next;
}Nodes;

typedef struct{
    Nodes node[MAX];
    int Avail;
}VirtualHeap;

typedef int List;

void initVirtualHeap(VirtualHeap * V);
int allocSpace(VirtualHeap * V);
void deallocSpace(VirtualHeap * V, int index);
void display(VirtualHeap V, List L);
void insertFirst(VirtualHeap * V, List * L, int data);
void insertLast(VirtualHeap * V, List * L, int data);
void insertSorted(VirtualHeap * V, List * L, int data);
void deleteElem(VirtualHeap * V, List * L, int elem);
void deleteAllOccur(VirtualHeap * V, List * L, int elem);

int main(){
    VirtualHeap VH;
    List L = -1;
    initVirtualHeap(&VH);
    insertFirst(&VH, &L, 2);
    insertFirst(&VH, &L, 1);
    insertFirst(&VH, &L, 3);
    display(VH, L);
    deleteElem(&VH, &L, 3);
    display(VH, L);
    insertLast(&VH, &L, 4);
    insertSorted(&VH, &L, 0);
    insertSorted(&VH, &L, 0);
    display(VH, L);
    deleteAllOccur(&VH, &L, 0);
    display(VH, L);
    return 0;
}

void initVirtualHeap(VirtualHeap * V){
    int x;
    for(x=0;x<MAX-1;x++){
        V->node[x].next = x+1;
    }
    V->node[x].next=-1;
    V->Avail=0;
}

int allocSpace(VirtualHeap * V){
    int space=V->Avail;
    if(space != -1){
        V->Avail = V->node[space].next;
    }
    return space;
}

void deallocSpace(VirtualHeap * V, int index){
    if(index > 0 && index < MAX){
        V->node[index].next = V->Avail;
        V->Avail = index;
    }
}

void display(VirtualHeap V, List L){
    int trav;
    for(trav=L;trav!=-1;trav=V.node[trav].next){
        printf("%d ", V.node[trav].data);
    }
    printf("\n");
}

void insertFirst(VirtualHeap * V, List * L, int data){
    int temp = allocSpace(V);
    if(temp!=-1){
        V->node[temp].data=data;
        V->node[temp].next=*L;
        *L=temp;
    }
}

void insertLast(VirtualHeap * V, List * L, int data){
    int temp = allocSpace(V);
    if(temp!=-1){
        V->node[temp].data=data;
        V->node[temp].next=-1;
        int * trav;
        for(trav=L;*trav != -1; trav = &V->node[*trav].next){}
        *trav = temp;
    }
}

void deleteElem(VirtualHeap * V, List * L, int elem){
    int * trav;
    for(trav=L;*trav != -1 && V->node[*trav].data != elem; trav = &V->node[*trav].next){}
    if(*trav != -1){
        int temp = *trav;
        *trav = V->node[temp].next;
        deallocSpace(V, temp);
    }
}

void insertSorted(VirtualHeap * V, List * L, int data){
    int temp = allocSpace(V);
    if(temp!=-1){
        V->node[temp].data=data;
        int * trav;
        for(trav=L; *trav != -1 && V->node[*trav].data < data; trav = &V->node[*trav].next){}
        V->node[temp].next = *trav;
        *trav = temp;
    }
}

void deleteAllOccur(VirtualHeap * V, List * L, int elem){
    int * trav;
    for(trav=L;*trav != -1;){
        if(V->node[*trav].data == elem){
            int temp = *trav;
            *trav = V->node[temp].next;
            deallocSpace(V, temp);
        }else{
            trav = &V->node[*trav].next;
        }
    }
}