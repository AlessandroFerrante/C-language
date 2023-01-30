/*
Scrivere un programma che permetta di calcolare la media dei voti di una classe.
 Il programma permette all’utente di inserire un numero arbitrario di voti (sotto forma di numeri interi) 
 e stampa a schermo la media dei voti inseriti (sotto forma di numero in virgola mobile). 
 La sequenza di voti inseriti viene terminata quando l’utente inserisce -1.
*/
#include<stdio.h>
int main(){
    int total=0;
    int counter=0;
    printf("%s", "Emter grade, -n to end: ");
    int grade=0;
    scanf("%d", &grade);

    while(grade>0){
        total = total+grade;
        counter++;
        printf("%s", "Enter grade, -n to end: "),
        scanf("%d", &grade);
    }
    if(counter!=0){
        double average= (double) total/counter;
        printf("Class average is %.2f\n", average);
    }
    else { 
        puts("No grades were entered");
    }
}
