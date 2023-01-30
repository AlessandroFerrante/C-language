#include<stdio.h>
int main(){
    int n;
    int m;
    int p=0;
    
    printf("N:");
    scanf("%d",&n);
    printf("M:");
    scanf("%d",&m);
    
    for(int i=0;i<n;i++){
        printf("%d ",p);
        p+=2;
    }
    printf("\n");
    p--;
    for(int j=0;j<m;j++){
        printf("%d ",p);
        p+=2;
    }
}