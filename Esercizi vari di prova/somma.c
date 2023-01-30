#include <stdio.h>

int main(){
    //first ecs
    
    printf("first exc\n");//display
    int integer1=0;
    int integer2=0;

    printf("Enter first integer: "); //promot
    scanf("%d",&integer1); //read an integer

    printf("Enter second integer: "); //promot
    scanf("%d",&integer2); //read an integer1
    
    int sum; //variable in witch sum will be stored 
    
    sum= integer1+integer2;// assign total to sum 
    printf("Sum %d+%d is %d!\n",integer1,integer2,sum);//print the two int and the sum
    /*
    //second ecs
    printf("second exc");//display
    int x,y,z;
    printf("Enter three integer: "); //promot
    scanf("%d%d%d",&x,&y,&z); //read an integer

    int result= x*y*z;
    printf("%d",result);//display result
    //threeth exc
    printf("threeth exc\n");//display
    int x1 = 2 * 3 + 8 / 2-1 * 3; 
    int y1 = 2 * (3 + 8) / 2-1 * 3;
    int z1 = (2 * 3) + 8 / (2 - 1) * 3;
    printf("%d\n%d\n%d\n", x1, y1, z1);*/
}//end