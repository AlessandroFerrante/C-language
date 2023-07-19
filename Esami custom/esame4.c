#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define STRLEN 255
typedef struct parameter{
    char filename[STRLEN];
}Param;

typedef struct record{
    char name[STRLEN];
    int scritto;
    int orale;    
}Record;

Param decodeParameter(int argc, char*argv[]){
    if(argc!=2){
        fprintf(stderr,"Errore, inserire un parametro");
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
void insertArray(Record* a, Record r,int i){
   memcpy(&a[i], &r, sizeof(Record));
}
int countRecord(char filename[]){
    FILE* f=NULL;
    if((f=fopen(filename,"r"))==NULL){
        fprintf(stderr,"Errore apertura file");
        exit(-1);
    }
    int size=0;
    while(!feof(f)){
        char row[255];
        fscanf(f,"%s\n",row);
        size++;
    }
    return size;
}
Record* readFile(char filename[], int size){
    FILE* f=NULL;
    if((f=fopen(filename,"r"))==NULL){
        fprintf(stderr,"Errore apertura file");
        exit(-1);
    }
    Record* a=malloc(size * sizeof(Record));
    int i=0;
    while(!feof(f)){
        Record r;
        char row[STRLEN];
        fscanf(f,"%s\n",row);
        strcpy(r.name,strtok(row,":"));
        r.scritto=atoi(strtok(NULL,":"));
        r.orale=atoi(strtok(NULL,"\n"));
        insertArray(a, r, i);
        ++i;
    }
    fclose(f);
    return a;
}
void printArray(Record* array, int size){
    for(int i=0; i<size;++i){
        printf("%s:%d:%d\n",array[i].name, array[i].scritto, array[i].orale );
    }
}

void shuffleArray(Record *a, int size){
    srand(time(NULL));
    int random=0;
    for(int i=0; i<size;++i){
        random=rand()%(size);
        Record r;
        r=a[i];
        a[i]=a[random];
        a[random]=r;
    }
}
void insertionSort(Record* array, int size){
    for(int i=0; i<size; i++){
        int move=i;
        Record r=array[move];
        //strcpy(r.name, array[move].name);
        //r.scritto=array[move].scritto;
        //r.orale=array[move].orale;
        while(move>0 && strcmp(array[move-1].name,r.name)>0){
            array[move]=array[move-1];
            --move;
        }
        array[move]=r;
    }
}
void saveFile(Record* array, char filename[], int size){
    FILE* f=NULL;
    if((f=fopen(filename,"w"))==NULL){
        fprintf(stderr,"Errore apertura file");
        exit(-1);
    }
    for(int i=0; i<size; i++){
        Record r= array[i];
        fprintf(f,"%s:%d:%d\n",r.name, r.scritto, r.orale);
    }
    fclose(f);
}
int main(int argc, char *argv[]){
    Param p= decodeParameter(argc, argv);
    int size=countRecord(p.filename);
    Record* array=readFile(p.filename, size);
    printArray(array, size);
    shuffleArray(array, size);
    printf("\n\nArray shuffle\n");
    printArray(array, size);
    insertionSort(array, size);
    printf("\n\nArray \n");
    printArray(array, size);
    saveFile(array,p.filename, size);
}