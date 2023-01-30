//fig11_01.c
// Creazione di un file sequenziale
#include<stdio.h>

 int main(){
    FILE *cfPtr=NULL;//puntatore al file clients.txt
    
    // fopen apre il file. Esce dal programma  se non è possibile creare il file 
    if ((cfPtr=fopen("clients.txt","a+"))==NULL)// la lettera "w" indica la modalità di accesso al file 
    {                 //(crea file per la scrittura se esiste cancella il contenuto) meglio usare "a+"
      puts("File could not be opened");
    }
    else{
      puts("Enter the numeber of account, name, and balance.");
      puts("Enter EOF to end input");// carattere per terminare l'inserimetno (ctrl+Z)
      puts("x Account Firstname Lastname Balance");
      printf("%s","#"); // carattere di "indice"

      int account=0;//numero del conto
      char firstname[30]="";//nome cliente
      char lastname[30]="";//cognome cliente   
      double balance=0.00;// saldo cliente
      
      scanf("%d %29s %29s %lf", &account, firstname, lastname, &balance);
      
      size_t i = 0;
      while (!feof(stdin)){
        if (i==0){
          //fprintf(cfPtr,"%-15s \t %-30s \t %-30s \t %s\n", "Account", "Firstname", "Lastname", "Balance");//stampa nel file la prima riga con spazi tra le stringhe per formare una tabella
          i=1;
        }        
        fprintf(cfPtr,"%-15d \t %-30s \t %-30s \t %.2f\n", account, firstname, lastname, balance);// cfPtr all'inizio è il numero di indice//Scrittura su file 
        printf("%s","#");
        scanf("%d %29s %29s %lf", &account, firstname, lastname, &balance);            
      }
      puts("Chiusura del programma in corso...");
      fclose(cfPtr);//fclose chiude il file
    }
 }
 