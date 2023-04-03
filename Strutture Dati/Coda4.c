#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct queueNode{
    char *data;
    struct queueNode *nextPtr;
} qNode;

typedef qNode * qNodePtr;

int isEmpty(qNodePtr headPtr);
void printQueue(qNodePtr headPtr);
void enqueue(qNodePtr *headPtr, qNodePtr *tailPtr, char *newData);
char *denqueue(qNodePtr *headPtr, qNodePtr *tailPtr);
void instructions();

int main(){
    puts("Avvio menu...");
    instructions();
}

void instructions(){
    qNodePtr headPtr=NULL;
    qNodePtr tailPtr=NULL;

    puts("Enter your choice: \n"
    "1 - To add an item to the queue \n"
    "2 - To remove an item from th queue \n"
    "3 - To print queue \n"
    "4 - To end program");
    printf("%s","#");
    int choice=0;
    scanf("%d", &choice);
    char *nData;
    while(choice!=4){
        switch(choice){
            case 1: 
                nData= malloc(100);
                printf("Inserisci una stringa: ");
                scanf("%s", nData);
                enqueue(&headPtr,&tailPtr, nData);
                printf("The string '%s' has been enqueued.\n", nData);
                printQueue(headPtr);
                free(nData);
                break;
            case 2: 
                if(isEmpty(headPtr)){
                    printf("La coda è vuota");
                }
                else{
                    nData = denqueue(&headPtr, &tailPtr);
                    if(nData!=NULL)
                        printf("%s è stata estratta dalla coda", nData);
                }
                printQueue(headPtr);
                break;
            case 3: 
                printQueue(headPtr);
                break;
            default :
                puts("Invalid choice\n");
                break;
        }
        printf("%s","...\n""Inserisci la scelta->");
        scanf("%d", &choice);
    }
    puts("Programma terminato");
}
int isEmpty(qNodePtr headPtr){
    return headPtr== NULL;
}
void printQueue(qNodePtr headPtr){
    if(isEmpty(headPtr)){
        printf("La coda è vuota");
    }
    else{
        printf("Questa è la coda: ");
        while(headPtr!=NULL){
            printf("%s->", headPtr->data);
            headPtr= headPtr->nextPtr;
        }
        puts("NULL\n");
    }
}
void enqueue(qNodePtr *headPtr, qNodePtr *tailPtr, char *newData){
    qNodePtr newNode= malloc(sizeof(qNode));

    if(newNode==NULL)
        printf("%s non aggigunta, memoria insufficente", newData);
    else{
        newNode->data= strdup(newData);
        newNode->nextPtr= NULL;
        if(isEmpty(*headPtr)){
            *headPtr= newNode;
        }
        else{
            (*tailPtr)->nextPtr= newNode;
        }
        *tailPtr=newNode;
    }
}

char *denqueue(qNodePtr *headPtr, qNodePtr *tailPtr){
    qNodePtr tempNode= *headPtr;
    char *denData;

    if(tempNode==NULL){
        printf("%s", "La coda è vuota");
        *tailPtr=NULL;
    }
    else{
        denData= strdup(tempNode->data);
        *headPtr=tempNode->nextPtr;
    }
    free(tempNode);
    return denData;
}