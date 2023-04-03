#include<stdio.h>
#include<stdlib.h>

int main(){
  FILE* cfPtr= NULL;

  if((cfPtr=fopen("col.txt","r"))==NULL){
    printf("File non aperto");
  }
  else{
    char col1[30]="";
    char col2[30]="";
    printf("%s","Stampa del file...\n");
    fscanf(cfPtr,"%29s \t %29s", col1, col2);
    while(!feof(cfPtr)){
      printf("%-29s \t %29s \n", col1, col2);
      fscanf(cfPtr,"%29s \t %29s",col1, col2);
    }
    printf("Stampa terminata\n");
  }
  rewind(cfPtr);
  puts("Inserire 1 per aggiornare il file, altrimenti 2 per terminare il programma");
  int choice=0;
  
  scanf("%d", &choice);
  while(choice!=2){
    char colw1[30]="";
    char colw2[30]="";
    switch(choice){
      case 1:        
        if((cfPtr=fopen("col.txt","a+"))==NULL){
          printf("File non aperto");
        }
        else{
          printf("Inserisci Nome e Cognome: ");
          scanf("%29s %29s",colw1 , colw2);

          while(!feof(stdin)){
            fprintf(cfPtr,"%s \t %29s \n",colw1, colw2);
            printf("%s","Inserisci Nome e Cognome: ");
            scanf("%29s %29s", colw1, colw2);
          }
        }
        break;
      default:
        puts("Invalid choice");
        break;
    }
    puts("Inserire 1 per aggiornare il file, altrimenti 2 per terminare il programma");
    scanf("%d",&choice);
  }
  puts("Programma terminato");
  fclose(cfPtr);//chiude il file
}