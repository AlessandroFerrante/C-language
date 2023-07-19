
//====================== get_random.c ======================

//====================== Esame.c ======================
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct input{
    char filename[255];
    int n;
}Input;

typedef struct record{
    int numeroConto;
    char nome[255];
    char cognome[255];
    double saldo;
}Records;

typedef struct listNode{
    Records record;
    struct listNode *nextPtr;
}lNode;

typedef lNode* lNodePtr;
     
unsigned int get_random() {
    static unsigned int m_w = 424242;
    static unsigned int m_z = 242424;
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return (m_z << 16) + m_w;
}

Input decodeParameters(int argc, char* argv[]){
    Input input;
    if(argc!=3){
        fprintf(stderr,"\nInserire un intero e il nome del file con estensione .bin\n");
        exit(-1);
    }
    else{
        strcpy(input.filename, argv[1]);
        input.n=atoi(argv[2]);
        if(input.n<=3 && input.n>=5 || strcmp(strrchr(input.filename,'.'),".bin")!=0){
            fprintf(stderr, "Inserire i dati in modo corretto");
            exit(-1);
        }
        else{
            puts("PUNTO A");
            printf("I parametri inseriti sono \nFilename= %s \n n= %d\n\n", input.filename, input.n);
            return input;
        }
    }
}
void printRecord(Records print){
    printf("%d %s %s %.2lf\n", print.numeroConto, print.nome, print.cognome, print.saldo);
}
int isEmpty(lNodePtr list){
    return list==NULL;    
}
void printList(lNodePtr list){
    if(isEmpty(list)){
        puts("The list is empty");
    }
    else{
        puts("Contenuto lista L: ");
        lNodePtr current = list;
        while(current != NULL){
            Records r=current->record;
            printRecord(r);
            current= current->nextPtr;
        }
    }
}
void loadRecords(lNodePtr *list, lNodePtr newNode){
    if(*list == NULL){
        *list= newNode;
    }
    else{
        lNodePtr current = *list;
        while (current->nextPtr != NULL) {
            current = current->nextPtr;
        }
        current->nextPtr = newNode;
    }
}
void readRecords(lNodePtr *list){
    Records record;
    puts("PUNTO B");
    printf("Inserisci i dati nel seguente ordine:\n NumeroConto Nome Cognome Saldo\n");
    while(!feof(stdin)){
        lNodePtr newNode=malloc(sizeof(lNode));
        if(newNode == NULL){
            fprintf(stderr, "Errore di allocazione di memoria ");
            break;
        }
        scanf("%d %255s %255s %lf\n", &record.numeroConto, record.nome, record.cognome, &record.saldo);
        newNode->record= record;
        newNode->nextPtr=NULL;
        loadRecords(list, newNode);
    }    
}
int countNode(lNodePtr list){
    lNodePtr current=list;
    int i=0;
    while(current!=NULL){
        i++;
        current=current->nextPtr;
    }
    return i;
}
Records* getArray(lNodePtr list){
    Records* X= calloc(countNode(list), sizeof(Records));
    if(X == NULL){
        fprintf(stderr, "Errore di allocazione di memoria per array X di struct");
        exit(-1);
    }
    int i=0;
    lNodePtr current=list;
    while(current){
        X[i++]=current->record;
        current=current->nextPtr;
    }
    return X;
}
void sort(Records* X, int n){
    double avg=0;
    for(int i =0 ; i<n; i++){
        avg += X[i].saldo;
    }
    avg/=n;

    for(int i=0; i<n-1; ++i){
        int small=i;
        for(int j=i+1; j<n; ++j){
            if(((X[j].saldo-avg)*(X[j].saldo-avg))<((X[small].saldo-avg)*(X[small].saldo-avg))){
                small=j;
            }
        }
        Records tmp= X[i];
        X[i]=X[small];
        X[small]=tmp;
    }
}
void printArray(Records* X, int n){
    for(int i=0; i<n; i++){
        /*Records r= X[i];
        printRecord(r);*/
        printRecord(X[i]);
    }
}
void saveToFile(Records* X,char filename[], int n){
    FILE* f=NULL;
    if((f=fopen(filename,"wb"))==NULL){
        fprintf(stderr,"Errore di apertura file");
        exit(-1);
    }
    for(int i=0; i<n;i++){
        fwrite(&X[i],sizeof(Records), 1, f);
    }
    fclose(f);
}
void saveToFileTXT(Records* X, int n){
    FILE* ff=NULL;
    if((ff=fopen("prova.txt","w"))==NULL){
        fprintf(stderr,"Errore di apertura file di testo");
        exit(-1);
    }
    for(int i=0; i<n;i++){
        fprintf(ff,"%d %s %s %.2lf\n",X[i].numeroConto, X[i].nome, X[i].cognome, X[i].saldo);
    }
    fclose(ff);
} 
void  showFileContent(char filename[], int n){
    FILE* f=NULL;
    if((f=fopen(filename,"rb"))==NULL){
        fprintf(stderr,"Errore di apertura file");
        exit(-1);
    }
    for(int i=0; i<n; ++i){
        int m= get_random()%5;
        fseek(f, m*sizeof(Records), SEEK_SET);
        Records r;
        size_t result= fread(&r,sizeof(Records), 1, f);
        if(result!=0){
            printRecord(r);
        }
    }
    fclose(f);
}
int main(int argc, char* argv[]){
    Input param = decodeParameters(argc, argv);
    lNodePtr L=NULL;
    readRecords(&L);
    printList(L);
    Records* X= getArray(L);
    sort(X, countNode(L));

    printf("\nPUNTO C\n");
    printArray(X, countNode(L));

    saveToFile(X, param.filename, countNode(L));
    saveToFileTXT(X, countNode(L));

    printf("\nPUNTO D\n");
    showFileContent(param.filename, param.n);
}