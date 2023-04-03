#include<stdio.h>
#include<stdlib.h>

typedef struct stackNode {
    int data;
    struct stackNode *nextPtr;
}StackNode;

typedef StackNode *sNodePtr;

int isEmpty(sNodePtr stackPtr);
void push(sNodePtr *stackPtr, int newData);
int pop(sNodePtr *stackPtr);
void printStack(sNodePtr stackPtr);
void instructions(void);
int main(){
    puts(">Avvio menu...");
    instructions();
}

void instructions(){
    sNodePtr stackPtr= NULL;

    printf("%s", "Inserisci la scelta: \n"
    "1 - Inserisci valore nella pila\n"
    "2 - Estrai valore dalla pila\n"
    "3 - Stampa pila\n"
    "4 - Termina programma\n");
    int choice;
    printf("%s","#");
    scanf("%d", &choice);
    int newData=0;
    while(choice!=4){
        switch(choice){
            case 1: 
                printf("%s", "Inserisci il valore: ");
                scanf("%d", &newData);
                push(&stackPtr, newData);
                printStack(stackPtr);
                break;
            case 2:
                if(isEmpty(stackPtr)){
                    printf("%s","La pila è vuota\n");   
                }
                else{
                    printf("The pop value is %d\n",pop(&stackPtr));
                    printStack(stackPtr);
                }
                break;
            case 3:
                printStack(stackPtr);
                break;
            default: 
                puts("Scelta non valida");
                break;
        }
        printf("%s","...\n""Insersci la scelta -->  ");
        scanf("%d", &choice);
    }
    puts("Programma terminato");
}

int isEmpty(sNodePtr stackPtr){
    return stackPtr==NULL;
}
void printStack(sNodePtr stackPtr){
    if(isEmpty(stackPtr)){
        printf("La pila è vuota");
    }
    else{
        while(stackPtr!=NULL){
            printf("%d->", stackPtr->data);
            stackPtr= stackPtr->nextPtr;
        }
        puts("NULL\n");
    }
}

void push(sNodePtr *stackPtr, int newData){
    sNodePtr newNode= malloc(sizeof(StackNode));

    if(newNode==NULL){
        printf("%d non memorizzato, memoria insufficente", newData);
    }
    else{
        newNode->data= newData;          
        newNode->nextPtr= *stackPtr;
        *stackPtr=newNode;
    }
}

int pop(sNodePtr *stackPtr){
    sNodePtr tempNode= *stackPtr;

    int delData= tempNode->data;
    *stackPtr= tempNode->nextPtr;

    free(tempNode);
    return delData;
}