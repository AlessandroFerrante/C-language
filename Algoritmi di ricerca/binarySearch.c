#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10
void insertionSort(int array[], size_t length);
void selectionSort(int array[], size_t length);
void blubbleSort(int array[],size_t length);
void binarySearch(int array[], int key, int low, int high);
int main(){
    int a[SIZE]={0};

    srand(time(NULL));
    for (size_t i = 0; i < SIZE; i++){
        a[i]=rand()%90+10;
    }
    puts("This is the unsorted array: ");
    for (size_t i = 0; i < SIZE; i++){
        printf("%d ",a[i]);
    }
    blubbleSort(a, SIZE);
    puts("\nThis is the sorted array: ");
    for (size_t i = 0; i < SIZE; i++){
        printf("%d ",a[i]);
    }
    int searchKey = 0;
    printf("\nInsert your key: ");
    scanf("%d", &searchKey);
    binarySearch(a, searchKey, 0, SIZE-1);
}



void binarySearch(int array[], int key, int low, int high){
    size_t count=0;
    while (low<=high){
        int middle=(low + high)/2;
        if(array[middle] == key && count==0){
            printf("The key is present at posittion array[%d]\n",middle);
            count++;
        }
        else if(key < array[middle]){//nel caso sia vera bisogna controllare solo gli elementi sulla sinista//infatti sposta high (indietro)
            high = middle-1;
        }
        else{
            low = middle+1;//sposta low(in avanti) per controllare solo gli elementi sulla desta
        }
    } 
    if(count>0){
        printf("It is present for %d times", count);
    }    
    else{
        puts("The key isn't present");
    }
}
void selectionSort(int array[], size_t length){
    for (size_t i = 0; i < length-1; i++){
        size_t small = i;
        for (size_t j = i+1; j < length; j++){
            if (array[j]<array[small]){
                small=j;
            }
        }
        int temp=array[i];
        array[i]=array[small];
        array[small]=temp;
    }   
}
void insertionSort(int array[], size_t length){
    for(size_t i=1; i<length;i++){
        size_t moveItem= i;
        int insert =array[i];
        while (moveItem>0 && array[moveItem-1]>insert){
            array[moveItem]=array[moveItem-1];
            --moveItem;
        }
        array[moveItem]=insert;// moveItem viene decrementato prima che esce dal while, quindi è come se inseriamo insert in moveItem-1
    }
}
void blubbleSort(int array[], size_t length){
    for (size_t i = 0; i < length; i++){
        for (size_t j = 0; j < length-1; j++){
            if(array[j]>array[j+1]){
                int hold =array[j];
                array[j]=array[j+1];
                array[j+1]=hold;
            }
        }   
    }   
}