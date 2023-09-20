#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRLEN 255

typedef struct input {
    char input[STRLEN];
    char output[STRLEN];
}Inputs;

typedef struct record{
    char nome[STRLEN];
    char cognome[STRLEN];
    int numeroConto;
    int annoApertura;
    float saldo;
}Record;

typedef struct lnode{
    Record record;
    struct lnode * nextPtr;
}Node;

typedef Node* NodePtr;

typedef struct {
    NodePtr head;
    NodePtr tail;
}NodePtr2;


Inputs readInput(int argc, char* argv[]){
    if(argc!=3){
        fprintf(stderr,"Inserire il numero di argomenti corretto");
        exit(-1);
    }
    else{
        Inputs p;
        strcpy (p.input, argv[1]);
        strcpy (p.output, argv[2]);
        if(strcmp(strrchr(p.input, '.'),".txt")!=0 || strcmp(strrchr(p.output, '.'),".txt")!=0  ){
            fprintf(stderr,"I file devono avere estensione txt");
            exit(-1); 
        }
        printf("File input: %s\n",p.input);
        printf("File output: %s\n",p.output);
           
        return p;
    }

}
void insertNode(NodePtr *list, Record r){
    NodePtr newNode= malloc(sizeof(Node));
    if(newNode==NULL){
        fprintf(stderr,"Errore memoria insuficente");
        exit(-1);
    }
    else{
        NodePtr current= *list;
        NodePtr prev=NULL;
        newNode->record=r;
        newNode->nextPtr=NULL;
        while(current!=NULL && newNode->record.annoApertura > current->record.annoApertura){
            prev=current;
            current=current->nextPtr;
        }
        if(prev==NULL){
            newNode->nextPtr=*list;
            *list=newNode;
        }
        else{
            prev->nextPtr= newNode;
            newNode->nextPtr=current;
        }
    }
}
NodePtr readFile(char fileInput[]){
    FILE* fPtr=NULL;
    if((fPtr = fopen(fileInput,"r")) == NULL ){
        printf("\nFilename input: %s", fileInput);
        fprintf(stderr,"Errore apertura file");
        exit(-1);
    }    
    else{
        NodePtr list=NULL;
        while(!feof(fPtr)){
            Record r;
            fscanf(fPtr,"%s %s %d %d %f\n",r.nome, r.cognome, &r.numeroConto, &r.annoApertura, &r.saldo);
            printf("%s %s %d %d %.2f\n",r.nome, r.cognome, r.numeroConto, r.annoApertura, r.saldo);
            insertNode(&list, r);
        }
        return list;
    }
}
void push(NodePtr *head, Record r){
    NodePtr newNode= malloc(sizeof(Node));
    if(newNode==NULL){
        fprintf(stderr,"Errore allocazione di memoria");
        exit(-1);
    }
    else{
        newNode->record=r;
        newNode->nextPtr=*head;
        *head=newNode;
    }
}

NodePtr readFile2(char fileInput[]){
    FILE* fPtr=NULL;
    if((fPtr = fopen(fileInput,"r")) == NULL ){
        printf("\nFilename input: %s", fileInput);
        fprintf(stderr,"Errore apertura file");
        exit(-1);
    }    
    else{
        NodePtr stack=NULL;
        while(!feof(fPtr)){
            Record r;
            fscanf(fPtr,"%s %s %d %d %f\n",r.nome, r.cognome, &r.numeroConto, &r.annoApertura, &r.saldo);
            printf("%s %s %d %d %.2f\n",r.nome, r.cognome, r.numeroConto, r.annoApertura, r.saldo);
            push(&stack, r);
        }
        return stack;
    }
}
void enqueue(NodePtr *head, NodePtr *tail, Record r){
    NodePtr newNode = malloc(sizeof(Node));
    if(newNode==NULL){
        fprintf(stderr,"Errore di allocazione nodo coda");
        exit(-1);
    }
    newNode->record=r;
    newNode->nextPtr=NULL;
    if(*head==NULL){
        *head=newNode;
    }
    else{
        (*tail)->nextPtr= newNode;
    }
    *tail=newNode;
}

NodePtr2 readFile3(NodePtr2 node, char filename[]){
    printf("\n\n readFile3 \n\n");
    FILE* fPtr=NULL;
    if((fPtr = fopen(filename,"r")) == NULL ){
        printf("\nFilename input: %s",filename);
        fprintf(stderr,"Errore apertura file");
        exit(-1);
    }    
    else{
        node.head=NULL;
        node.tail=NULL;
        while(!feof(fPtr)){
            Record r;
            fscanf(fPtr,"%s %s %d %d %f\n",r.nome, r.cognome, &r.numeroConto, &r.annoApertura, &r.saldo);
            //printf("%s %s %d %d %.2f\n",r.nome, r.cognome, r.numeroConto, r.annoApertura, r.saldo);
            enqueue(&node.head,&node.tail, r);
        }
        return node;
    }
}
void printRecord(Record r){
    printf("%s %s %d %d %.2f\n",r.nome, r.cognome, r.numeroConto, r.annoApertura, r.saldo);
}
void printList(NodePtr list){
    NodePtr current=list;
    while(current!=NULL){
        printRecord(current->record);
        current=current->nextPtr;
    }
}
float getMax(NodePtr list){
    NodePtr current= list;
    float max= current->record.saldo;
    //char name[255];
    //char lastname[255];
    while(current!=NULL){
        if(max<current->record.saldo){
            max=current->record.saldo;
            //strcpy(name,current->record.nome);
            //strcpy(lastname,current->record.cognome);
        }
        current=current->nextPtr;
    }
    //printf("\n %s %s getMax saldo: %f\n ", name, lastname, max);
    return max;
}
float getMin(float f, float n){
    if(f<n){
        return f;
    }
    return n;
}

void deleteAccounts(NodePtr *list, NodePtr deleteAccount){
    NodePtr current=*list;
    NodePtr prev= NULL;
    while(current!=deleteAccount && current!=NULL){
        prev=current;
        current=current->nextPtr;
    }
    if(current==NULL){
        printf("Il Nodo da eliminare non è presente nella lista");
        return;
    }
    if(prev==NULL){
        *list=current->nextPtr;
    }
    else{
        prev->nextPtr= current->nextPtr;
    }
    free(deleteAccount);
}
void removeAccount(NodePtr list){
    NodePtr current = list;
    float x=0, saldo=0, min=0, m=0;
    int year;
    char name[255];
    char lastname[255];
    float Xmax=0;
    NodePtr deleteAccount = NULL;
    while(current!=NULL){
        saldo=current->record.saldo;
        year=current->record.annoApertura;
        float f= (float)((2023-year)/5);
        min=getMin(f, 1.0);
        m=getMax(list);
        x=min*(saldo/m);
        if(Xmax<x){
            Xmax=x;
            deleteAccount=current; 
        }
       printf("XMAX: %f\n",Xmax);
        current=current->nextPtr;
    }
    deleteAccounts(&list, deleteAccount);
}
int countNode(NodePtr list){
    NodePtr current = list;
    int count=0;
    while(current!=NULL){
        count++;
        current=current->nextPtr;
    }
    printf("COUNT : %d\n",count);
    return count;
}
int getH(int n){
    int h=0;
    h= (int) (n/2);
    return h;
}
void writeFile(NodePtr list, char* output){
    NodePtr current= list;
    FILE* f= NULL;
    if((f=fopen(output, "w"))==NULL){
        fprintf(stderr,"Errore di apertura file %s",output);
        exit(-1);
    }
    Record r;
    while(current!=NULL){
        r=current->record;
        fprintf(f,"%s %s %d %d %f\n", r.nome, r.cognome, r.numeroConto, r.annoApertura, r.saldo);
        current=current->nextPtr;
    }
}
void writeFile2(NodePtr list){
    NodePtr current= list;
    FILE* b=NULL;
    if((b=fopen("b.bin","wb"))==NULL){
        fprintf(stderr,"File binario non aperto");
        exit(-1);
    }
    Record r;
    while(current!=NULL){
        r=current->record;
        fwrite(&r,sizeof(Record), 1, b);//b è il puntatore
        current=current->nextPtr;
    }
}
void pop(NodePtr *head){
    NodePtr tmp= *head;
    Record r;
    
    r=tmp->record;
    *head=tmp->nextPtr;
    
    printf("\nPOP : ");
    printRecord(r);
    
    free(tmp);
}
void denqueue(NodePtr *head, NodePtr *tail){
    if(*head==NULL){
        fprintf(stderr,"La coda è vuota");
        *tail=NULL;
    }
    else{
        NodePtr tmp=*head;
        Record r= tmp->record;
        printRecord(r);
        *head= *head->nextPtr;
        free(tmp);
        if (*head == NULL) {
            *tail = NULL;
        }
    }
}
int main(int argc, char* argv[]){
    Inputs param=readInput(argc, argv);
    NodePtr list=readFile(param.input);
    NodePtr stack=readFile2(param.input);
    printf("\n\nPUNTO B\n");
    printf("LISTA\n");
    printList(list);
    printf("PILA\n");
    printList(stack);
    getMax(list);  
    int n=countNode(list);
    int h= getH(n);
    for(int i=0; i<h; i++){
        removeAccount(list);
    }
    printf("\nPUNTO C\n");
    printList(list);
    writeFile(list,param.output);
    writeFile2(list);
    pop(&stack);
    printf("PILA\n");
    printList(stack);
    pop(&stack);
    printf("PILA\n");
    printList(stack);
    pop(&stack);
    printf("PILA\n");
    printList(stack);
    NodePtr2 node =readFile3(node, param.input);
    printf("CODA\n");
    printList(node.head);
    denqueue(node);
}