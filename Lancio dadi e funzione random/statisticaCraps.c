#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define loop 1000000
enum Status {CONTINUE, WON, LOST};

int roll(void);

int main(void){
    int countWON=0;
    int countLOST=0;
    srand(time(NULL));
    for(int i=0; i<loop;i++){

        int Point=0;
        enum Status gameStatus= CONTINUE;
        int sum= roll();

        switch(sum){
            case 7:
                gameStatus=WON;
                countWON+=1;
                break;
            case 11:
                gameStatus=WON;
                countWON+=1;
                break;
            case 2:
                gameStatus= LOST;
                countLOST+=1;
                break;
            case 3:
                gameStatus= LOST;
                countLOST+=1;
                break;
            case 12:
                gameStatus= LOST;
                countLOST+=1;
                break;
            default://case 4,5,6,8,9,10
                gameStatus= CONTINUE;//continua a lanciare
                Point =sum;6
                //printf("Il punteggio e'  %d\n", Point);
                break;
        }

        //finché il gioco non si conclude e cìquindi lo status è CONTINUE
        
        while(CONTINUE== gameStatus){//continua il gioco
            sum= roll(); //lancia di nuovo i dadi
            
            if (sum==Point){//si vince facendo il punteggio
                gameStatus=WON;
                countWON+=1;
            }
            else if(7 == sum){// si perde se si ottine sette dopo il primo lancio
                gameStatus=LOST;
                countLOST+=1;
            }  
        }
    }
    double pWon=(double)countWON/loop*100; //?casting
    double pLost=(double)countLOST/loop*100;
    printf("Il numero di vincite e' %d\n",countWON);
    printf("Il numero di perdite e' %d\n",countLOST);
    printf("La percentuale di vincita e' %f %%\n", pWon);
    printf("La percentuale di perdita e' %f %%\n", pLost);
}
int roll(void){
        int die1= 1 +(rand() % 6);//sintassi più corretta
        int die2= 1 +(rand() % 6);// sintassi meno corretta
         
         //printf("%d + %d = %d\n", die1, die2, die1 + die2);
         return die1+die2;//ritorna la somma dei dati
    }