#include<stdio.h>
#include<stdlib.h>

typedef struct listNode{
    int data;
    struct listNode *nextPtr;
} ListNode;

typedef ListNode *lNodePtr;

void insert(lNodePtr *sPtr, int newData);
int delete(lNodePtr *sPtr, int delData);
int isEmpty(lNodePtr sPtr);
void printList(lNodePtr currentNode);
void instructions(void);

int main(){
    puts(">Avvio del menu...");
    instructions();
}
void instructions(void){
    lNodePtr startPtr= NULL;
    int item;
    printf("%s\n","Enter your choice: \n"
    "1 - Insert new element \n"
    "2 - Delete element \n"
    "3 - Print list \n"
    "4 - End program");
    printf("#");
    int choice = 0;
    scanf("%d",&choice);
    while(choice !=4){
        switch(choice){
            case 1:
                printf("%s", "Enter a character: ");
                scanf("%d",&item);
                insert(&startPtr, item);
                printList(startPtr);
                break;
            case 2: 
                if(!isEmpty(startPtr)){
                    printf("Enter character to be deleted: ");
                    scanf("%d",&item);
                    if(delete(&startPtr, item)){
                        printf("%d deleted\n",item);
                        printList(startPtr);
                    }
                    else{
                        printf("%d not found\n", item);
                    }
                }
                else 
                    printf("The list is empty");    
                break;
            case 3:
                printList(startPtr);
            default:
                printf("Invalid choice");
                break;
        }
        printf("%s","#");
        scanf("%d",&choice);
    }
    puts("End of run");
}

void insert(lNodePtr *sPtr, int newData){
    lNodePtr newNode= malloc(sizeof(ListNode));
    
    lNodePtr prevNode= NULL;
    lNodePtr currentNode= *sPtr;

    if (newNode!=NULL){
        newNode->data = newData;
        newNode->nextPtr = NULL;

        while(currentNode != NULL && newData > currentNode->data){
            prevNode= currentNode; 
            currentNode= currentNode->nextPtr;
        }
        
        if(prevNode==NULL){
            newNode->nextPtr = *sPtr;//dato questo funzona anche con prevNode al posto nextPtr?
            *sPtr= newNode;
        }
        else{
            prevNode->nextPtr= newNode;
            newNode->nextPtr= currentNode;
        }
    }
    else
        printf("%d not inserted. Not memory available\n",newData);
}
int delete(lNodePtr *sPtr, int delData){    
    lNodePtr tempNode= *sPtr;
    
    if(tempNode->data==delData){
        *sPtr= tempNode->nextPtr;
        free(tempNode);
    }
    else{
        lNodePtr prevNode=  *sPtr;
        lNodePtr currentNode= (*sPtr)->nextPtr;

        while(currentNode!=NULL && currentNode->data!=delData){
            prevNode = currentNode;
            currentNode= currentNode->nextPtr;
        }

        if(currentNode!=NULL){
            tempNode= currentNode;
            prevNode->nextPtr=currentNode->nextPtr;
            free(tempNode);
            return delData;
        }
        else
            return '\0';
    }
}

int isEmpty(lNodePtr sPtr){
    return sPtr == NULL;
}

void printList(lNodePtr currentNode){
    if(isEmpty(currentNode)){
        puts("The list is empty");
    }
    else{
        puts("The list is: ");

        while(currentNode!=NULL){
            printf("%d->",currentNode->data);
            currentNode= currentNode->nextPtr;
        }
        puts("NULL\n");
    }
}


