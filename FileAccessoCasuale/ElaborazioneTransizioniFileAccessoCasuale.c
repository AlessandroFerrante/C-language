 /*Programma per elaborazione di transizioni che legge sequensialmente 
un file ad accesso casuale, aggiorna i dati già scritti sul file,
crea nuovi dati(record) da inserire nel file e cancella dati(record) dal file*/
#include<stdio.h>

// struttura dei dati del cliente
typedef  struct clientData{
    int account;
    char firstName[30];
    char lastName[30];
    double balance;
}clientData;

//prototipi di funzioni
extern void openChoice();
extern int enterChoice(void);
extern void textFile(FILE *readPtr);
extern void updateRecord(FILE *fPtr);
extern void newRecord(FILE *fPtr);
extern void deleteRecord(FILE *fPtr);

int main(){
       openChoice();     
}
void openChoice(){
    FILE *cfPtr=NULL;

    if ((cfPtr=fopen("accounts.dat","rb+"))==NULL){
        puts("File could not opened");
    }
    else{
       int choice= 0;

       //consenti all'utente di specificare l'azione
       while ((choice= enterChoice())!=5)
       {
        switch (choice)
        {
        case 1://crea un file di testo dal file di record
            textFile(cfPtr);
            break;
        case 2://aggiorna un record -
            updateRecord(cfPtr);
            break;
        case 3://aggiunge un nuovo record al file
            newRecord(cfPtr);
            break;
        case 4://cancella record esistente
           deleteRecord(cfPtr);
            break;
        default:
            puts("Incorrect choice");
            break;
        }
       }
    }
}
//menu per consetire all'utente la scelta
int enterChoice(){
    //stampa le opzioni disponibili
    printf("%s", "\nEnter your choice\n"
        "1 - store a formatted text file of accounts called \"accounts.txt\" for printing\n"
        "2 - update an account\n"
        "3 - add new account\n"
        "4- delete an account\n"
        "5 - end program\n# ");

        int menuChoice=0;
        scanf("%d", &menuChoice);
        return menuChoice;// ritorna il numero di variabile scelta dall'utente
}

//creazione file di testo formattato per la stampa dal file accounts.dat     
void textFile(FILE *readPtr){
     FILE *writePtr=NULL;//*puntatore al file accounts.txt per copiare i dati da accounts.dat a accounts.txt

        /*fopen apre il file se non può essere aperto esce,perchè restituisce un puntatore
         quindi assegna un puntatore da lui generato (all'apertura del file) a writePtr
        se il file non può essere aperto restituisce NULL, e l'if mostra il messaggio del puts*/
     if ((writePtr = fopen("accounts.txt","w")) == NULL){
        puts("File could not be opened");
     }
     else{
        rewind(readPtr);//*sposta il puntatore all'inizio del file
        fprintf(writePtr,"%-6s %-29s %-29s %s\n","Acct","Last Name", "First Name","Balance");
        
        //*copia tutti i record dal file ad accesso casuale al file di testo
        while (!feof(readPtr)){
            clientData client={0, "", "", 0.0};
            size_t result=fread(&client, sizeof(clientData), 1, readPtr);
            if(result!=0 && client.account!=0){
                fprintf(writePtr,"%-6d %-29s %-29s %lf\n", client.account, client.lastName, client.firstName, client.balance);
            }
        }
        fclose(writePtr);//chiude il file accounts.txt
     }
}
//aggiorna il saldo nel record
void updateRecord(FILE *fPtr){

    //ottieni il numero di conto da aggiornare 
    printf("%s", "Enter account to update (1 - 100): ");
    int account = 0;
    scanf("%d", &account);
    
    /*
     sposta il puntatore del file al record corretto nel file prendendo in input il numero di account 
    account-1 perchè l'account 0 non esiste ma deve comunque inziare dall'inizio del file 
    l'argomento centrale cioè l'offset indica il numero di byte (restituiti da sizeof e 
    moltiplicati per il numero di account) di cui ci si deve spostare rispetto a seek_set cioè l'inizio del file 
    */
    fseek(fPtr, (account-1) * sizeof(clientData), SEEK_SET);
    
    //leggi il recod dal file
    clientData client={0, "", "", 0.0};
    fread(&client, sizeof(clientData), 1, fPtr);

    //stampa un messaggio di errore se il conto non esiste
    if(client.account==0){ 
        printf("Account #%d has no information.\n", account);
    }
    else{
        //aggiorna il record 
        printf("%-6d%-16s%-11s%10.2f\n\n", client.account, client.lastName , client.firstName, client.balance);
        
        //richiedi l'ammontare della transizione all'utente
        puts("Enter charge + or payment - : ");
        double transaction=0.0;
        scanf("%lf",&transaction);
        client.balance+=transaction;//aggiorna il saldo 

        //record aggiornato
        printf("%-6d%-16s%-11s%10.2f\n\n", client.account, client.lastName , client.firstName, client.balance);
        
        //sposta il puntatore al record da aggiornare
        fseek(fPtr, (account-1)*sizeof(clientData), SEEK_SET);
        //scrivi il record aggiornato al posto del vecchio record nel file 
        fwrite(&client, sizeof(clientData),1,fPtr);
    }
}

void newRecord(FILE *fPtr){
    //ottieni il numero del conto da creare 
    printf("%s","Enter new account number (1-100): ");
    int account=0;
    scanf("%d",&account);

    //sposta il puntatore del file al record corretto nel file
    fseek(fPtr,(account-1)*sizeof(clientData),SEEK_SET);
    
    //leggi il record dal file
    clientData client={0, "", "", 0.0}; 
    fread(&client, sizeof(clientData), 1, fPtr);

    if (client.account != 0){
     }
    else
    {
        //crea un record
        printf("%s","Enter lastname, firstname, balance\n# ");
        scanf("%29s%29s%lf",&client.lastName, &client.firstName, &client.balance);

        client.account= account;

        //sposta il puntatore del file al record corretto nel file
        fseek(fPtr,(account-1)*sizeof(clientData),SEEK_SET);
        //inserisce sul file il record
        fwrite(&client,sizeof(clientData),1,fPtr);
    }    
}
//cancella un record esistente
void deleteRecord(FILE *fPtr){
    puts("Enter account number to delete (1-100)");

    int account= 0;
    scanf("%d",&account);

    //sposta il puntatore del file al reccord da eliminare nel file
    fseek(fPtr,(account-1)*sizeof(clientData),SEEK_SET);

    //leggi il record da eliminare
    clientData client={0, "", "", 0.0};
    fread(&client, sizeof(clientData), 1,fPtr);

    if(client.account==0){
        printf("Account %d does not exist\n ",account);
    }
    else
    {
        //elimina il record
        //sposta il puntatore sul record da eliminare nel file
        fseek(fPtr,(account-1)*sizeof(clientData),SEEK_SET);
        
        //record vuoto da sostituire con il record da eliminare
        clientData blankClient= {0,"","",0.0};

        //sostituisce il record precedente con uno vuoto blankClient (riga sopra)
        fwrite(&blankClient,sizeof(clientData),1,fPtr);
    }
}
