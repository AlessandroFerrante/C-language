#include<stdio.h>
int fibonacci(int n);
int main(){
	int n,f;
	do{
		printf("Iserisci un numero >=1 per trovare l'ennesimo termine: ");
		scanf("%d",&n);
	}while(n<1);
	f=fibonacci(n);
	printf("La succesione di Fibonacci e': %d",f);
}
int fibonacci(int n){
	if(n<=2){
		return 1;
	}
	else{
		return fibonacci(n-1)+fibonacci(n-2);
	}
}