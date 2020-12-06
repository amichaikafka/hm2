#include <stdio.h>
#include "myBank.h"
double bank[arrow][arrcol]={0};
/**
 * this function crate a new account 
 * **/
 void O (){
     double deposit=0;
     printf("Please enter amount for deposit:");
    if( scanf("\n%lf",&deposit)==1) {
        if (deposit < 0) {
            printf("Invalid Amount\n");
        } else {
            int flag = 0;
            for (int i = 0; i < 50; i++) {
                if (bank[i][0] == 0) {
                    bank[i][0] = 1;
                    bank[i][1] = deposit;
                    printf("New account number is: %d\n", (i + 901));
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                printf("The bank is in full capacity\n");
            }
        }
    }else {
        printf("Failed to read the amount\n");
    }
}
/**
 * this function check the balance in a specific account 
 * **/
void B(){
    printf("Please enter account number:");
    int account=0;
   if( scanf("\n%d",&account)==1) {
       if (account > 950 || account < 901) {
           printf("Invalid account number\n");
       } else if (bank[account - 901][0] == 0) {
           printf("This account is closed\n");
       } else {
           printf("The balance of account number %d is:%0.2lf\n", account, bank[account - 901][1]);
       }
   }else{
       printf("Failed to read the account number\n");
   }
}
/**
 * this function add deposit to a specific account 
 * **/
void  D (){
    printf("Please enter account number:");
    int account=0;
    if(scanf("\n%d",&account)==1) {
        if (account > 950 || account < 901) {
            printf("Invalid account number\n");
        } else if (bank[account - 901][0] == 0) {
            printf("This account is closed\n");
        } else {
            printf("Please enter the amount to deposit:");
            double deposite = 0;
           if( scanf("\n%lf", &deposite)==1) {
               if (deposite < 0) {
                   printf("Cannot deposit a negative amount\n");
               } else {
                   bank[account - 901][1] = bank[account - 901][1] + deposite;
                   printf("The new balance is:%0.2lf\n", bank[account - 901][1]);
               }
           }else{
               printf("Failed to read the amount\n");
           }
        }
    }else{
        printf("Failed to read the account number\n");
    }
}
/**
 * this function reduces withdraw in a specific account 
 * **/
void W(){
    printf("Please enter account number:");
    int account=0;
    if(scanf("\n%d",&account)==1) {
        if (account > 950 || account < 901) {
            printf("Invalid account number\n");
        } else if (bank[account - 901][0] == 0) {
            printf("This account is closed\n");
        } else {
            printf("Please enter the amount to withdraw:");
            double w = 0;
           if( scanf("%lf", &w)==1) {
               if (w < 0) {
                   printf("Cannot withdraw a negative amount\n");
               } else {
                   if (bank[account - 901][1] - w < 0) {
                       printf("There is no enough money for this amount\n");

                   } else {
                       bank[account - 901][1] = bank[account - 901][1] - w;
                       printf("The new balance is:%0.2lf\n", bank[account - 901][1]);
                   }
               }
           }else{
               printf("Failed to read the amount\n");
           }
        }
    }else{
        printf("Failed to read the account number\n");
    }
}
/**
 * this function close a specific account 
 * **/
void C(){
    printf("Please enter account number:");
    int account=0;
   if( scanf("\n%d",&account)) {
       if (account > 950 || account < 901) {
           printf("Invalid account number\n");
       } else if (bank[account - 901][0] == 0) {
           printf("This account is already closed\n");
       } else {
           bank[account - 901][0] = 0;
           bank[account - 901][1] = 0;
           printf("Closed account number %d\n", account);
       }
   }else{
       printf("Failed to read the account number\n");
   }

}
/**
 * this function add deposit according to interest rate  for all account 
 * **/
void I(){
    printf("Please enter interest rate:");
    double interest=0;
   if( scanf("\n%lf",&interest)==1) {
       if (interest <= 0) {
           printf("Invalid interest rate\n");
       } else {
           for (int i = 0; i < 50; i++) {
               if (bank[i][0] == 1) {
                   bank[i][1] += ((bank[i][1] / 100.0) * interest);
               }
           }
       }
   }else{
       printf("Failed to read the interest rate\n");
   }
}
/**
 * this function print the current status   of all accounts in the bank
 * **/
void P(){
    for(int i=0;i<50;i++) {
        if(bank[i][0]==1) {
            printf("The balance of account number %d is: %0.2lf\n", (i + 901), bank[i][1]);
        }
    }
}
/**
 * this function print close the program
 * **/
void E(){
    for(int i=0;i<50;i++){
        bank[i][0]=0;
        bank[i][1]=0;
    }
}
// Created by amichai on 26/11/2020.
//