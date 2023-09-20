#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    char* data;
    struct Node *nextPtr;
}Node;

typedef Node* NodePtr;
typedef struct param{
    int a;
    char m;
}Param;

Param decodeParameters(int argc, char argv* []){
    if(argc!=3){
        fprintf(stderr,"Errore inserire due volori");
        exit(1);
    }
    Param p;
    p.a= atoi();
}
int main(int argc, char argv* []){
    Param p = decodeParameters(argc, argv);
    NodePtr headPtr= NULL;
    NodePtr tailPtr= NULL;

    char *data;

}
void print(NodePtr headPtr){

}
void enqueue(NodePtr *headPtr, NodePtr *tailPtr, char *newData){
    NodePtr newNode= malloc(sizeof(Node));
}