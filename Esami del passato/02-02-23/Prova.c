#include <stdio.h>
#include <string.h>
int main() {
        char input[255]="42 ciao ciao 44 ciao";
        int num1, num2;
        char str1[20], str2[20];

        sscanf(input, "%d %s %s %d %s", &num1, str1, str2, &num2, str2);

        printf("Number 1: %d\n", num1);
        printf("String 1: %s\n", str1);
        printf("String 2: %s\n", str2);
        printf("Number 2: %d\n", num2);
    
}