#include <stdio.h>
#include<stdlib.h>

int main(){
    FILE *cfPtr=NULL;

    if ((cfPtr=fopen("clients.txt","a+"))==NULL)
        puts("File not opened");
    else{
        int account=0;
        char firstname[30]="";
        char lastname[30]="";
        double balance=0.00;
        puts("#");
        
        scanf("%15d %29s %29s %lf", &account, firstname, lastname, &balance);
        
        while(!feof(stdin)){
            fprintf(cfPtr,"%-15d \t %-30s \t %-30s \t %.2f\n", account, firstname, lastname, balance);// cfPtr all'inizio è il numero di indice//Scrittura su file 
            printf("%s","#");
            scanf("%d %29s %29s %lf", &account, firstname, lastname, &balance);
        }
        fclose(cfPtr);
    }
}
