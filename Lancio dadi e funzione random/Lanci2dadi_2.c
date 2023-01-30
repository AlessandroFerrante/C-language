#include <stdio.h>
#include <stdlib.h> 
#define Roll 36000
#define CountArray 11

int RollDice(void){
    return rand() % 6 + 1;
}

int main(void){
    int Array[11] = {0};
    for(int i = 0; i < Roll; i++){
        Array[RollDice() + RollDice() - 2] += 1; 
    } 
    for(int i = 0; i < CountArray; i++){
        printf("numero: %d - Contatore: %d \n", i + 2, Array[i]);
    }
}