#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>


typedef struct listNode{
    char *data;
    struct listNode *nextPtr;
}lNode;
typedef lNode* lNodePtr;

int isEmpty(lNodePtr lPtr);
void printList(lNodePtr lPtr);
void insert(lNodePtr *lPtr, char * newData);
bool delete(lNodePtr *lPtr, char * delData);
void instructions(void);

int main(){
    puts(">Avvio menu...");
    instructions();
}

void instructions(){
    //lNode* lPtr=NULL;
    lNodePtr lPtr= NULL;

    int choice;
    printf("%s","Inserisci una scelta: \n"
    "1 - Inserisci una stringa\n"
    "2 - Elimina una stringa\n"
    "3 - Stampa la lista\n"
    "4 - Termina programma\n"
    "#");
    scanf("%d",&choice);
    char *newData;    

    while(choice!=4){
        switch(choice){
            case 1:
                newData= malloc(100);
                printf("%s", "Inserisci una stringa da inserire nella lista: ");
                scanf("%s", newData);
                insert(&lPtr, newData);
                printf("La stringa %s e' stata aggiunta alla lista\n", newData);
                printList(lPtr);
                free(newData);
                break;
            case 2:
                if (isEmpty(lPtr))
                    printf("%s","La lista e' vuota");
                else{
                    char * delData= malloc(100);                    
                    printf("%s","Inserisci la stringa da eliminare: ");
                    scanf("%s",delData);
                    if(delete(&lPtr, delData)){
                        printf("%s e' stata eliminata\n", delData);
                        printList(lPtr);
                    }
                    else{
                        printf("Stringa %s non trovata\n", delData);
                    }
                }
                break;
            case 3:
                printList(lPtr);
                break;
            default: 
                puts("Invalid choice");
                break;
        }
        printf("%s","...\n" "Insersci una scelta: ");
        scanf("%d", &choice);
    }
}

int isEmpty(lNodePtr lPtr){
    return lPtr==NULL;
}
void printList(lNodePtr lPtr){
    if(isEmpty(lPtr))
        printf("%s", "La lista e' vuota\n");
    else{
        printf("La lista e':\n");
        while(lPtr!=NULL){
            printf("%s->",lPtr->data);
            lPtr= lPtr->nextPtr;
        }
    }
    puts("NULL\n");
}

void insert(lNodePtr *lPtr, char *newData){
    lNodePtr newNode= malloc(sizeof(lNode));

    if(newNode==NULL)
        printf("La stringa %s non e' stata aggiunta, memoria insufficente", newData );
    else{
        newNode->data= strdup(newData);
        newNode->nextPtr= NULL;

        lNodePtr prevNode=NULL;
        lNodePtr currentNode=*lPtr;

        while(currentNode!=NULL && strcmp(newData,currentNode->data)>0){
            prevNode=currentNode;
            currentNode= currentNode->nextPtr;
        }
        if(prevNode==NULL){
            newNode->nextPtr=*lPtr;
            *lPtr=newNode;
        }
        else{
            prevNode->nextPtr=newNode;
            newNode->nextPtr=currentNode;
        }
    }
}

bool delete(lNodePtr *lPtr, char *delData){
    lNodePtr tempNode= *lPtr;
    
    if(strcmp(delData,tempNode->data)==0){
        *lPtr= tempNode->nextPtr;
        free(tempNode);
    }
    else{
        lNodePtr prevNode = tempNode;
        lNodePtr currentNode = tempNode->nextPtr;

        while(currentNode!=NULL && (strcmp(delData,currentNode->data)>0 || strcmp(delData,currentNode->data)<0 )){
            prevNode=currentNode;
            currentNode= currentNode->nextPtr;
        }
        if(currentNode!=NULL){
            tempNode= currentNode;
            prevNode->nextPtr= currentNode->nextPtr;
            free(tempNode);
            return 1; 
        }
        else{
            return 0;
        }
    }    
}