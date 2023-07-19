#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STR_LEN 255

typedef struct parameters{
    char filename[STR_LEN];
}Param;

typedef struct record{
    char name[STR_LEN];
    int Vscritto;
    int Vorale;
}Record;

typedef struct listNode{
    Record record;
    struct listNode *nextPtr;
}Node;

typedef Node* NodePtr;


Param decodeParamaters(int argc, char* argv[]){
    if(argc!=2){
        fprintf(stderr, "Inserire solo un parametro");
        exit(1);
    }
    Param p;
    strcpy(p.filename,argv[1]);
    if(strcmp(strrchr(p.filename, '.'),".txt")!=0){
        fprintf(stderr,"Il file deve avere estensione .txt");
        exit(1);
    }
    return p;
}
void ListInsert(NodePtr *list, Record r){
    NodePtr newNode= malloc(sizeof(Node));

    if(newNode==NULL){
        fprintf(stderr, "Errore allocazione nodo lista");
        exit(-1);
    }
    else{
        newNode->record= r;
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
}
void listInsertOrder(NodePtr *list, Record r){
    NodePtr newNode= malloc(sizeof(Node));

    if(newNode==NULL){
        fprintf(stderr, "Errore allocazione nodo lista");
        exit(-1);
    }
    else{
        newNode->record= r;
        newNode->nextPtr=NULL;
        NodePtr current=*list;
        NodePtr prev = NULL;
    
        while(current!=NULL && strcmp(current->record.name,r.name)<0){
            prev=current;
            current=current->nextPtr;
        }
        if(prev==NULL){
            newNode->nextPtr= *list;
            *list=newNode;
        }else{
            prev->nextPtr=newNode;
            newNode->nextPtr= current;
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
        Record r;
        char record[STR_LEN];
        fscanf(f,"%s\n", record);
        strcpy(r.name,strtok(record,":"));
        r.Vscritto=atoi(strtok(NULL,":"));
        r.Vorale=atoi(strtok(NULL,"\n"));
        ListInsert(&list ,r);
    }
    fclose(f);
    return list;
}
void printRecords(Record r){
    printf("%s:%d:%d\n", r.name, r.Vscritto, r.Vorale);
}

void printList(NodePtr list){
    if(list==NULL)
     fprintf(stderr,"Lista vuota");
    NodePtr current= list;
    while(current!=NULL){
        Record r= current->record;
        printRecords(r);
        current= current->nextPtr;
    }
}

void listTrimmer(NodePtr *list, NodePtr *LAE, NodePtr *LFN, NodePtr *LOZ){
    NodePtr current= *list;

    while(current!=NULL){
        if (current->record.name[0] >= 'a' && current->record.name[0] <= 'e') {
            listInsertOrder(LAE, current->record);
        } else if (current->record.name[0] >= 'f' && current->record.name[0] <= 'n') {
            listInsertOrder(LFN, current->record);
        } else if (current->record.name[0] >= 'm' && current->record.name[0] <= 'z') {
            listInsertOrder(LOZ, current->record);
        }
        current=current->nextPtr;
    }
    *list=NULL;
}
/*void saveList(NodePtr *LAE, NodePtr *LFN, NodePtr *LOZ){
    FILE* f=NULL;
    if((f=fopen("AE.txt","w"))==NULL){
        fprintf(stderr,"Errore apertura file");
        exit(-1);
    }
    NodePtr current=*LAE;
    while(current!=NULL){
        fprintf(f,"%s:%d:%d\n",current->record.name, current->record.Vscritto, current->record.Vorale );
        current=current->nextPtr;
    }
    if((f=fopen("FN.txt","w"))==NULL){
        fprintf(stderr,"Errore apertura file");
        exit(-1);
    }
    current=*LFN;
    while(current!=NULL){
        fprintf(f,"%s:%d:%d\n",current->record.name, current->record.Vscritto, current->record.Vorale );
        current=current->nextPtr;
    }
    if((f=fopen("OZ.txt","w"))==NULL){
        fprintf(stderr,"Errore apertura file");
        exit(-1);
    }
    current=*LOZ;
    while(current!=NULL){
        fprintf(f,"%s:%d:%d\n",current->record.name, current->record.Vscritto, current->record.Vorale );
        current=current->nextPtr;
    }
    fclose(f);
}*/
void saveList(NodePtr *list, char filename[]){
    FILE* f=NULL;
    if((f=fopen(filename,"w"))==NULL){
        fprintf(stderr,"Errore apertura file");
        exit(-1);
    }
    NodePtr current=*list;
    while(current!=NULL){
        fprintf(f,"%s:%d:%d\n",current->record.name, current->record.Vscritto, current->record.Vorale );
        current=current->nextPtr;
    }
    fclose(f);
}
int main (int argc, char * argv[]){
    Param p= decodeParamaters(argc, argv);
    printf("PUNTO 1 \nFilename : %s\n", p.filename);
    NodePtr list= readInputs(p.filename);
    printf("PUNTO 2");
    printList(list);
    NodePtr LAE=NULL;
    NodePtr LFN=NULL;
    NodePtr LOZ=NULL;
    listTrimmer(&list, &LAE, &LFN, &LOZ);
    printf("\nLAE\n");
       
    printf("\nLFN\n");
    printList(LFN);
    printf("\nLOZ\n");
    printList(LOZ);
    printf("\nLISTA\n");
    printList(list);
    saveList(&LAE, "AE.txt");
    saveList(&LFN, "FN.txt");
    saveList(&LOZ, "OZ.txt");
}