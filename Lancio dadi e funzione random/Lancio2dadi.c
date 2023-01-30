#include<stdio.h>
#include<stdlib.h>
#define roll 36000
#define nsum 11
int main(){
    int x=0;
    int y=0;
    int xy=0;
    int countsum[nsum]={0};
    for(int i=0; i<roll;i++){
        x=rand() % 6 + 1;
        y=rand() % 6 + 1;   
        xy=x+y;
        countsum[xy-2]+=1;
    }
    for(int i=0;i<11;i++){
        printf("%d = %d\n",i+2,countsum[i]);
    }
}