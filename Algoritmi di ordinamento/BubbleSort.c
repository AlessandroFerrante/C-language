#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10

void bubbleSort(int array[], size_t length);

int main(){
    int array[SIZE]={0};
    srand(time(NULL));
    for (size_t i = 0; i < SIZE; i++){
        array[i]=rand() % 90 + 10;
    }
    puts("Unsorted array: ");
    for (size_t i = 0; i < SIZE; i++){
        printf("%d ",array[i]);
    }
    bubbleSort(array, SIZE);
    puts("Sorted array");
    for (size_t i = 0; i < SIZE; i++){
        printf("%d ", array[i]);
    }      
}

void bubbleSort(int array [], size_t length){
    for (size_t i = 1; i < length; i++){//numero di passate sull'array,porta l'elemento più grande alla fine lasciado il più piccolo in array[0]
        for (size_t j = 0; j < length-1; j++){//confronta ad ogni passata
            if (array[j]>array[j+1]){//scambia se non sono ordinati
                int hold = array[j];
                array[j]=array[j+1];
                array[j+1]=hold;
            }          
        }
    }
}