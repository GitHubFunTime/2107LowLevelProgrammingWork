#include <stdio.h>
#include <stdlib.h>
int main(void){
   int pinCount=0;
   int Pin=0;
   int Balance=5000;
   
   int UserInput;
   int TransactionCount=0;
   int DepositLimit;
   int WithdrawlLimit;
   int ReceiptCheck;
   int DepositAmount;
   int WithdrawlAmount;
   
   //prototype
   int PrintBalance(int Balance);
   int Deposit(int DepositAmount);
   int Withdrawl(int WithdrawlAmount);
   void Quitvoid(int TransactionCount);
   while (pinCount<3&&Pin!=3014){
   printf("%s","Enter pin:");
   scanf("%d", &Pin );
   if (pinCount==2){
       printf("you have run out of chances, exiting atm...\n");
       exit(0);
   }
   else if (Pin<0 && Pin==0){
       printf("Invalid numerical input");
       ++pinCount;
   }
   if (Pin!=3014){
        printf("Incorrect enter again\n");
       ++pinCount;
   }
   }
   while (Pin==3014){
       printf("-------------------------------------\n");
       printf("\tMENU\n");
       printf("1: Print Balance\n");
       printf("2: Cash withdrawl, then enter an amount to withdraw\n");
       printf("3: Cash deposition, then enter an amount to deposit\n");
       printf("4: Quit\n");       
       printf("-------------------------------------\n");
       //do somethign, Run all the functions?
       scanf("%d",&UserInput);
       if (UserInput==1){
           PrintBalance(Balance);
       }
       if (UserInput==2){
           printf("%s","How much would you like to Withdraw? ");
           scanf("%d",&WithdrawlAmount);
           WithdrawlLimit+=Withdrawl(WithdrawlAmount);
           if (WithdrawlLimit<=1000&&WithdrawlAmount%20==0){
           Balance-=Withdrawl(WithdrawlAmount);
           ++TransactionCount;
            printf("%s","Would you like a receipt?, 1 for yes 2 for no \n");
            scanf("%d", &ReceiptCheck);
            if (ReceiptCheck==1){
            printf("printing receipt...\n");
            }
            
            else if(ReceiptCheck==2){
            printf("ok have fun using the atm");
            }
           }
           else if (WithdrawlLimit>1000){
               printf("You have reached the Withdrawl Limit\n");
           }
       }
       if (UserInput==3){
           printf("%s","How much would you like to Deposit? ");
           scanf("%d",&DepositAmount);
           DepositLimit+=Deposit(DepositAmount);
           if (DepositLimit<=10000&&(DepositAmount%1==0 || DepositAmount%5==0 || DepositAmount%10==0)){
           Balance+=Deposit(DepositAmount);
           ++TransactionCount;
            printf("%s","Would you like a receipt?, 1 for yes 2 for no \n");
            scanf("%d", &ReceiptCheck);
            if (ReceiptCheck==1){
            printf("printing receipt...\n");
            }
            
            else if(ReceiptCheck==2){
            printf("ok have fun using the atm");
            }
           }
           else if (DepositLimit>1000){
               printf("You have reached the Deposit Limit\n");
           }
       }
       if (UserInput==4){
           Quitvoid(TransactionCount);
           exit(0);
       }
   }
}
   


int PrintBalance(int Balance){
    printf("%d\n",Balance);
    return Balance;
}
int Deposit(int DepositAmount){
    if (DepositAmount<=0){
        printf("Not a valid input\n");
        return 0 ;
    }
    else if (DepositAmount%1!=0 || DepositAmount%5!=0 || DepositAmount%10!=0){
        printf("enter an amount in an increment of 1, 5 or, 10 dollars please\n");
        return 0;
    }
    else if (DepositAmount%1==0 || DepositAmount%5==0 || DepositAmount%10==0){
        return DepositAmount;
    }
    return 0;
}
int Withdrawl(int WithdrawlAmount){
    if (WithdrawlAmount<=0){
        printf("Not a valid input\n");
        return 0;
    }
    else if (WithdrawlAmount%20!=0){
        printf("enter an amount in an increment of 20 dollars please\n");
        return 0 ;
    }
    else if (WithdrawlAmount%20==0){
        return WithdrawlAmount;
    }
    return 0;
}
void Quitvoid(int TransactionCount){
    int ReceiptCheck;
    printf ("Would you Like a receipt? 1 for yes, 2 for no\n");
           scanf("%d", &ReceiptCheck );
           if (ReceiptCheck==1){
               printf("Printing Receipt...\n");
               printf("Thank you for using the ATM!!!!\n");
               printf("Total Transactions: %d\n", TransactionCount);
           }
           else if (ReceiptCheck==2){
               printf("Thank you for using the ATM!!!!\n");
               printf("Total Transactions: %d\n", TransactionCount);
           }
}