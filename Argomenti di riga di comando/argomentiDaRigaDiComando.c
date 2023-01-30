//Uso degli argomenti della riga di comando, 
//sono comunemente usati per passari opzioni e nomi di file a un programma
//per fare cuiò la funzione  main del programma deve includere i parametri int arg e char *argv[]
//il primo riceve in input il numero di argomenti della riga di comando che l'utente ha inserito 
//il secondo è un array di stringhe in cui sono memorizzati gli argomenti della riga di comando
#include<stdio.h>

int main(int argc, char *argv[]){
    FILE *inFilePtr=NULL;
    //controlla il numero degli argomenti inseriti nel riga di comando 
    //
    //perchè in questo caso il programma funziona solo con 3 argomenti
    if (argc !=3){
        puts("Usage: infile outfile");
    }
    else{
        if((inFilePtr=fopen(argv[1],"r"))==NULL){
            printf("File \"%s\" could not be opened\n",argv[1]);
        }
        else {
            FILE *outFilePtr=NULL;
            if ((outFilePtr = fopen(argv[2],"w"))==NULL){
                printf("File \"%s\" could not be opened\n", argv[2]);
            }
            else{
                int c=0;
                while ((c= fgetc(inFilePtr))!= EOF){
                    fputc(c, outFilePtr);
                }
                fclose(outFilePtr);
            }
            fclose(inFilePtr);
        }
    }      
}