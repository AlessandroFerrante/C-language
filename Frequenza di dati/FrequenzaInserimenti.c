#include<stdio.h>
int main(void){
    int aCount=0,bCount=0,cCount=0,dCount=0,fCount=0;
    int grade=0;
    puts("Enter the letter grades: ");
    puts("Enter EOF character to end input");

    while((grade=getchar())!= EOF){// viene eseguita prima la l'assegnazione (grade=getchar()) e poi viene controlata
        //EOF End Of File con ctrl+z varibaile sentinella di default
        //getchar() è una funzione appartente alla libraria <stdio.h> e ha la funzionalità di prendre in input un carattere

        switch(grade){
            case 'A':
            case 'a':
                ++aCount;
                break;
            case 'B':
            case 'b':
                ++bCount;
                break;
            case 'C':
            case 'c':
                ++cCount;
                break;
            case 'D':
            case 'd':
                ++dCount;
                break;
            case 'F':
            case 'f':
                ++fCount;
                break;
            case '\n':
            case '\t':
            case ' ':
                break;
            default:
                printf("%s","Incorrect letter");
                puts("enter a new grade");
                break;
        }
    }   
    puts("\nTotals fo each letter grade are: "),
    printf("A: %d\n",aCount);
    printf("B: %d\n",bCount);
    printf("C: %d\n",cCount);
    printf("D: %d\n",dCount);
    printf("F: %d\n",fCount);

}