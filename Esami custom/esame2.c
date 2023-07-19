#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STRLEN 255

typedef struct parameters{
    char filename1[STRLEN];
    char filename2[STRLEN];
    char filename3[STRLEN];
}Param;
typedef struct record{
    char name[STRLEN];
    int scritto;
    int orale;
}Record;

typedef struct queueNode{
    Record record;
    struct queueNode *nextPtr;
}Node;

typedef Node* NodePtr;

typedef struct headTailNode{
    NodePtr head;
    NodePtr tail;
}Coda;

Param decodeParameters(int argc, char *argv[]){
    if(argc!=4){
        fprintf(stderr,"Errore, i parametri devono essere 3");
        exit(-1);
    }
    Param p;
    strcpy(p.filename1,argv[1]);
    strcpy(p.filename2,argv[2]);
    strcpy(p.filename3,argv[3]);
    if(strcmp(strrchr(p.filename1,'.'),".txt")!=0 || strcmp(strrchr(p.filename2,'.'),".txt")!=0 || strcmp(strrchr(p.filename3,'.'),".txt")!=0){
        fprintf(stderr,"Errore i file devono avere estensione .txt");
        exit(-1);
    }
    return p;
}
void printRecords(Record r){
    printf("%s:%d:%d\n", r.name, r.scritto, r.orale);
}
void printQueue(NodePtr head){
    NodePtr current= head;
    while(current!=NULL){
        Record r= current->record;
        printRecords(r);
        current= current->nextPtr;
    }
}
void enqueue(NodePtr *head, NodePtr *tail, Record r){
    NodePtr newNode = malloc(sizeof(Node));
    if(newNode==NULL){
        fprintf(stderr,"Errore di allocazione nodo");
        exit(-1);
    }
    newNode->record=r;
    newNode->nextPtr=NULL;
    if(*head==NULL){
        *head=newNode;
    }else{
        (*tail)->nextPtr=newNode;
    }
    *tail=newNode;
}
void readFile(NodePtr *hide, NodePtr *tail, char filename[]){
    FILE* f=NULL;
    if((f=fopen(filename,"r"))==NULL){
        fprintf(stderr,"Errore apertura file");
        exit(-1);
    }
    while(!feof(f)){
        Record r;
        char row[STRLEN];
        fscanf(f,"%s\n",row);
        strcpy(r.name,strtok(row,":"));
        r.scritto=atoi(strtok(NULL,":"));
        r.orale=atoi(strtok(NULL,"\n"));
        enqueue(hide, tail, r);
    }
}
void dequeue(NodePtr *head, NodePtr *tail, Coda *c){
    NodePtr tmp= *head;
    if(tmp==NULL){
        fprintf(stderr,"La coda è vuota");
        *tail=NULL;
    }
    else{
        Record r= tmp->record;
        *head=tmp->nextPtr;
        float avg=(r.scritto+r.orale)/2;
        if(avg>=18.00){
            enqueue(&(c->head), &(c->tail), r);
        }
        free(tmp);
    }
}
Coda trimCoda(NodePtr *head, NodePtr *tail){
    Coda c;
    c.head = NULL;
    c.tail = NULL;
    NodePtr current=*head;
    while(current!=NULL){
        dequeue(head, tail, &c);
        current=current->nextPtr;
    }    return c;
}
void saveQueue(Coda c, char filename[]){
    FILE* f=NULL;
    if((f=fopen(filename,"w"))==NULL){
        fprintf(stderr,"Errore aprtura file");
        exit(-1);
    }
    else{
        NodePtr current=c.head;
        while(current!=NULL){   
            Record r=current->record;
            fprintf(f,"%s:%d:%d\n", r.name, r.scritto, r.orale);
            current=current->nextPtr;
        }

    }
}
int main(int argc, char* argv[]){
    Param p= decodeParameters(argc, argv);
    printf("\n PUNTO 1 \n %s - %s - %s\n", p.filename1, p.filename2, p.filename3);
    NodePtr headCAE=NULL;
    NodePtr tailCAE=NULL;
    NodePtr headCFN= NULL;
    NodePtr tailCFN= NULL;
    NodePtr headCOZ=NULL;
    NodePtr tailCOZ=NULL;
    readFile(&headCAE, &tailCAE , p.filename1);
    readFile(&headCFN, &tailCFN , p.filename2);
    readFile(&headCOZ, &tailCOZ , p.filename3);
    printf("\nPUNTO 2\n");
    printf("\nCAE \n");
    printQueue(headCAE);
    printf("\nCFN \n");
    printQueue(headCFN);
    printf("\nCOZ \n");
    printQueue(headCOZ);
    printf("\nPUNTO 3\n");
    Coda CAE=trimCoda(&headCAE, &tailCAE);
    Coda CFN=trimCoda(&headCFN, &tailCFN);
    Coda COZ=trimCoda(&headCOZ, &tailCOZ);
    printf("\ntrimCAE\n\n");
    printQueue(CAE.head);
    printf("\ntrimCFN\n\n");
    printQueue(CFN.head);
    printf("\ntrimCOZ \n\n");
    printQueue(COZ.head);
    saveQueue(CAE,"AEout.txt");
    saveQueue(CFN,"FNout.txt");
    saveQueue(COZ,"OZout.txt");
} 