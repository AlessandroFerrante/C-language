#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10
void linearSearch(int array[], int key, size_t length);
int main(){
    int a[SIZE]={0};

    srand(time(NULL));
    for (size_t i = 0; i < SIZE; i++){
        a[i]=rand()%90+10;
    }
    puts("This is the array: ");
    for (size_t i = 0; i < SIZE; i++){
        printf("%d ",a[i]);
    }
    int searchKey = 0;
    printf("\nInsert your key: ");
    scanf("%d", &searchKey);
    linearSearch(a, searchKey, SIZE);
}
void linearSearch(int array[], int key, size_t length){
    int count=0;
    for (size_t j = 0; j < length; j++){
        if (array[j] == key){
            count++;
            printf("The key is present at position array[%d]\n",j);  
        }
    }
    if (count>0)    
        printf("It is present for %d times",count);
    else
        puts("The key isn't present");
}