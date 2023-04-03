#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct queueNode{
    char *data;
    struct queueNode *nextPtr;
}qNode;

typedef qNode *qNodePtr;

void printQueue(qNodePtr currentNode);
int isEmpty(qNodePtr headPtr);
void enqueue(qNodePtr *headPtr, qNodePtr *tailPtr, char *newData);
char *denqueue(qNodePtr *headPtr, qNodePtr *tailPtr);
void instructions(void);

int main(){
    puts(">Avvio...");
    instructions();
}
void instructions(){
    qNodePtr headPtr = NULL;
    qNodePtr tailPtr = NULL;

    puts("Enter your choice: \n"
    "1 - To add an item to the queue \n"
    "2 - To remove an item from th queue \n"
    "3 - To print queue \n"
    "4 - To end program");
    printf("%s","#");
    int choice=0;
    scanf("%d", &choice);

    while (choice!=4){
        char* item;
        switch (choice){
        case 1:
            item=  malloc(100 * sizeof(char));
            printf("%s","Enter a string: ");
            scanf("%s", item);
            enqueue(&headPtr, &tailPtr, item);
            printf("The string '%s' has been enqueued.\n", item);
            printQueue(headPtr);
            free(item);
            break;
        case 2:
            if (!isEmpty(headPtr)){
                item= denqueue(&headPtr, &tailPtr);
                if(item!=NULL)
                printf("%s has been denqueue\n", item);
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
int isEmpty(qNodePtr headPtr){
    return headPtr == NULL;
}
void printQueue(qNodePtr currentNode){
    if(currentNode==NULL){
        printf("The queue is empty");
    }
    else{
        while(currentNode!=NULL){
            printf("%s->", currentNode->data);
            currentNode= currentNode->nextPtr;
        }
        puts("NULL\n");
    }
}

void enqueue(qNodePtr *headPtr, qNodePtr *tailPtr, char *newData){
    qNodePtr tailNode= *tailPtr;
    qNodePtr newNode= malloc(sizeof(qNode));
    if(newNode==NULL){
        printf("%s not inserted. No memory avilable\n", newData);
    }
    else{
        newNode->data= strdup(newData);//strdup corre usarlo per copiare l'intera stringa altrimenti coperebbe l'indirizzo puntatto da newDatar
        newNode->nextPtr= NULL;
        if(isEmpty(*headPtr)){
            *headPtr= newNode;
        }
        else{
            tailNode->nextPtr=newNode;
        }
        *tailPtr=newNode;
    }
}
char* denqueue(qNodePtr *headPtr, qNodePtr *tailPtr){
    char *denqData;
    qNodePtr tempNode= *headPtr;
    if(tempNode!=NULL){
        denqData= strdup(tempNode->data);
        *headPtr= tempNode->nextPtr;
    }
    else{
        printf("%s","The queue is Empty");
    }
    free(tempNode);
    return denqData;
}