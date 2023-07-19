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

typedef  struct listNode{
    Record record;
    struct listNode *nextPtr;
}Node;
typedef Node* NodePtr;

Param decodeParameters(int argc, char * argv[]){
    if(argc!=4){
        fprintf(stderr, "Errore, inserire tre paramteri");
        exit(-1);
    }
    else{
        Param p;
        strcpy(p.filename1,argv[1]);
        strcpy(p.filename2,argv[2]);
        strcpy(p.filename3,argv[3]);

        if(strcmp(strrchr(p.filename1,'.'),".txt")!=0 || strcmp(strrchr(p.filename2,'.'),".txt")!=0 || strcmp(strrchr(p.filename3,'.'),".txt")!=0){
            fprintf(stderr,"Erorre, i file devono avere estensione .txt");
            exit(-1);
        }
            return p;
    }

}
void printRecord(Record r){
    printf("%s:%d:%d\n",r.name, r.scritto, r.orale);
}
void printList(NodePtr list){
    NodePtr current= list;
    while(current!=NULL){
        Record r=current->record;
        printRecord(r);
        current=current->nextPtr;
    }
}
void insertList(NodePtr *list, Record r){
    NodePtr newNode= malloc(sizeof(Node));
    if(newNode==NULL){
        fprintf(stderr,"Errore, memoria insufficente");
        exit(-1);
    }
    newNode->record=r;
    newNode->nextPtr=NULL;
    NodePtr current=*list;
    if(*list==NULL){
        *list=newNode;
    }
    else{
        while(current->nextPtr!=NULL){
            
            current=current->nextPtr;
        }
        current->nextPtr=newNode;
    }
}
NodePtr readFile (char filename[]){
    FILE* f=NULL;
    if((f=fopen(filename,"r"))==NULL){
        fprintf(stderr, "Errore, file non aperto");
        exit(-1);
    }
    else {
        NodePtr list=NULL;
        while(!feof(f)){
            Record r;
            char row[STRLEN];
            fscanf(f,"%s\n",row);
            strcpy(r.name,strtok(row,":"));
            r.scritto=atoi(strtok(NULL,":"));
            r.orale=atoi(strtok(NULL,"\n"));
            insertList(&list, r);
        }
        return list;
    }
}
NodePtr linkMultipleList(NodePtr listAE, NodePtr listFN, NodePtr listOZ){
    NodePtr list=NULL;

    NodePtr current=listAE;
    while(current!=NULL){
        Record r=current->record;
        insertList(&list, r);
        current=current->nextPtr;
    }
    current=listFN;
    while(current!=NULL){
        Record r=current->record;
        insertList(&list, r);
        current=current->nextPtr;
    }
    current=listOZ;
    while(current!=NULL){
        Record r=current->record;
        insertList(&list, r);
        current=current->nextPtr;
    }
    return list;
}
void saveList(NodePtr list){
    FILE* f=NULL;
    if((f=fopen("candidati.txt","w"))==NULL){
        fprintf(stderr,"Errore apertura file");
        exit(-1);
    }
    while(list!=NULL){
        Record r = list->record;
        fprintf(f,"%s:%d:%d\n",r.name,r.scritto, r.orale);
        list=list->nextPtr;
    }
    fclose(f);
}
int main (int argc, char* argv[]){
    Param p= decodeParameters(argc, argv);
    NodePtr listAE= readFile(p.filename1);
    NodePtr listFN= readFile(p.filename2);
    NodePtr listOZ= readFile(p.filename3);
    printf("\nPUNTO2");
    printf("\n\nlistAE\n");
    printList(listAE);
    printf("\n\nlistFN\n");
    printList(listFN);
    printf("\n\nlistOZ\n");
    printList(listOZ);
    printf("\nPUNTO3");
    NodePtr list= linkMultipleList(listAE, listFN, listOZ);
    printf("\n\nlist\n");
    printList(list);
    saveList(list);
}