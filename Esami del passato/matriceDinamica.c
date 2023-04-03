#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct argomenti{
    int k;
    char w;
    int N;
    int M;
}Argomenti;

//prototipi
Argomenti checkArgs(int argc, char *argv[]);
char ***allocateMatrix(int k, int N, int M);
char *genString(int k, char start, char end);
void  riempiMatrice(char ***S, int N, int M, int length);
void bubbleMatrice(char ***S, int M, int N );
void stampaMatrice(char ***S, int M, int N);

int main(int argc, char *argv[]){
    Argomenti args= checkArgs(argc, argv);
    int k= args.k;
    int N= args.N;
    int M= args.M;
    //printf("%d %c %d %d",args.k,args.w,args.N,args.M);
    char ***S= allocateMatrix(k, N, M);
    riempiMatrice(S, N, M, k);
    //bubbleMatrice(S, N, M);
    stampaMatrice(S, N, M);
}

Argomenti checkArgs(int argc, char *argv[]){
    //num k
    char *endk= malloc(sizeof(char *));
    int k= strtol(argv[1], &endk,0);
    char w =argv[2][0];
    char *endN= malloc(sizeof(char *));
    int N= strtol(argv[3], &endN,0);
    char *endM= malloc(sizeof(char *));
    int M= strtol(argv[4], &endM,0);

    if(endk && k>=10 && k<=15 && islower(w) && endN && N>=4 && N<=8 && endM && M>=4 && M<=8){
        Argomenti args={k, w, N, M};
        printf("k=%d w=%c N=%d M=%d\n",args.k, args.w, args.N, args.M);
        return args;
    }
    else{
        fprintf(stderr, "Errore, i parametri passati devono essere: un intero k in [10,15], un carattere w in [a-z] e due interi N ed M in [4,8].\n");        
        exit(0);
    }
}


char ***allocateMatrix(int k, int N, int M){
    char ***matrice=malloc(M * sizeof(char **));
    for(size_t i= 0; i < M; i++){
        matrice[i]=malloc(N * sizeof(char *));
        for(size_t j= 0; j < N; j++){
            matrice[i][j]=malloc(sizeof(char)*k);
        }
    }
    return matrice;
}

char *genString(int length, char start, char end){
    char *str=malloc(sizeof(char) * length);
    int st= (int)(start);
    int en= ((int)(end)) + 1;
    for(int i=0;i<length;i++)
        str[i]= (rand() % (en-st)) +st;
    return str;
}

void riempiMatrice(char ***S, int N, int M, int length){
    for (size_t i = 0; i < M; i++){
        for (size_t j = 0; j < N; j++){
            char *randomStr= genString(length, 'a', 'z');
            strcpy(S[i][j], randomStr);
        }
    }
}
//ordina solo la colonna
void bubbleMatrice(char ***S, int M, int N){  
    for (size_t i = 0; i < N; i++){
        for (size_t j = 0; j < M-1-i; j++){
           if(strcmp(S[j+1][i],S[j][i])<0){
            char *temp=S[j][i];
            S[j][i]= S[j+1][i];
            S[j+1][i]=temp;
           }
        }        
    }
        printf("-------bubbleMatrice");
}

void stampaMatrice(char ***S, int N, int M){
    for(size_t i= 0; i<M; i++){
        for(size_t j=0; j<N; j++)
            printf("%-20s",S[i][j]);
            printf("\n");
    }
}
