//Lettura sequensiale su un file ad acceso casuale
#include<stdio.h>

//definiizione struttura clientData
typedef struct clientData{
   int account;
   char lastName[30];
   char firstName[30];
   double balance;
}clientData;
   
 int main(){
    FILE *cfPtr= NULL;//puntatore al file accounts.dat

    //fopen apre il file, esce se non può essere aperto
    if((cfPtr = fopen("accounts.dat","rb")) == NULL){
      puts("File could not be opened");
    }
    else
    {
      printf("%-6s%-16s%-11s%10s\n","Acct","Last Name","First Name","Balance");
      
      //leggi tutti i record dal file fino a eof
      while (!feof(cfPtr))
      {
         //leggi un record
         clientData client={0, "", "", 0.0};

         size_t result = fread(&client, sizeof(clientData), 1, cfPtr);
         //printf("result= %d",result);
         //stampa il record 
         if (result!=0 && client.account != 0){
            printf("%-6d%-16s%-11s%10.2f\n",client.account, client.lastName, client.firstName, client.balance);
         }
         
      }
      fclose(cfPtr);;//fclose chiude il file 
    }
 }