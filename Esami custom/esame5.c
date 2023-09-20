#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct parameter{
    char filename[255];
}Param;

typedef struct record{
    char name[255];
    int scritto;
    int orale;
}Record;

typedef struct stackNode{
    Record record;
    struct stackNode *nextPtr;
}Node;
typedef Node* NodePtr;

Param decodeParam(int argc, char *argv[]){
    if(argc!=2){
        fprintf(stderr,"Errore, inserie un parametro");
        exit(-1);
    }
    Param p;
    strcpy(p.filename,argv[1]);
    if(strcmp(strrchr(p.filename,'.'),".txt")!=0){
        fprintf(stderr,"Errore, il file deve avere estensione .txt");
        exit(-1);
    }
    return p;
}
void push(NodePtr *stack, Record r){
    NodePtr newNode= malloc(sizeof(Node));
    if(newNode==NULL){
        fprintf(stderr,"Errore, memoria insufficente");
        exit(-1);
    }
    newNode->record=r;
    newNode->nextPtr=*stack;
    *stack=newNode;
}
NodePtr readFile(char filename[]){
    FILE* f=NULL;
    if((f=fopen(filename,"r"))==NULL){
        fprintf(stderr,"Errore, il file non è stato aperto");
        exit(-1);
    }
    NodePtr stack=NULL;
    while(!feof(f)){
        Record r;
        char row[255];
        fscanf(f,"%s",row);
        strcpy(r.name,strtok(row,":"));
        r.scritto=atoi(strtok(NULL,":"));
        r.orale=atoi(strtok(NULL,"\n"));
        push(&stack, r);
    }
    return stack;
}
void printRecords(Record r){
    printf("%s:%d:%d\n", r.name, r.scritto, r.orale);
}
void printStack(NodePtr stack){
    while(stack!=NULL){
        Record r= stack->record;
        printRecords(r);
        stack=stack->nextPtr;
    }
}
int countNode(NodePtr *stack){
    int count=0;
    NodePtr current=stack;
    while(current!=NULL){
        current++;
        current=current->nextPtr;
    }
    return count;
}
float topAvg(NodePtr *stack){
    Record r=stack->record;
    float scritto=(float)r.scritto;
    float orale=(float)r.orale;
    float avg=(scritto+orale)/2;
    while(stack!=NULL){
        r=stack->record;
        float scritto=(float)r.scritto;
        float orale=(float)r.orale;
        float newAvg= (scritto+orale)/2;
        if(newAvg>avg){
            avg=newAvg;
        }
        stack=stack->nextPtr;
    }
    return avg;
}
Record pop(NodePtr *stack){
    NodePtr tmp=*stack;
    Record r= tmp->record;
    *stack=tmp->nextPtr;
    free(tmp);
    return r;
}

NodePtr topStudentMaker(NodePtr *stack){
    NodePtr top=NULL;
    int n= countNode(&stack);
    float highAvg=topAvg(stack);  

    for(int i=0; i<n;i++){
        Record r= pop(stack);
        float scritto=(float)r.scritto;
        float orale=(float)r.orale;
        float avg=(scritto+orale)/2;
        if(avg > (highAvg-3)){
            printf("%f",highAvg);
            push(&top, r);
        }
        else{
            push(stack1, r);
        }
    }    
    return top;
}
int main(int argc, char *argv[]){
    Param p= decodeParam(argc, argv);
    NodePtr stack=readFile(p.filename);
    printStack(stack);
    NodePtr topStudent= topStudentMaker(&stack);

    //printRecords(r);
    printf("\n topStudent\n");
    printStack(topStudent);
    printf("\n stack\n");
    printStack(stack);

}