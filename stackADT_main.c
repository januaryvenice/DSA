#include <stdio.h>
#include <stdlib.h>
#include "stackADT_linkedlist.h"
#include "stackADT_linkedlist.c"
// #include "stackADT_array.h"
// #include "stackADT_array.c"

int main(){
    Stack S;
    initialize(&S);
    push(&S, 1);
    push(&S, 2);
    push(&S, 3);
    push(&S, 4);
    print(&S);
    pop(&S);
    print(&S);
    insertBottom(&S, 0);
    print(&S);
    return 0;
}