#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct riga{
    char word[100];
    int count;
}Riga;

typedef struct node{
    Riga data;
    struct node *nextPtr;
}Node;

typedef Node *NodePtr;

//prototipi 
int readN(int argc, char *argv[]);
void readFile(char *nameFile);
void filterList(NodePtr *head, int n);
void printList(NodePtr head);

//****************************
int main(int argc, char *argv[]){
    int n= readN(argc,argv[]);
    NodePtr head= malloc(sizeof(Node));
    head = readFile("input.txt");

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

void readFile(char *nameFile){
    
}

void filterList(NodePtr *head, int n){

}

void printList(NodePtr head){

}