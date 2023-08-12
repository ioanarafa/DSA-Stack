#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    struct node* next;
}nodeT;

//1
nodeT* creare(int givenkey){
    nodeT* p = (nodeT*)malloc(sizeof(nodeT));
    p->key = givenkey;
    p->next = NULL;

    return p;
}

//2
void push(int givenkey, nodeT** first){
    nodeT* p = creare(givenkey);
    p->next = *first;
    *first = p;
}

//3
int pop(nodeT** first){
    nodeT* p = (*first);
    p = p->next;
    int val = (*first)->key;
    free(*first);
    *first = p;

    return val;
}

//4
void afisare(nodeT* first){
    nodeT* p =first;
    while(p!=NULL)
    {
        printf("%d ", p->key);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    nodeT* first = NULL;
    push(3, &first);
    push(6, &first);
    push(1, &first);
    afisare(first);


    int out = pop(&first);
    pop(&first);
    afisare(first);
    return 0;
}
