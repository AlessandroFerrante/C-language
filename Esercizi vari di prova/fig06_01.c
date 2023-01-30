
//fig 6_01 e fig 6_03
#include<stdio.h>
int main(){
    int n[5];
    printf("%s %8s\n","Element","Value");
    for(int i=0;i<5;i++){
        n[i]=i*2+2;        
        printf("%7u %8d\n",i,n[i]);
    }
}