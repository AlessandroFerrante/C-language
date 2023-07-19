#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<limits.h>


typedef struct node{
    int data;
    struct node *nextPtr;

}Node;

typedef Node* lNodePtr;//Puntatore di TIPO node alla struttura node

int isEmpty(lNodePtr lPtr);
void printList(lNodePtr lPtr);
void insert(lNodePtr *lPtr, int newData);
bool delete(lNodePtr *lPtr, int delData);
void istructions();
int main(){
 instructions();
}
void istructions(){
    printf("Instr");
    int newData;
    scanf("%d",&newData);
    insert(&lPtr,newData);
}
void insert(lNodePtr *lPtr, int newData){
    lNodePtr newNode= malloc(sizeof(Node))
    if(newNode==NULL){
        printf("Il numero %d no è stato inserito errore creazione nodo, memoira insuficente");
    }
    else{
        newNode->data= newData;
        newNode->nextPtr= NULL;

        lNodePtr currentNode=*lPtr;
        lNodePtr prevNode=NULL;
        
        while(currentNode!=NULL && currentNode->data<newData){
            prevNode=currentNode;
            currentNode= currentNode->nextPtr;
        }

        if(prevNode==NULL){
            newNode->nextPtr=*lPtr;
            *lPtr=newNode;
        }
        else{
            prevNode->nextPtr=newNode;
            newNode->nextPtr=currentNode;
        }
    }
}

bool delete(lNodePtr *lPtr. int delData){
    lNodePtr tempNode=*lPtr;

    if
}