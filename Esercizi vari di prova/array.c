#include<stdio.h>
int main(){
    int n [5]={32,27,64,18,95};
    printf("%s%8s\n","Element","Value");

    for(size_t i =0;i<5;++i){
        printf("%7zu%8d\n",i,n[i]);
    }
}