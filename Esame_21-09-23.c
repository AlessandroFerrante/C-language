
//====================== Esame.c ======================
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct param{
    int min;
    int max;
    int n;
}Param;

unsigned int get_random() {
    static unsigned int m_w = 424242;
    static unsigned int m_z = 242424;
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return (m_z << 16) + m_w;
}

Param decodeParam(int argc, char* argv[]){
    if(argc!=4){
        fprintf(stderr,"Errore inserire 3 parametri\n");
        exit(1);
    }
    Param p;
    char *end1;
    p.min=(int) strtol(argv[1], &end1,  10);
    if(*end1){
        fprintf(stderr,"Il primo parametro deve essere un'intero\n");
        exit(1);
    }
    char *end2;
    p.max=(int) strtol(argv[2], &end2,  10);
    if(*end2){
        fprintf(stderr,"Il secondo parametro deve essere un'intero\n");
        exit(1);
    }
    char *end3;
    p.n=(int) strtol(argv[3], &end3,  10);
    if(*end3){
        fprintf(stderr,"Il terzo parametro deve essere un'intero\n");
        exit(1);
    }
    if(p.min<7 || p.min>12){
        fprintf(stderr,"Il primo parametro deve essere un'intero compreso tra 7 e 12\n");
        exit(1);
    }
    if(p.max<7 || p.max>12){
        fprintf(stderr,"Il secondo parametro deve essere un'intero compreso tra 7 e 12\n");
        exit(1);
    }
    if(p.n==0){
        fprintf(stderr,"Il terzo parametro deve essere un'intero positivo diverso da 0\n");
        exit(1);
    }
    if(p.min>p.max){
        fprintf(stderr,"Il primo parametro deve essere minore del secondo\n");
        exit(1);
    }
    return p;
}
char * generateString(int min, int max){
    int x=(get_random()%max-min+1) +min;
    char *str= malloc(x);
    const char vocali[]="aeiou";
    
    for(int i=0; i<x; i++){
        int indice= get_random()%5;
        str[i]=vocali[indice];
    }
    str[x]='\0';
    return str;
}
char ** makeArray(int n, int min, int max){
    char **A=malloc(n * sizeof(char*));
    for(int i=0; i<n; i++){
        A[i]=generateString(min, max);
        printf("%s\n", A[i]);
    }
    return A;
}
void sortArray(int n, char **A){
    char *str;
    for(int i=0; i<n; i++){
        int moveItem= i;
        str=A[i];
        while(moveItem>0 && strcmp(A[moveItem-1], str)>0){
            A[moveItem+1]=A[moveItem];
            moveItem--;
        }
        A[moveItem]=str;
    }
}
char * concatString(char **A, int n){
    int strLen=0;

    for(int i=0; i<n; i++){
        strLen += strlen(A[i]);
    }
    char *B= malloc(strLen+1);
    for(int i=0; i<n; i++){
        strcat(B,A[i]);
    }
    return B;
}
void replaceCharacters(char *B){
    int strLen= strlen(B);
    for(int i=1; i<strLen; i++){
        if(B[i]== 'u' && B[i-1]=='e'){
            B[i]= '*';
        }
    }
}
int main(int argc , char* argv[]){
    Param p = decodeParam(argc, argv);
    printf("Punto A - Parametri inseriti: min=%d, max=%d, n=%d\n", p.min, p.max, p.n);
    printf("%s\n","---Punto B---");
    char **A= makeArray(p.n, p.min, p.max);
    sortArray(p.n, A);
    printf("%s\n","---Punto C---");
    char *B= concatString(A, p.n);
    printf("%s\n",B);
    printf("%s\n","---Punto D---");
    replaceCharacters(B);
    printf("%s\n",B);
}