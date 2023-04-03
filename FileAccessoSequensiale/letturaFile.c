#include <stdio.h>
#include<stdlib.h>

int main(){
    FILE *cfPtr=NULL;
    if((cfPtr = fopen("clients.txt","r"))==NULL)
        puts("File not opened");
    else{
        int account=0;//numero del conto
        char firstname[30]="";//nome cliente
        char lastname[30]="";//cognome cliente   
        double balance=0.00;// saldo cliente
        
        char firstRow[30]="";//prima riga per la tabella
        char firstRow2[30]="";//prima riga per la tabella
        char firstRow3[30]="";//prima riga per la tabella
        char firstRow4[30]="";//prima riga per la tabella
        //leggi la prima riga del file
        
        fscanf(cfPtr,"%29s \t %29s \t %29s \t %29s",firstRow, firstRow2, firstRow3, firstRow4); 
        printf("%-15s \t% -29s \t% -29s \t %-20s\n",firstRow, firstRow2, firstRow3, firstRow4);

        // questa viene stampata nel whilea
        fscanf(cfPtr,"%15d \t %29s \t %29s \t %lf", &account, firstname, lastname, &balance);

        while(!feof(cfPtr)){//mentre il puntatore è diverso dal carattere di terminazione  
            printf("%-15d \t %-29s %-29s \t %-7.2lf\n", account, firstname, lastname, balance);
            fscanf(cfPtr,"%15d \t %29s \t %29s \t %lf", &account, firstname, lastname, &balance);
        }
        fclose(cfPtr);//chiude il file 
    }
}