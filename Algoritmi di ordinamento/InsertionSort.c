#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10
//prototipi
void insertionSort(int array[],size_t length);
void printPass(int array[], size_t length, int pass, size_t index);

int main(){
    int array[SIZE]={0};

    srand(time(NULL));

    for (size_t i = 0; i < SIZE; i++){
        array[i]= rand() % 90 +10;
    }
    puts("Unserted array");
    
    for(size_t i= 0; i < SIZE; i++){
        printf("%d ",array[i]);
    }
    puts("\n");

    insertionSort(array, SIZE);
    puts("Sorted array: ");
    for (size_t i = 0; i < SIZE; i++){
        printf("%d ",array[i]);
    }
    puts("");
}

void insertionSort(int array[], size_t length){  
    //esegue l'iterazione su ligth-1 elementi
   for (size_t i = 1; i < length; i++){
    size_t moveItem = i; //posizione in cui inserire l'elemento
    int insert = array[i];//contiente l'elemento da inserire
    
    while(moveItem > 0 && array[moveItem-1] > insert){// moveItem>0 serve perchè viene decrementato moveItem, in questo modo permette di fare il confronto all'indietro,
    //...infatti a ogni iterazione del ciclo esterno una prima parte dell'array sarà sempre ordinata
        //sposta l'elemento, a destra di una sola posizione, cioè al posto di quello minore
        array[moveItem]=array[moveItem-1];//inserisce l'elemento maggiore al suo posto spostandolo a destra 
        --moveItem;//decrementa l'indice
    }
    //come se fosse moveItem-1 infatti viene già decrementato nel while
    array[moveItem]=insert;//inserisci l'elemento minore al suo posto
   } 
}

/*
void insertionSort(int array[], int lenght){
    for(int i=1 ; i<lenght; i++){
        int MoveItem=i;
        int data= array[MoveItem];

        while(MoveItem > 0 && array[MoveItem-1]>data){
            arry[MoveItem]=arry[MoveItem-1];
            --MoveItem;
        }
        array[MoveItem]=insert;
    }
}
*/