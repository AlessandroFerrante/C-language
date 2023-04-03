#include<stdio.h>
#include<stdlib.h>

//struttura autoreferenziale
typedef struct stackNode{
    int* data;
    struct stackNode *nextPtr;
} StackNode;

typedef StackNode *StackNodePtr;

//prototipi
void push(StackNodePtr *topPtr, int info);
int pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);
void instructions(void);

int main(){
    puts(">Start menu...");
    instructions();
}
void instructions(){
    StackNodePtr stackPtr=NULL;
    int value=0;//value int inserito dall'utente

    puts("Enter your choice: \n"
    "1 - To push a value on the stack \n"
    "2 - To pop a value off the stack \n"
    "3 - To print stack \n"
    "4 - To end program");
    printf("%s","#");
    int choice=0;
    scanf("%d",&choice);

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
//*PUSH__________________________________________
void push(StackNodePtr *topPtr, int info){
    StackNodePtr newPtr= malloc(sizeof(StackNode));

    //inserisci il nodo in cima alla pila
    if(newPtr != NULL){
        (*newPtr).data= (int*)info;//inserisce i dati nel nuovo nodo//operatore di cast necessario perchè data è un'itero di tipo puntatore e info è un'intero
        newPtr->nextPtr= *topPtr;//assegna il nodo puntato al primo puntatore ad ogni nuovo nodo//il puntatore *topPtr è il primo in cima alla pila// se è il primo verrà fatto puntare a NULL
        *topPtr = newPtr;//il primo puntatore (*topPtr)  adesso punta al nuovo nodo
    }
    else{
        printf("%d not inserted. No memory available\n", info);
    }

}
//* __________________________________________PUSH
//***********************************************
//*POP___________________________________________
int pop(StackNodePtr *topPtr){
    StackNodePtr tempPtr= *topPtr;

    int popValue= (int) topPtr->data;//memorizza il valore in cima //operatore di cast necessario perchè data è un'itero di tipo puntatore e pop è unt'intero

    *topPtr= (*topPtr)->nextPtr;//prendi il puntatore del nodo in cima(puntato infatti da topPtr) e assegalo a topPtr così puntaterà al secondo nodo che di conseguenza diventerà il primo
    free(tempPtr);//libera la memoria allocata dal nodo precedentemente in cima
    return popValue;//ritorna il valore in cima
}
//* ___________________________________________POP
//***********************************************/
int isEmpty(StackNodePtr topPtr){
    return topPtr == NULL;//restituisce 1 se la pila è vuota, altrimenti 0
}
//*PRINT__________________________________________
void printStack(StackNodePtr currentPtr){
    if(currentPtr == NULL){
        puts("The stack is empty\n");
    }
    else{
        puts("The stack is");
        //finchè non si raggiunge la fine della pila
        while (currentPtr != NULL){
            printf("%d->", currentPtr->data);
            currentPtr=currentPtr->nextPtr;
        }
        puts("NULL\n"); //collegamento per l'ultimo valore nella pila       
    }
}
