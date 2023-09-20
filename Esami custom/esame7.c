#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct record{
    int numero;
    char name[255];
    char cognome[255];
    double saldo;
}Record; 

typedef struct node{
    Record record;
    struct node * nextPtr;
}Node;

typedef Node* NodePtr;

typedef struct param{
    int n;
    char filename[255];
}Param;

typedef struct coda{
    NodePtr head;
    NodePtr tail;
}Coda;

Param decodeParam(int argc, char * argv[]){
    Param p;
    if(argc!=3){
        fprintf(stderr,"Errore inserire 2 parametri");
        exit(1);
    }
    char *end;
    p.n= strtol(argv[1], &end, 10);
    if(*end){
        fprintf(stderr,"Errore, il primo parametro deve essere un intero");
        exit(1);
    }
    if(p.n<4 || p.n>8){
        fprintf(stderr, "Errore l'intero inserito deve essere compreso tra 4 e 8");
        exit(1);
    }
    strcpy(p.filename, argv[2]);
    if(strcmp(strrchr(p.filename, '.'),".txt")!=0){
        fprintf(stderr, "Errore il file deve avere estensione .bin");
        exit(1);
    }
    return p;
}
Record* readFile(int n, char filename[]){
    FILE *fPtr=NULL;
    Record *r= malloc(sizeof(Record)*n);

    if((fPtr=fopen(filename,"r+"))==NULL){
        fprintf(stderr,"Errore, file non aperto");
        exit(1);
    }
    char row[255];
    for(int i =0; i < n; i++){
        fscanf(fPtr,"%s\n", row);
        r[i].numero= atoi(strtok(row, ":"));
        strcpy(r[i].name, strtok(NULL, ":"));
        strcpy(r[i].cognome, strtok(NULL, ":"));
        r[i].saldo= atof(strtok(NULL, "\n"));
    }
    return r;
}
void printRecord(Record* r, int n){
    for(int i =0; i< n; i++){
        printf("%d %s %s %.3lf\n", r[i].numero, r[i].name, r[i].cognome, r[i].saldo);
    }
}
void insert(NodePtr *list, Record* r, int n){
    for(int i=0; i<n; i++){
        NodePtr newNode= malloc(sizeof(Node));

        if(newNode==NULL){
            perror("Errore nell'allocazione di memoria");
            exit(1);
        }
        newNode->record= r[i];
        newNode->nextPtr=NULL;

        if(*list==NULL){
            *list=newNode;
        }
        else{
            NodePtr current= *list;
            while(current->nextPtr!=NULL){
                current= current->nextPtr;
            }
            current->nextPtr=newNode;
        }
    }
}
void insertOrder(NodePtr *list, Record* r, int n){
    for(int i=0; i< n; i++){
        NodePtr newNode= malloc(sizeof(Node));
        
        if(newNode==NULL){
            perror("Errore nell'alocaznione di memoria");
            exit(1);
        }
        newNode->record=r[i];
        newNode->nextPtr=NULL;

        NodePtr current= *list;
        NodePtr prev= NULL;

        while(current!=NULL && r[i].saldo > current->record.saldo){
            prev= current;
            current= current->nextPtr;
        }
        if(prev==NULL){
            newNode->nextPtr= *list;
            *list=newNode;
        }
        else{
            prev->nextPtr= newNode;
            newNode->nextPtr= current;
        }
    }
}
void printRecords(Record r){
    printf("%d %s %s %.3lf\n", r.numero, r.name, r.cognome, r.saldo);
}
void printNode(NodePtr N){
    printf("%s\n",">>>>>--Struttura dati--<<<<<<");
    if(N==NULL){
        fprintf(stderr, ">>>>>--Struttura dati vuota--<<<<<<\n ");
    }
    NodePtr current = N;
    while(current!=NULL){
        Record r = current->record;
        printRecords(r);
        current=  current->nextPtr;
    }
}
void push(NodePtr *stack, Record *r, int n){
    for(int i =0; i<n ; i++){
        NodePtr newNode= malloc(sizeof(Node));

        if(newNode==NULL){
            fprintf(stderr,"Errore allocazione memoria");
            exit(1);
        }
        else{
            newNode->record= r[i];
            newNode->nextPtr=  *stack;
            *stack=newNode;
        }
    }
}
void pop(NodePtr *stack, Record* r, int n){
    for(int i=0; i < n ; i++){
        NodePtr tempNode= *stack;
        Record rec= r[i];
        *stack= tempNode->nextPtr;

        free(tempNode);
        printRecords(rec);
    }
}
void enqueue(NodePtr *head, NodePtr *tail, Record* r, int n){
    for(int i =0; i < n; i++){
        NodePtr newNode= malloc(sizeof(Node));

        if(newNode==NULL){
            fprintf(stderr, "Errore, memoria non allocata");
            exit(1);
        }
        else{
            newNode->record= r[i];
            newNode->nextPtr= NULL;
            if(*head==NULL){
                *head= newNode;
            }
            else{
                (*tail)->nextPtr=newNode;
            }
            *tail=newNode;
        }
    }
}
void denqueue(NodePtr *head, NodePtr *tail, Record* r, int n){
    for(int i=0; i<n ; i++){
        NodePtr tempNode= *head;
        Record rec;
        if(tempNode==NULL){
            fprintf(stderr,"La coda è vuota");
            *tail= NULL;
        }
        else{
             rec= r[i];
             *head= tempNode->nextPtr;
        }
        free(tempNode);
        printRecords(rec);
    }
}
void writeFile(Record *r, int n){
    FILE *fPtr=NULL;
    if((fPtr=fopen("file.bin", "wb+"))==NULL){
        fprintf(stderr, "Errore apertura file");
        exit(1);
    } 
    for(int i=0; i<n ; i++){
        fprintf(fPtr, "%d %s %s %lf\n", r[i].numero, r[i].name, r[i].cognome, r[i].saldo );
    }  
    fclose(fPtr);
}
void saveList(NodePtr *list){
    FILE *fPtr=NULL;
    if((fPtr=fopen("file.bin", "ab+"))==NULL){
        fprintf(stderr, "Errore apertura file");
        exit(1);
    }
    NodePtr current= *list;
    Record rec;
    fprintf(fPtr, "%s\n", "LISTA");
    while(current!=NULL){
        rec=current->record;
        fprintf(fPtr,"%d %s %s %.3lf\n", rec.numero, rec.name, rec.cognome, rec.saldo );
        current= current->nextPtr;
    }
    fclose(fPtr);
}
void saveStack(NodePtr *stack){
    FILE *fPtr=NULL;
    if((fPtr=fopen("file.bin", "ab+"))==NULL){
        fprintf(stderr,"Errore apertura file");
        exit(1);
    }
    NodePtr current= *stack;
    Record rec;
    fprintf(fPtr, "%s\n", "STACK");
    while(current!=NULL){
        rec= current->record;
        fprintf(fPtr,"%d %s %s %.3lf\n", rec.numero, rec.name, rec.cognome, rec.saldo );
        current= current->nextPtr;
    }
    fclose(fPtr);
}
void saveQueue(Coda c){
    FILE *fPtr=NULL;
    if((fPtr=fopen("file.bin", "ab+"))==NULL){
        fprintf(stderr,"Errore apertura file");
        exit(1);
    }
    NodePtr current = c.head;
    Record rec;
    fprintf(fPtr, "%s\n", "QUEUE");
    while(current!=NULL){
        rec= current->record;
        fprintf(fPtr,"%d %s %s %lf\n", rec.numero, rec.name, rec.cognome, rec.saldo);
        current= current->nextPtr;
    }
    fclose(fPtr);
}
int main(int argc, char * argv[]){
    Param p=  decodeParam(argc, argv);
    Record *r= readFile(p.n, p.filename);
    printRecord(r, p.n);

    NodePtr list = NULL;
    insert(&list, r, p.n);
    printNode(list);
    NodePtr list2 = NULL;
    insertOrder(&list2, r, p.n);
    puts("Lista 2 ordinata");
    printNode(list2);
    
    puts("Pila");
    NodePtr stack= NULL;
    push(&stack, r, p.n);
    printNode(stack);
    puts("pop");
    //pop(&stack, r,  p.n);
    printNode(stack);
    
    puts("Coda");
    NodePtr head = NULL;
    NodePtr tail = NULL;
    enqueue(&head, &tail, r, p.n);
    printNode(head);
    puts("denqueue");
    //denqueue(&head, &tail, r, p.n);
    writeFile(r, p.n);
    saveList(&list);
    saveStack(&stack);
    Coda c;
    c.head= head;
    c.tail= tail;
    saveQueue(c);
}