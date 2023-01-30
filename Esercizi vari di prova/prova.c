#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
 int main(){
    int a=0;
    while(a<10){
        printf("%d\n",++a);
    }
    a=7;
        printf("%d\n",a++);
        printf("%d\n",a);
        printf("%d\n",++a);
        printf("%d\n",a);
    int b;
    printf("%d\n",b);
    /*----ES3.5-------*/
    int x=1,sum=0;
    while(x<=10){
        sum+=x;
        x++;
    }
    printf("%d ",x);
    while(x>1){
        --x;
        printf("%d ",x);
    }
    /*-------------------*//*
    srand(time(NULL));
    int xx=rand();
    while(x>10){
        printf("%d  ",rand());
        --xx;
    }
    
    while(xx>1){
        --xx;
        printf("%d ",xx);
    }*/
    int x1, y1, i=1, power=1;
    printf("\nInsersci x: ");
    scanf("%d",&x1);
    printf("\nInsersci y: ");
    scanf("%d",&y1);
    
    while(i<=y1){
        power*=x1;
        if(i==y1)
            printf("%d\n",power); 
        i++;      
    }
    /*LOOP*//*
    for(int c=0;;c++){
        if(c<100 && c>0)
        printf("%d",c);
    }*/
    for(int c=0;c<100;c++){
        printf("%d",c);
        
    }
    printf("\n normal: %f",pow(2,2));
    printf("\n 21.2 : %21.2f",pow(2,2));
    printf("\n 21.22 :  %21.22f",pow(2,2));
    printf("\n -21.2 : %-21.2f",pow(2,2));
    printf("\n -21.22 :  %21.22f",pow(2,2));
    /*----------es 4.3-----------------*/
    //a
    int sum2=0,count=1;
    for(;count<=99;count+=2){
        sum2+=count;
    }
        printf("\n%d",sum2);

    //b
    //333.5                   333.55        333.546       333.5464      333.54637
    printf("\n%-15.1f",333.546372);
    printf("%15.2f",333.546372);
    printf("%15.3f",333.546372);
    printf("%15.4f",333.546372);
    printf("%15.5f",333.546372);
    //c
    printf("\n%10.2f\n",pow(2.5,3));
    //d
    int m=0;
    while(++m<=20){
        printf("%d",m);
        if(m % 5==0)
            printf("\n");
        else
            printf("\t");
    }
    int m2=1;
    while(m2<=20){
         if(m % 5==0)
            printf("%d\n",m2++);
        else
            printf("%d\t",m2++);
    }














 }