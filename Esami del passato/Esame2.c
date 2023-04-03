#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct parametri{
    int n;
    char w;
}Parametri;

typedef struct listNode{
    char *data;
    struct listNode *nextPtr;
}lNode;

typedef lNode* lNodePtr;

Parametri decodeParametri(int argc, char * argv[]);
void insertString(lNodePtr *lPtr, char * data);
lNodePtr getList(int n);
char* getString();
void printList(lNodePtr lPtr, int n);
int isEmpty(lNodePtr lPtr);
void printW(lNodePtr lPtr, int n, char w);

unsigned int get_random() {
    static unsigned int m_w = 424242;
    static unsigned int m_z = 242424;
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return (m_z << 16) + m_w;
}

int main(int argc, char * argv[]){
    Parametri p= decodeParametri(argc, argv);
    puts("Avvio getList...");
    lNodePtr l= getList(p.n);
    puts("Avvio printList...");
    printList(l, p.n);
    printW(l,p.n,p.w);
}

lNodePtr getList(int n){
    lNodePtr l=malloc(sizeof(lNodePtr));
    if(l==NULL){
        fprintf(stderr,"Errore, impossibile allocare la lista\n");
        exit(-1);
    }
    for(int i=0; i<n;i++){
        printf("%d\n",i);
        char *str= getString();
        printf("%s \t",str);
        insertString(&l,str);
    }
    return l;
}

void insertString(lNodePtr *lPtr, char *newData){
    
    puts("insertString");

    lNodePtr newNode=malloc(sizeof(lNode));
    if(newNode==NULL){
        fprintf(stderr,"Errore, nodo lisa non allocato, memoria piena");
        exit(-1);
    }
    newNode->data= strdup(newData);
    newNode->nextPtr= NULL;

    lNodePtr prevNode=NULL;
    lNodePtr currentNode= *lPtr;
    
    
    while(currentNode!=NULL && strcmp(newData,currentNode->data)>0){
        prevNode = currentNode;
        currentNode = currentNode->nextPtr;
    }
    if(prevNode==NULL){
        newNode->nextPtr= *lPtr;
        *lPtr= newNode;
    }
    else{
        prevNode->nextPtr=newNode;
        newNode->nextPtr=currentNode;
    }
    puts("end getString");
}

char *getString(){
    int L=get_random()%11+5;
    char *str=malloc((L+1) * sizeof(char));
    int a=(int) ('a');
    int z=((int) ('z'))+1;
    for(int i=0;i<L; i++){ 
        str[i]= (get_random()%(z-a))+a;
    }
    str[L]='\0';
    return str;
}

int isEmpty(lNodePtr lPtr){
  return lPtr==NULL;
}

void printList(lNodePtr lPtr, int n){
    puts("gestList");
    if(isEmpty(lPtr)){
        fprintf(stderr,"Errore, la lista è vuota impossibile stamparla");
        exit(-1);
    }
    for(int i=0; i<n;i++){
        printf("%s->", lPtr->data);
        lPtr=lPtr->nextPtr;
    }
    puts("NULL");
}


void printW(lNodePtr lPtr, int n, char w){
    puts("gestList");
    if(isEmpty(lPtr)){
        fprintf(stderr,"Errore, la lista è vuota impossibile stamparla");
        exit(-1);
    }
    int count =0;
    for(int i=0; i<n; i++){
        char *str= lPtr->data;
        int len= strlen(str);
        for(int j=0; j<len; j++){
            if(str[j]==w){
                count++;
            }
        }
        lPtr=lPtr->nextPtr;
    }
    
    printf("La lettera %c è ripetuta %d",w,count);
    
}

Parametri decodeParametri(int argc, char *argv[]){
     if(argc!=3){
        fprintf(stderr,"Errore i parametri passati devono essere 2");
        exit(-1);
    }
    else{
        Parametri p;
        char *end;
        p.n= (int) strtol(argv[1], &end,10);
        p.w= argv[2][0];
        if(p.n<10 || p.n>20){
            fprintf(stderr,"Errore, n deve essere un'intero tra 10 e 20 compresi");
            exit(-1);
        }

        if(!islower(p.w)){
            fprintf(stderr,"Errore, w non è un carattere minuscolo");
            exit(-1);
        }
        return p;
    }
}

