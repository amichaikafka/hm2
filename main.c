#include <stdio.h>
#include "myBank.h"

int main() {

    char choice;
    while (choice!='E'){

        printf("Please choose a transaction type:\nO-Open Account\nB-Balance Inquiry\nD-Deposit\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print\nE-Exit\n");

      scanf("\n%c",&choice);
        switch (choice) {
            case 'O':
                O();
                break;
            case 'B':
                B();
                break;
            case 'D':
                D();
                break;
            case 'W':
                W();
                break;
            case 'C':
                C();
                break;
            case 'I':
                I();
                break;
            case 'P':
                P();
                break;
            case 'E':
                E();
                break;

        }

    }
    return 0;
}