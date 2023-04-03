#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode{
    int *data;
    struct stackNode *nextPtr;
}StackNode;

typedef StackNode* StackNodePtr;

//prototipi
void push(StackNodePtr *topPtr, int newData);
int pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);
void instructions(void);

int main(){
    puts(">Avvio menu...");
    instructions();

}
void instructions(){
    StackNodePtr stackPtr=NULL;
    int value=0;

    puts("Enter your choice: \n"
    "1- To push aq vlaue on the stack \n"
    "2 - to pop a vlaue off the stack \n"
    "3 - to print Stack \n"
    "4 - to end program");
    printf("%s","#");
    int choice=0;
    scanf ("%d", &choice);
    
    while (choice!=4){
        switch (choice){
        case 1:// effettua un push di un valore nella pila
            printf("%s","Enter an integer: ");
            scanf("%d",&value);
            push(&stackPtr, value);
            printStack(stackPtr);
            break;
        case 2://effettua un pop di un valore dalla pila
            //se la pila non è vuota
            if (!isEmpty(stackPtr)){
                printf("The popped value is %d\n", pop(&stackPtr));//stackPtr è la nostra pila che viene passata per riferimento 
            }
            printStack(stackPtr);
            break;
        case 3:
            printStack(stackPtr);
            break;
        default:
            puts("Invalid choice");
            break;
        }
        printf("%s","#");
        scanf("%d",&choice);
    }
    puts("End of run");
}
int isEmpty(StackNodePtr topPtr){
    return topPtr == NULL;//come se ci fosse un controllo con un if della pila, restituisce, 1 vuota, 0 che non è vuota
}
void printStack(StackNodePtr currentNode){
    if(currentNode==NULL){
        puts("The stack is empty\n");
    }
    else{
        puts("The stack is: ");
        while(currentNode != NULL){
            printf("%d->", currentNode->data);
            currentNode= currentNode->nextPtr;
        }
        puts("NULL\n");
    }
}
void push (StackNodePtr *topPtr, int newData){
    StackNodePtr newNode= malloc(sizeof(StackNode));
    if (newNode != NULL){
        newNode->data = (int*) newData;
        newNode->nextPtr= *topPtr;
        *topPtr= newNode;
    }
    else{
        printf("%d not inserted. No meory avaible\n", newData);
    }
}
int pop(StackNodePtr *topPtr){
    StackNodePtr tempNode=*topPtr;
    int popValue= (int) tempNode->data;
    *topPtr= tempNode->nextPtr;
    free(tempNode);
    return popValue;
}