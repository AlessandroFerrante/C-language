#include<stdbool.h>
#include<stdio.h>

enum Options { ALL=0, ZERO_BALANCE = 1, CREDIT_BALANCE, DEBIT_BALANCE, KEY_BALANCE, END };
bool shouldDisplay(enum Options option, double balance,double key);

int main(void){
    FILE* cfPtr =NULL;
    if ((cfPtr = fopen("clients.txt","r")) == NULL){
        puts("File could not be opened");
    }
    else{
        printf("%s","Enter request: \n"
        "0 - List of all Accounts\n"
        "1 - List accounts with zero balances\n"
        "2 - List account with credit balances\n"
        "3 - List account with debit balances\n"
        "4 - List account with key balances\n"
        "5 - End of run\n#");
        int request = 0;
        scanf("%d",&request);
        double key=0.00;

        //stampa record richiesti
        while (request != END){
            
            switch (request){
                case ALL:
                    puts("\nAll Accounts: ");
                    break;
                case ZERO_BALANCE:
                    puts("\nAccounts with zero balances: ");
                    break;
                case CREDIT_BALANCE:
                    puts("\nAccounts with credit balances: ");
                    break;
                case DEBIT_BALANCE:
                    puts("\nAccounts with debit balances: ");                
                    break;
                case KEY_BALANCE:
                    printf("%s","Inserisci il valore del saldo chiave: ");
                    scanf("%lf", &key);
                    puts("\nAccounts with key balances: ");                
                    break;
            }       
        
            int account=0;//numero del conto
            char firstname[30]="";//nome cliente
            char lastname[30]="";//cognome cliente   
            double balance=0.00;// saldo cliente
            char firstRow[30]="";//prima riga per la tabella
            printf("%-15s \t %-29s %-29s \t %s\n", "Account", "Firstname", "Lastname", "Balance" );

            //leggi la prima riga del file, non viene stampata serve solo a portare avanti il puntatore perchè il puntatore viene avanzato con il prossimo fscanf
            fscanf(cfPtr,"%29s \t %29s \t %29s \t %29s",firstRow, firstRow, firstRow, firstRow);
            // questa viene stampata nel while
            fscanf(cfPtr,"%15d \t %29s \t %29s \t %lf", &account, firstname, lastname, &balance);

            while (!feof(cfPtr)){
                //stampa se soddisfa le condizioni
                if (shouldDisplay(request, balance, key)){
                    printf("%-15d \t %-29s %-29s \t %-7.2lf\n", account, firstname, lastname, balance);
                }
                fscanf(cfPtr,"%15d \t %29s \t %29s \t %lf", &account, firstname, lastname, &balance);
            }

            rewind(cfPtr);//reimposta il puntatore 
            printf("%s", "\n# ");
            scanf("%d",&request);// prende un'altra richiesta se c'è
        }
     
        puts("End of run.");
        fclose(cfPtr);//chiude il file 
    } 
}
bool shouldDisplay(enum Options option, double balance,double key){
    if((option == ALL)){
        return true;
    }
    if ((option == ZERO_BALANCE) && (balance == 0)){
        return true;
    }
    if ((option == CREDIT_BALANCE) && (balance < 0)){
        return true;
    }
    if ((option == DEBIT_BALANCE) && (balance > 0)){
        return true;
    }
    if ((option == KEY_BALANCE) && (balance == key)){
        return true;
    }
    return false; 
}