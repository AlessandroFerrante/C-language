#include<stdio.h>
int fattoriale(int);
int main (){
	int n,fatt;
	do{
	printf("Insersci un numero >0 per eseguire il fattoriale:");
	scanf("%d",&n);
	}while(n<0);
	fatt=fattoriale(n);
	printf("%d",fatt);
}
int fattoriale(int n) {
	if (n==0){
	return 1;
	}
else return n*fattoriale(n-1); 
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
