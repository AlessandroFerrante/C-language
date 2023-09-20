#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct parametri{
    char *alfabeto;
    int n;
    char *fileName;
}Parametri;

typedef struct stackNode{
    char *data;
    struct stackNode *nextPtr;
}sNode;

typedef sNode* sNodePtr;

Parametri decodeParameters(int argc, char *argv[]);
int* readInput(int n, int L);
char* sampleString(char * alfabeto, int h);
char** getStringArray(int n, char * alfabeto, int* W);
sNodePtr *getStack(char** Q, int n);
void push(sNodePtr *head,char *Q);
char* pop(sNodePtr *head);
void writeStackToFile(sNodePtr *stack, char * fileName);

unsigned int get_random() {
    static unsigned int m_w = 424242;
    static unsigned int m_z = 242424;
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return (m_z << 16) + m_w;
}
Parametri decodeParameters(int argc, char* argv[]){
    if(argc!=4){
        fprintf(stderr,"Errore i parametri passati devono essere 3");
        exit(-1);
    }
    else{
        Parametri p;
        p.alfabeto= argv[1];
        p.fileName= argv[3];

        char *end;
        p.n= (int) strtol(argv[2], &end, 10);

        if(*end){
            fprintf(stderr,"n non è un intero valido\n");
            exit(-1);
        }
        if(p.n<5 || p.n>20){
            fprintf(stderr,"Errore, n deve essere un intero compreso tra 5 e 20 (inclusi)\n");
            exit(-1);
        }
        if(strlen(p.alfabeto)<5 || strlen(p.alfabeto)>15){
            fprintf(stderr,"Errore, la lunghezza dell'alfabeto non è corretta deve essere compresa tra 5 e 15 inclusi\n");
            exit(-1);
        }
        return p;//verrà ritornato se e solo se le condizioni risulteranno false e non termineranno il programma
    }
}

int* readInput(int n, int L){
    int* W=calloc(n, sizeof(int));
    int x;
    for(int i=0; i<n; i++){
        printf("Inserisci un valore: ");
        scanf("%d", &x);
        if(x>1)
            x=x;
        else
            x=1;
        if(x<L)
            x=x;
        else
            x=L;
        W[i]=x;
    }
    return W;
}
char *sampleString(char *alfabeto, int h){
    char* sampleStr=calloc(h+1,sizeof(char));//h+1 per il carattere di terminazione
    int L=strlen(alfabeto);
    for(int i=0; i<h;i++){
        sampleStr[i]=alfabeto[get_random()%L];
        //printf("sampleStr[%d]=%c\n",i,sampleStr[i]);
    }
    sampleStr[h]=0;//carattere di terminazione
    return sampleStr;
}
char **getStringArray(int n, char* alfabeto, int* W){
    char** Q=calloc(n, sizeof(char**));//array di stringhe
    for(int i=0; i<n; i++){
        Q[i]= sampleString(alfabeto, W[i]);
        printf("Q[%d]=%s\n",i,Q[i]);
    }
    return Q;
}

sNodePtr *getStack(char** Q, int n){
    sNodePtr *head= malloc(sizeof(sNodePtr));
    if(head==NULL){
        fprintf(stderr,"Errore Stack non allocato");
        exit(-1);
    }
    push(head, Q[0]);
    for(int i=1; i<n; i++){
        char* insert;
        if((strlen(Q[i])%2)==0){
            push(head,Q[i]);
        }
        else{
            char *top= pop(head);
            insert= calloc(strlen(Q[i])+strlen(top)+1, sizeof(char));
            strcpy(insert, top);
            strcat(insert, Q[i]);
            push(head, insert);
        }
    }
    return head;
}
int isEmpty(sNodePtr head){
    return head==NULL;
}
void push(sNodePtr *head, char *str){
    
    sNodePtr newNode= calloc(1,sizeof(sNode));
    
    if(newNode==NULL){
        fprintf(stderr,"memoria insufficente impossibile allocare la stringa nella pila\n");
        //exit(-1);
    }
    else{
        newNode->data= str;
        printf("%s",str);
        //strcpy(newNode->data, str); SBAGLIATO
        if(isEmpty(*head)){
            newNode->nextPtr= NULL;
            *head= newNode; 
        }
        else{
            newNode->nextPtr= *head;
            *head= newNode;
        }
    }
}
char* pop(sNodePtr *head){
    if(isEmpty(*head)){
        fprintf(stderr,"La pila è vuota impossibile restituire una stringa");
        exit(-1);
    }
    else{
        sNodePtr temp= *head;
        char *Str = temp->data;
        char *pop= calloc(strlen(Str), sizeof(char));
        strcpy(pop, Str);
        *head= temp->nextPtr;
        free(temp);
        return pop;
    }
}

void writeStackToFile(sNodePtr *stack, char * fileName){
    FILE *cfPtr= NULL;
    if((cfPtr=fopen(fileName, "a"))==NULL){
        fprintf(stderr,"Errore nell'apertura del file %s\n",fileName);
        exit(-1);    
    }
    sNode* read=*stack;
    puts("ok2.1");
    while(read!=NULL){
        fprintf(cfPtr,"%s\n", read->data);
        read = read->nextPtr;
    }
    fclose(cfPtr);
}
int main(int argc, char *argv[]){
    puts("Programma avviato");
    Parametri p= decodeParameters(argc, argv);
    int* W= readInput(p.n, strlen(p.alfabeto));
    char** Q= getStringArray(p.n, p.alfabeto, W);
    puts("ok1");
    sNodePtr *head = getStack(Q, p.n);
    puts("ok2");
    writeStackToFile(head, p.fileName);
    puts("Programma terminato");
}