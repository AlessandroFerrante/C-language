//Lista collegata
//inserimento e cancellazione di nodi in una lista, stampa della lista
//nel file è apportata qualche modifica per rendere più semplice una possibile chiamata di una funzione da un altro file
#include<stdio.h>
#include<stdlib.h>

typedef struct listNode{
    char data;
    struct listNode *nextPtr;
}ListNode;

typedef ListNode *ListNodePtr;

void insert(ListNodePtr *sPtr, char value);//passo l'indirizzo del puntatore per creare un puntatore a puntatore
char delete(ListNodePtr *sPtr, char value);
int isEmpty(ListNodePtr sptr);
void printList(ListNodePtr currentPtr);
void instructions (void);

int main(){    
    puts("#> Avvio del menu...");
    instructions();//chiamata al menu di scelta
}

// menu di scelta
void instructions(){
    ListNodePtr startPtr = NULL;//ListNodePtr rappresenta un puntatore a ListNode cioè all'oggetto struct listNode//ListNodePtr è un puntatore di tipo ListNode
    //QUINDI IN QUESTO MODO CREA UN PUNTATORE A PUNTATORE DOVE QUEST'ULTMO PUNTA AL NUOVO NODO DEL TIPO DEL PRIMO PUNTAOTRE 
    //IN QUESTO CASO  un puntatore che punta a un'oggetto DI TIPO struct listNode// IN SOSTANZA CREA UN  NODO VUOTO
    char item ='\0';
    printf("%s\n","Enter your choice: \n"//viene scritto tutto attraverso solo un %s è scritto così solo per l'intentazione
    "1 - Insert new element \n"
    "2 - Delete element \n"
    "3 - Print list \n"
    "4 - End program");
    printf("#");
    int choice =0;
    scanf("%d",&choice);
    while (choice!=4){
        switch (choice){
        case 1://inserisci un elemento
            printf("%s","Enter a character: ");       
            scanf("\n%c",&item);     
            insert(&startPtr, item);
            printList(startPtr);
            break;
        case 2://elimina un elemento
            if (!isEmpty(startPtr)){
                printf("Enter character to be deleted: ");
                scanf("\n%c", &item);

                if (delete(&startPtr, item)){//passa l'indirizzo del puntatore iniziale il quale punta al primo nodo se esiste 
                    printf("%c deleted\n",item);
                    printList(startPtr);
                }
                else{
                    printf("%c not found",item);
                }
            }
            else{
            printf("The list is empty\n");
            }
            break;
        case 3:
              printList(startPtr);
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
//inserimento nodo nella lista
void insert(ListNodePtr *sPtr, char value){//prende l'indirizzo del puntatore e il nuovo valore//puntatore passato per riferimento che crea un puntatore a puntatore
    ListNodePtr newPtr= malloc(sizeof(ListNode));//crea il nuovo nodo con le dimensioni della struct  
    //c'è spazio disponibile?
    if (newPtr!=NULL){//diverso da null perchè se è null vuol dire che malloc non ha potuto allocare il nodo, vedere istruzione sopra 
        //*inizializza nel nuovo nodo char con un valore e il puntatore a NULL  
        newPtr->data=value;//data è il carattere definito nella struct//equivale a (*newPtr).data//_inserisce value nel nodo
        (*newPtr).nextPtr=NULL;//nextPtr è il puntatore definito nella struct// equivale a newPtr->nextPtr=NULL//il nodo quindi non sarà collegato ad altri nodi

        ListNodePtr previousPtr= NULL;//inizializzazione puntatore del nodo precedente
        ListNodePtr currentPtr= *sPtr;// è il puntatore che viene passato alla funzione da instructions() che passa startPtr, indirizzo del primo nodo
        
        while (currentPtr != NULL && value > currentPtr->data){//mentre il puntatore del nodo corrente (passato alla funzione, quindi il primo ,sPtr) non è nullo, e il valore da inserire è maggiore di quello già inserito...
            previousPtr = currentPtr;//va avanti... pone il nodo precedente uguale al nodo corrente
            currentPtr = currentPtr->nextPtr;//... al nodo successivo, assegna a currentePtr il nodo successivo cioè quello puntato dal punatore del nodo corrente//nextPtr è il puntatore definito nella struct
        }
        //inserisci il primo nodo all'inizio della lista
        if (previousPtr == NULL){
            newPtr->nextPtr= *sPtr;//fa puntare il puntatore (nextPtr) del nuovo nodo (newPtr) al primo nodo della lista con il puntatore *sPtr 
            *sPtr= newPtr;//assegna al puntatore sPtr il nodo newPtr che è il nuovo primo nodo
        }
        //inserisci il nuovo nodo tra previousPtr e currentPtr
        else{
            previousPtr->nextPtr=newPtr;//fa puntare il puntatore del nodo precedente al nuovo nodo// uguale a (*previousPtr).nextPtr=newPtr
            newPtr->nextPtr=currentPtr;//fa punatre il puntatore del nuovo nodo al nodo corrente (cioè il succesivo)
        }
    }
    //non c'è spazio disponibile
    else{
        printf("%c not inserted. Not memory available\n",value);
    }   
}

//elimina un elemento della lista
char delete(ListNodePtr *sPtr, char value){
    
    //elimina il primo nodo se viene trovata una corrispondenza...
    if (value == (*sPtr)->data){
        ListNodePtr  tempPtr = *sPtr;//aggancia il nodo da rimuovere in un nodo temporaneo che serve a liberare la memoria allocata 
        *sPtr= (*sPtr)->nextPtr;//assegna il puntatore del nodo da eliminare (il quale punta a un nodo succesivo) al primo puntatore, di fatto assegna a *sPtr il nodo sucessivo
        //da qui in poi il nodo da eliminare esiste ma non è collegato a nessun altro nodo nella lista 
        // sucessivamente però si deve liberare(con free) la memoria in cui è allocato, dunque viene eliminato
        free(tempPtr);//libera il nodo sfilato
        return value;//restituisce il carattere cancellato 
    }
    //se non è il primo nodo...
    else{
        ListNodePtr previousPtr=*sPtr;
        ListNodePtr currentPtr= (*sPtr)->nextPtr;//è uguale a previous->nextPtr e a (*previous).nextPtr

        while (currentPtr!=NULL && currentPtr->data != value){
            previousPtr= currentPtr;//va avanti...
            currentPtr= currentPtr->nextPtr;//... al nodo successivo
        }
        //elimina il nodo a currentPtr
        if (currentPtr!=NULL){
            ListNodePtr tempPtr = currentPtr;//il nodo corrente si salva il un nodo temporaneo che dovrà essere eliminato ma che ancora serve per sganciare i puntatori 
            previousPtr->nextPtr= (*currentPtr).nextPtr;//fa puntare il nodo precedente con il nodo successivo a quello che dobbiamo eliminare, usando i punatori i quali effetivamente puntano ai nodi stessi
            free(tempPtr);//libera il nodo 
            return value;//restituisce il carattere cancellato 
        }
        
    }
    return '\0'; //restituisce un carattere nullo per indicare che non è stato trovato il carattere da eliminare nella lista
}

int isEmpty(ListNodePtr sPtr){
    return sPtr == NULL; // è un predicato per cui non altera la lista//*restituisce 1 se la lista è vuota altrimenti 0
}

void printList(ListNodePtr currentPtr){
    if (isEmpty(currentPtr)){
        //se la lista è vuota
        puts("List is empty\n"); 
    }
    else{
        puts("The list is: ");

        //finchè non raggiunge la fine della lista quindi il nodo NULL scorre tutti i nodi
        while (currentPtr!= NULL){
            printf("%c ->",currentPtr->data);
            //va avanti...
            currentPtr= currentPtr->nextPtr;//pone il nodo corrente da stampare uguale a quello succesivo attraverso il puntatore che punta ad esso
        }
        puts("NULL\n");//scrive NULL perchè l'ultimo nodo ha un puntatore cha non punta a nessun nodo 
    }
}