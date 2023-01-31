//per avviare ./SimulazioneEsame.exe n
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct riga{
    char word[100];
    int count;
}Riga;
typedef Riga *RigaPtr;
typedef struct node{
    Riga data;
    struct node *nextPtr;
}Node;

typedef Node *NodePtr;

//prototipi 
int readN(int argc, char *argv[]);
NodePtr readFile(char *nameFile);//funzione che ritorna un puntatore (alla struct Node)
void filterList(NodePtr *head, int n);
void printList(NodePtr head);
bool insertHead(NodePtr *head, Riga r);
bool insertTail(NodePtr *head, Riga r);
bool insertWords(NodePtr *head, Riga r);
bool deleteHead(NodePtr *head);

//****************************
int main(int argc, char *argv[]){
    int n= readN(argc, argv);
    NodePtr head
    = malloc(sizeof(Node));
    head = readFile("input.txt");
    filterList(&head,n);
    printList(head);
    return 0;
}
//****************************
int readN(int argc, char *argv[]) {
    if(argc!=2){
        fprintf(stderr,"Errore, bisogna passare un parametro intero dalla riga di comando\n");
    }
    char *end= malloc(sizeof(char*));;//puntatore (che alloca per nuovi caratteri) usato per la  conversione a intero// serve per puntare ai successivi caratteri che non possono essere convertiti
    int n= strtol(argv[1], &end, 0);//converte il carattere trovato nella posizione [1] , memorizza nel puntatore end dove termina conversione, il terzo parametro è la base di conversione
    if (!end || n < 0)    {
        fprintf(stderr, "Errore, il parametro passato deve essere intero positivo.\n");
        exit(-1);
    }
    return n;
}  

NodePtr readFile(char *nameFile){
    NodePtr *head= malloc(sizeof(Node));
    *head = NULL;
    FILE *fPtr= fopen(nameFile,"r");
    char row[1000];
    int i=0;
    while (i==0){
        char *out= fgets(row,1000,fPtr);//legge una riga dal file(massimo 999 caratteri) e la memoriazza in row, *out viene usato per ciò che fgets restitusce
        if(out!=NULL){//finchè fgets non restituisce NULL//quindi finchè non terminano le righe da leggere         
            char *token = strtok(row," \n");//suddivide la riga in token fino a \n
            char *firstToken = token;
            int count = 0;
            do{
                if (strcmp(firstToken, token)==0)
                    count++;   
            } while (token = strtok(NULL, " \n"));
            Riga r;//crea un nodo r di tipo Riga
            r.count = count;
            strcpy(r.word, firstToken);//copia la prima parola nel nodo
            insertWords(head, r);//inserisci nella lista 
        } else {
            i++;
        }
    }
    
    return *head;
}


bool insertTail(NodePtr *head, Riga r){
    if(*head==NULL)
        return insertHead(head, r);

    //trova l'ultimo nodo della lista
    NodePtr tail = *head;//assegna il nodo a tail
    //scorri finchè non trovi l'ultimo nodo cioè fino a quando il puntatore srà NULL
    while (tail->nextPtr){//mentre il punatore di tail punta 
        tail= tail->nextPtr;//metti tail uguale a ciò che punta il puntatore
    }
    
    NodePtr newNode= malloc(sizeof(Node));
    if(newNode==NULL)
        return false;
    newNode->data= r;
    newNode->nextPtr= NULL;
    tail->nextPtr= newNode; 
    return true;
}

bool insertHead(NodePtr *head, Riga r){
    NodePtr newNode= malloc(sizeof(Node));
    if(newNode==NULL)
        return false;
    newNode->data= r;//nel nodo memorizza il dato = r
    newNode->nextPtr= *head;
    *head = newNode; 
    return true;
}

bool insertWords(NodePtr *head, Riga r){
    if(*head==NULL){
        NodePtr newNode=malloc(sizeof(Node));
        newNode->data=r;
        newNode->nextPtr= *head;
        *head=newNode;
        return true;
    }
    else{
        NodePtr tail=*head;
        while (tail->nextPtr){
            tail=tail->nextPtr;
        }
        NodePtr newNode=malloc(sizeof(Node));
        if(newNode==NULL)
            return false;
        newNode->data=r;
        newNode->nextPtr=NULL;
        tail->nextPtr=newNode;
        return true;
    }
}
void filterList(NodePtr *head, int n){
    NodePtr filter= *head;
    NodePtr prev=NULL;
    while(filter){
        RigaPtr r= &filter->data;
        if (r->count<n){
            if(prev==NULL){
                deleteHead(head);
                filter=*head;
                continue;
            }
            else{
                NodePtr temp= filter;
                prev->nextPtr= filter->nextPtr;
                free(temp);
                filter=prev;
            }
        }
        prev=filter;
        filter= filter->nextPtr;
    } 
}
bool deleteHead(NodePtr *head){
    if(*head){
        NodePtr temp= *head;
        *head= (*head)->nextPtr;
        free(temp);
        return true;
    }else {
        return false;
    }
}
void printList(NodePtr head){
    NodePtr print= head;
    while (print){
        RigaPtr r= &print->data;
        printf("%s %d\n",r->word,r->count);
        print= print->nextPtr;
    }
}