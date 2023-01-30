/*
Scrivere un programma che permetta di calcolare la media dei voti di una classe. 
Il programma permette all’utente di inserire 10 voti (sotto forma di numeri interi) 
e stampa a schermo la media dei 10 voti inseriti (anch’essa sotto forma di numero intero).
*/
//massimo 10 voti 
#include<stdio.h>
int main(){
    float total=0;
    for(int i=1;i<=10;i++){
        printf("%s","Enter grade: ");
        float grade=0;
        scanf("%f",&grade);
        total= total+grade;
    };
    float average=total/10;
    printf("Class average is %f\n", average);
}
