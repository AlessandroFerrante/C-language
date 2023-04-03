#include<stdio.h>
#include<stdlib.h>


typedef struct queueNode {
    char *data;
    struct queueNode *nextPtr;
} qNode;

typedef qNode* QueueNodePtr;
typedef QueueNodePtr qNodePtr;

void printQueue(qNodePtr currentNode);
int isEmpty (qNodePtr headPtr);
void enqueue(qNodePtr *headPtr, qNodePtr *tailPtr, char** newData);
char* denqueue(qNodePtr *headPtr, qNodePtr *tailPtr);
void instructions(void);

int main(){
    puts(">Avvio del menu...");
    instructions();     
}
void instructions(){
    QueueNodePtr headPtr = NULL;
    QueueNodePtr tailPtr = NULL;
    char *item;
    
    puts("Enter your choice: \n"
    "1 - To add an item to the queue \n"
    "2 - To remove an item from th queue \n"
    "3 - To print queue \n"
    "4 - To end program");
    printf("%s","#");
    int choice=0;
    scanf("%d", &choice);

    //finchè l'utente non inserisce 4
    while (choice!=4){
        switch (choice){
        case 1:
            printf("%s","Enter a string: ");
            scanf(" %c", &item);
            enqueue(&headPtr, &tailPtr, &item);
            printQueue(headPtr);
            break;
        case 2:
            if (!isEmpty(headPtr)){
                item = denqueue(&headPtr, &tailPtr);
                if(item!=NULL)
                printf("%c has been denqueue\n", item);
            }
            printQueue(headPtr);
            break;
        case 3:
            printQueue(headPtr);
            break;
        default:
            puts("Invalid choice\n");
            break;
        }
        printf("%c",'#');
        scanf("%d",&choice);
    }
    puts("End of run");
}
void printQueue(qNodePtr currentNode){
    if(currentNode==NULL)
        puts("Queue is empty\n");
    else{
        while(currentNode != NULL){
            printf("%c->",currentNode->data);
            currentNode = currentNode->nextPtr;
        }
        puts("NULL\n");
    }
}
int isEmpty(qNodePtr headPtr){
    return headPtr == NULL;
}

void enqueue(qNodePtr *headPtr, qNodePtr *tailPtr, char **newData)
{
    //qNodePtr tempPtr = *tailPtr;
    qNodePtr newNode= malloc(sizeof(qNode));
    if(newNode!=NULL){
        newNode->data= *newData;
        newNode->nextPtr= NULL;
        if (isEmpty(*headPtr)){
            *headPtr = newNode;//il nuovo nodo è inserito in testa solo se è il primo della coda
        }
        else{
            //tempPtr->nextPtr= newNode; se uso tempPtr
            (*tailPtr)->nextPtr= newNode; //permette di accedere al valore del puntatore del nodo puntato da tailPtr, 
            //in pratica e come se l'ultimo nodo si collega al nuovo nodo per poi diventrare il penultimo con l'istruzione succesiva
        }
        *tailPtr=newNode;//il nuovo nodo è sempre l'ultimo 
    }
    else{
        printf("%s not inserted. No memory avilable\n", *newData);
    }
}

char *denqueue(qNodePtr *headPtr, qNodePtr *tailPtr){
    char *denqData;
    qNodePtr tempNode= *headPtr;
    if(tempNode!=NULL){
        denqData = tempNode->data;
        *headPtr= tempNode->nextPtr;
    }
    else{
        printf("%s","The queue is empty!");
        *tailPtr=NULL;
    }
    free(tempNode);
    return denqData;
}
