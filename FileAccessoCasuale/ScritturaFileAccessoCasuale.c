//Scrittura di dati in maniera casuale su un fuiel ad accesso casuale 

#include<stdio.h>

//definizione struttura client Data usata per scrivere sul file con una dimensione fissa
typedef struct clientData //il typedef viene usato per evitare di scrivere per intero struct clientData
{
    int account;
    char lastName[30];
    char firstName[30];
    double balance;
}clientData;

int main(){
    FILE *cfPtr=NULL;//puntatore al file accounts.dat
    //cfPtr è un puntatore di posizione per il file in termini di byte nel punto (client.account -1)*sizeof (struct clientData) 
    // il valore di questa espressione è chiamato offset o spostamento riga 40 
    if ((cfPtr = fopen("accounts.dat", "rb+"))== NULL)//apre il file esce se non può essere aperto 
    {
        puts("File could not be opened.");
    }
    else{
        //crea un oggetto clientData (che è di tipo struct) con informazioni predefinite
        clientData client={0, "", "", 0.0};
        
        //richiede all'utente di specificare il numero di conto 
        printf("Enter account number (1 to 100, 0 to end input): ");
        scanf("%d", &client.account);

        //l'utente inserisce le informazioni che vengono copiate sul file
         while (client.account!=0) {  

            //chiede all'utente di inserire il cognome, il nome e il valore del saldo 
            printf("%s","\nEnter lastname, firstname and balance: ");
            
            //imposta il record con il cognome, il nome e il valore del saldo prendendo da stdin le informazini
            fscanf(stdin,"%29s%29s %lf", client.lastName, client.firstName, &client.balance);
            
            //*cerca (seek) nel file la posizione del record specificato
            fseek(cfPtr,(client.account-1)*sizeof(clientData), SEEK_SET);// SEEK_SET indica che fseek deve spostare il puntatore all'inizio del file 
            //SEEK_CUR indica corrente nel file 
            //SEEK_END indica la fine del file
            // offset positivi indicano spostamenti in avanti da usare con SEEK_SET e quelli negativi spostamenti indietro da usare con SEEK_END
            //*scrivi le informazioni specificate dall'utente nel file  
            fwrite(&client, sizeof(clientData), 1,cfPtr);

            //consetire all'utente di inserire un'altro numero di conto
            printf("%s","\nEnter account number: ");
            scanf("%d", &client.account);
         }
         fclose(cfPtr);
    }

}