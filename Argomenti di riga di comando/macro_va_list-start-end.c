#include<stdio.h>
#include<stdarg.h>

//prototipo di funzione
double average(int i, ...);//... rapresenta argomenti varibili
int enterChoice(void);
int main(){
    double w= 37.5;
    double x= 22.5;
    double y= 1.7;
    double z= 10.2;

    printf("%s%.1f; %s%.1f; %s%.1f; %s%.1f;\n\n", "w= ", w, "x= ", x, "y= ", y, "z= ",z);
    printf("%s%.3f\n%s%.3f\n%s%.3f\n", 
    "The average of w and x is  ",average(2, w, x),
    "The average of w, x and y is ",average(3, w, x, y),
    "The average of w, x , y and z is ",average(4, w, x, y, z));
    enterChoice();
}
//calcola la media
double average(int i, ...){
    double total= 0;
    va_list ap;//memorizza le informazioni per var_start e var_end

    va_start(ap, i);//inizializza l'oggetto ap di tipo var_list

    //elabora la lista di argormenti di lunghezza variabile
    for (size_t j = 0; j <= i; ++j){
        total+= va_arg(ap, double);
    }
    va_end(ap);//pulitura della lista di argomenti di lunghezza variabile
    return total/i;//media calcolata   
}

