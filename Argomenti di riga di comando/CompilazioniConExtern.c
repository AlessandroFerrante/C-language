#include<stdio.h>
#include<stdarg.h>
#include "C:\Users\alefe\UniCt 2022-23\PROGRAMMAZIONE 1\Laboratorio\FileAccessoCasuale\ElaborazioneTransizioniFileAccessoCasuale.c"
//#include "macro_va_list-start-end.c"
//#include "C:\Users\alefe\UniCt 2022-23\PROGRAMMAZIONE 1\Laboratorio\FileAccessoCasuale\accounts.dat"
//#include "C:\Users\alefe\UniCt 2022-23\PROGRAMMAZIONE 1\Laboratorio\FileAccessoCasuale\accounts.txt"

extern void openChoice();
extern int enterChoice(void);
extern void textFile(FILE *readPtr);
extern void updateRecord(FILE *fPtr);
extern void newRecord(FILE *fPtr);
extern void deleteRecord(FILE *fPtr);
extern double average(int i, ...);
extern int account;
extern double transaction;
extern int menuChoice;
extern FILE *cfPtr;
extern FILE *fPtr;
extern FILE *readPtr;
extern FILE *writePtr;

int main1(){
    //per consentire l'uso di due funzioni da due file diversi occorre prima modificare 
    //il nome della funzione main perchè va ad interferie con gli altri main dei file
    puts("Inserisci 1 o 2\n");
    puts("#");
    int n=0;
    scanf("%d", &n);

    if (n==1){
      double w= 37.5;
      double x= 22.5;
      double y= 1.7;
      double z= 10.2;

      printf("%s%.1f; %s%.1f; %s%.1f; %s%.1f;\n\n", "w= ", w, "x= ", x, "y= ", y, "z= ",z);
      //printf("%s%.3f\n%s%.3f\n%s%.3f\n"
      //"The average of w and x is  ",average(2, w, x),
      //"The average of w , x and y is ",average(3, w, x, y),
      //"The average of w, x , y and z is ",average(4, w, x, y, z)); 
    }
    else {
      openChoice();
    }
}