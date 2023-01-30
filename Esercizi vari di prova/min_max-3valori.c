#include<stdio.h>

int main(){
    int a,b,c;
    printf("Inserisci il primo valore: ");
    scanf("%d",&a);
    printf("Inserisci il secondo valore: ");
    scanf("%d",&b);
    printf("Inserisci il terzo valore: ");
    scanf("%d",&c);
    if(a<b){
        if(a<c){
            printf("Il valore minimo e' %d",a);
        }
        else{
           printf("Il valore minimo e' %d",c); 
        }
    }
    else{
        if(b<c){    
            printf("Il valore minimo e' %d",b);
        }
        else{
           printf("Il valore minimo e' %d",c); 
        }
    }
}