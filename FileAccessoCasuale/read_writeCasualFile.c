#include<stdio.h>
#include<stdlib.h>
typedef struct data{
    int account=0;
    char fisrtname[30]="";
    char lastname[30]="";
    double balance=0.00;
}Data;
int main(){
    FILE *cfPtr=NULL;
    if((cfPtr=fopen("accounts.dat","rb+"))==NULL)
        puts("File not opened");
    else{
        while(!feof(cfPtr) || !feof(stdin)){
            Data data= {0, "", "", 0.00};
            fread(&data, sizeof(Data),1 , cfPtr);
        }
    }
}