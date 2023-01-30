#include<stdio.h>
struct clientData{
    int account;
    char lastName[15];
    char firstName[10];
    double balance;
};
typedef struct clientData clientData;


int main(){
    FILE *cfPtr=NULL;

    if ((cfPtr=fopen("accounts.dat","wb")) == NULL){
        puts("File could not be opened");
    }
    else{
        //crea un blankClient di tipo clientData (cioè struct clientData) con informazioni predefinite
        clientData blankClient = {0, "", "", 0.0};

        //scrive 100 record vuoti su file
        for (size_t i = 0; i < 100; i++){
            fwrite(&blankClient, sizeof(clientData),1,cfPtr);
        }
        
        fclose(cfPtr);//chiusura file
        
    }
    
}