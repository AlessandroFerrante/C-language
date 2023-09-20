#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct param{
    int n;
    char filename[255];
}Param;

typedef struct records{
    char name[255];
    int scritto;
    int orale;
}Records;

typedef struct nodeList{
    Records record;
    struct nodeList *nextPtr;
}Node;

typedef Node* NodePtr;

Param decodeParameteres(int argc, char * argv[]){
    if(argc!=2){
        fprintf(stderr,"Errore inserire un parametro");
        exit(-1);
    }
    Param p;
    strcpy(p.filename, argv[1]);
    if(strcmp(strrchr(p.filename, '.'),".txt")!=0){
        fprintf(stderr,"Errore inserire un file con estensione txt");
        exit(-1);
    }
    return p;
}
float getAvg(int scritto, int orale){
    float sum= (float)(scritto+orale);
    float avg= sum/2.0;
    return avg;
}
void ListInsert(NodePtr *list, Records r){
    NodePtr newNode= malloc(sizeof(Node));
    if(newNode==NULL){
        fprintf(stderr,"nodo non allocato");
        exit(-1);
    }
    else{
        newNode->record=r;
        newNode->nextPtr=NULL;
        NodePtr current= *list;
        NodePtr prev=NULL;
        float avg=getAvg(r.scritto, r.orale);
        while(current!=NULL && avg>getAvg(current->record.scritto, current->record.orale)){
                prev=current;
                current=current->nextPtr;
            }
        if(prev==NULL){
            newNode->nextPtr=*list;
            *list=newNode;
        }
        else{
            prev->nextPtr=newNode;
            newNode->nextPtr=current;
        }
    }
}
NodePtr readInputs(char filename[]){
    FILE* f=NULL;
    if((f=fopen(filename, "r"))==NULL){
        fprintf(stderr,"Errore apertura file");
        exit(1);
    }
    NodePtr list=NULL;
    while(!feof(f)){
        Records r;
        char record[255];
        fscanf(f,"%s\n",record);
        strcpy(r.name,strtok(record,":"));
        r.scritto=atoi(strtok(NULL,":"));
        r.orale=atoi(strtok(NULL,"\n"));
        ListInsert(&list ,r);
    }
    fclose(f);
    return list;
}
int main(int argc, char * argv[]){
    Param p=decodeParameteres(argc, argv);
    NodePtr list= readInputs(p.filename);
    //printlist(list);
}