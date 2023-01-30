#include<stdio.h>
#include<stdlib.h>

typedef struct queueNode{
    char data;//il campo dati è un char
    struct queueNode *nextPtr;//puntatore a queueNode
}QueueNode;

typedef QueueNode *QueueNodePtr;
//prototipi di funzioni 
void printQueue(QueueNodePtr currentPtr);
int isEmpty(QueueNodePtr headPtr);
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value);
char denqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
void instructions(void);

int main(){
    puts(">Avvio del menu...");
    instructions();     
}
void instructions(){
    QueueNodePtr headPtr = NULL;
    QueueNodePtr tailPtr = NULL;
    char item='\0';
    
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
            printf("%s","Enter a character: ");
            scanf("\n%c",&item);
            enqueue(&headPtr, &tailPtr, item);
            printQueue(headPtr);
            break;
        case 2:
            if (!isEmpty(headPtr)){
                item = denqueue(&headPtr, &tailPtr);
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
        printf("%s","#");
        scanf("%d",&choice);
    }
    puts("End of run");
}
//*ENQUEUE_________________________________________________________________/
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value){
    QueueNodePtr newPtr= malloc(sizeof(QueueNode));

    if (newPtr!=NULL){//salva i dati e inizializza il puntatore del nuovo nodo a NULL 
        newPtr->data= value;
        newPtr->nextPtr= NULL;
        //se la coda è vuota, inserisci il primo nodo in testa
        if (isEmpty(*headPtr)){
            *headPtr = newPtr;//******/al primo puntatore inserito assegna il primo nodo inserito
        }
        else{//dal secondo nodo in poi...
            (*tailPtr)->nextPtr= newPtr;//*******/assegna al puntatore di coda (cioè il puntatore dell'ultimo nodo) il nuovo nodo
        }
        *tailPtr=newPtr;//******/aggiorna il puntatore di coda spostandolo al nuovo nodo che è diventato l'ultimo nodo
    }
    else{
        printf("%c not inserted. No memory available\n", value);
    }   
}    
//*****************************************************************/
//*DEQUEUE_______________________________________________________________/
char denqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr){
    char value = (*headPtr)->data;//***salva il dato del primo noda in coda che sta in testa***/
    QueueNodePtr tempPtr= *headPtr;//salva in nodo per deallocarlo succesivamente/
    *headPtr= (*headPtr)->nextPtr;//***sposta il puntatore di testa al nodo successivo cioè quello puntato da nextPtr***/
    //se la coda è vuota
    if (*headPtr == NULL){
        *tailPtr=NULL;//inizializza a null il puntatore di coda***/
    }
    free(tempPtr);//libera la memoria allocata
    return value;//*ritorna il valore 
}
void printQueue(QueueNodePtr currentPtr){
    if(currentPtr== NULL){
        puts("Queue is empty\n");
    }
    else{
        puts("The queue is: ");   
        while (currentPtr !=NULL){//finchè non arriva alla fine della coda
            printf("%c-> ", currentPtr->data);//stampa il dato del nodo corrente a partire dalla testa
            currentPtr=currentPtr->nextPtr;//va al nodo succesivo 
        }
        puts("NULL\n");        
    }
    
}
int isEmpty(QueueNodePtr headPtr){
    return headPtr == NULL;//ritorna 1 se la coda è vuota(quindi la testa della coda), altrimenti ritorna 0
}