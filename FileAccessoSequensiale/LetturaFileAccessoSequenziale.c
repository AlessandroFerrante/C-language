//fig11_02.c
//Lettura e stampa di un file sequenziale
#include<stdio.h>

int main(){
    FILE *cfPtr =NULL;//puntatore al file clients.txt

    //fopen apre il file in modalità di sola lettura con r se esiste
    if ((cfPtr = fopen("clients.txt","r"))==NULL){
        puts("File could not be opened");
    }
    else{
      int account=0;//numero del conto
      char firstname[30]="";//nome cliente
      char lastname[30]="";//cognome cliente   
      double balance=0.00;// saldo cliente
      char firstRow[30]="";
      
      printf("%-15s \t %-30s \t %-30s \t %s\n", "Account", "Firstname", "Lastname", "Balance");//
      
      //leggi la prima riga del file, non viene stampata, il printf sopra già lo fa 
      fscanf(cfPtr,"%29s \t %29s \t %29s \t %29s", firstRow, firstRow, firstRow, firstRow);// cfPtr all'inizio è il numero di indice//Lettura su file 
      
      //legge la seconda riga del file che viene stampata dal printf nel while
      fscanf(cfPtr,"%15d \t %29s \t %29s \t %lf", &account, firstname, lastname, &balance);// cfPtr all'inizio è il numero di indice//Lettura su file 
     
      //finchè non incontra un end-of-file 
      while (!feof(cfPtr)){
        printf("%-15d \t %-30s \t %-30s \t %.2lf\n", account, firstname, lastname, balance);//stampa nel file la prima riga con spazi tra le stringhe per formare una tabella
        fscanf(cfPtr,"%15d \t %29s \t %29s \t %lf", &account, firstname, lastname, &balance);// cfPtr all'inizio è il numero di indice//Scrittura su file 
      }
      fclose(cfPtr);
    
    }    

}
