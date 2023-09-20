#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10
void selectionSort(int array[],size_t length);
void swap(int array[], size_t first, size_t second);
void printPass(int array, size_t length, int pass, size_t index);

int main(){
    int array[SIZE]={0};
    srand(time(NULL));
    for (size_t i =0; i < SIZE; i++){
        array[i]= rand() % 90 + 10;//assegna un valore casuale a ogni elemento
    }
    puts("Unsorted array:");
    for(size_t i=0; i < SIZE; i++){
        printf("%d ", array[i]);
    }
    puts("\n");
    //funzione per ordinare l'array 
    selectionSort(array, SIZE);
    puts("Sorted array: ");
    for(size_t i =0; i < SIZE; i++){
        printf("%d ", array[i]);//array ordinato
    }
    puts("");
}

void selectionSort(int array[], size_t length){//length = SIZE
    //esegui l'interazione su length-1 elementi  controlla gli elementi da array[0] a array[8] length=10
    for (size_t i = 0; i < length-1; i++){
        size_t smallest=i;//primo indice dell'array rimanente,facendo il controllo su un parte sempre più ridotta di elementi
        //trova l'indice dell'elemento più piccolo
        for (size_t j = i +1; j < length; j++){ //aggiunge 1 alla così controlla gli elemnti con indice da 1 a 9 quello con inidce 0 viene confrontato(smnallest)
            if (array[j] < array[smallest])
            smallest=j;
        }
        int temp= array[i];
        array[i] = array[smallest];
        array[smallest]= temp;
    }
}
/*
void selectionSort(int array[], size_t length){
    for (size_t i = 0; i < length-1; i++)
    {
        int small= i;
        for (size_t j = 0; j < length; j++)   {
            if (array[j]<array[small])
               small= j;
        }
        swap(array, i, smallest);
    }
}
*/
void swap(int array[], size_t first, size_t second){
    int temp= array[first];
    array[first] = array[second];
    array[second]=temp;
}

void printPass(int array, size_t length, int pass, size_t index){

}
void selectionSort(int array[], int lenght){
    for(int i=0; i<lenght; i++){
        int min=i;
        
        for(int j =i+1; j<lenght; j++){
            if(array[min] > array[j]){
                min= j;
            }
        }
        int temp = array[i];
        array[i]=array[min];
        array[min]=temp;
    }
}
//in ordine drecrescente
void selectionSort(int array[], int lenght){
    for(int i=lenght; i>=lenght;i--){
        int max=i;
        for(int j=i+1; j<lenght; j--){
            if(array[max] < array[j]){
                max=j;
            }
        }
        int temp= array[i];
        array[i]=array[max];
        array[max]= temp;
    }
}
void selectionSort(int array[], int lenght){
    for(int i=0; i<lenght;i++){
        int max=i;
        for(int j= 0; j<lenght-1;j++){
            if(array[j]>array[j+1]){
                max=j
            }
            int temp=array[j];
            array[j]=array[j+1];
            array[j]=temp;
        }
    }

}
int bubbleSort(int array[], int lenght){
    for(int i=0; i<lenght; i++){
        for(int j=0; j<lenght-1; j++){
            if(array[j]>array[j+1]){
                int max= array[j];
                array[j]=array[j+1];
                array[j+1]=max;
            }
        }
    }
}


void selectionSort(int array[], int lenght){
    for(int i=0; i<lenght; i++){
        int min=i;
        for(int j=i+1;j<lenght-1;j++){
            if(array[min]>array[j]){
                min=j;
            }
        }
        int temp= array[j];
        array[j]=array[min];
        array[min]= temp;
    }
}

void insertionSort(int array[], int lenght){
    for(int i=0; i<lenght; i++){
        int moveItem=i;
        int data=array[i];
        
        while(moveItem>0 && array[moveItem-1]>data){
            array[moveItem]=array[moveItem-1];
            --moveItem;
        }
        array[moveItem]=data;
    }
}
void bubbleSort(int array[], int lenght){
    for(int i=0; i<lenght; i++){
        for(int j=0; j<lenght-1;j++){
            if(array[j]>array[j+1]){
                int hold= array[j];
                array[j]=array[j+1];
                array[j+1]=hold;
            }
        }
    }
}

void selectionsort(int array[], int len){
    for(int i=0;i<len;i++){
        int min=i;
        for(int j=i+1;i<len-1;j++){
            if(array[min]>array[j]){
                min=j;
            }
        }
        int hold= <array[j];
        array[j]=array[min];
        array[min]=hold;
    }
}