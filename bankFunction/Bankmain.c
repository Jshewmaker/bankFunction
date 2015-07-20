//
//  main.c
//  bankFunction
//  This program creates a promt for the user to ask them what they want to do and accepts the input
//  Created by Joshua Shewmaker on 2/24/15.
//  Copyright (c) 2015 Joshua Shewmaker. All rights reserved.
//

char menu();
void getDeposit(float *);
void displayBalance(float);
void getWithdraw(float* );

#include <stdio.h>

int main() {
    
    char selection;
    float balance = 0;
    
    selection = menu();

    do {
        switch (selection) {
            case 'D': case 'd':
                getDeposit(&balance);
                break;
            case 'W': case 'w':
                getWithdraw(&balance);
                break;
            case 'B': case 'b':
                displayBalance(balance);
                break;
            case 'Q': case 'q':
                printf("Thank you for using HFC Federal Credit Union. Have a great day!");
                return 0;
                break;
            default:
                printf("Error:invalid choice. Please choose another option\n");
                break;
            }
       selection = menu();
        
    } while (selection != 'q' && selection !='Q');
   
    return 0;
}

char menu(){
    
    char selection;
    
    
    printf("Welcome to HFC Federal Credit Union!");
    printf("\n\nPlease select from the following menu:");
    printf("\n\nD:     Make a Deposit \nW:     Make a Withdrawl \nB:     Check your account balance \nQ:     To quit");
    printf("\n\nInput:");
    scanf("\n%c", &selection);
    
    
    return selection;
}

void getDeposit(float *balance){
    
    float deposite;
    
    printf("How much would you like to deposit?");
    scanf("%f", &deposite);
    
    if (deposite < 0) {
        printf("cannot deposite a negative amount\n");
    }
    
    
    
    *balance = deposite + *balance;
    
    
}

void getWithdraw(float *balance){
 
    float withdraw;
    
    printf("How much money would you like to withdraw?");
    scanf("%f", &withdraw);
    
    
    if (withdraw < 0)
        printf("Cannot withdraw a negative amount\n");
    
    else if (withdraw > *balance){
        do {
            printf("Account overdrawn: Please withdraw a lower amount.\n");
            printf("How much money would you like to withdraw?");
            scanf("%f", &withdraw);
        } while (withdraw > *balance);
        *balance = *balance - withdraw;
           }
    else
        *balance = *balance - withdraw;
    
}

void displayBalance(float balance){
    
    printf("Balance: %.2f\n", balance);
    
    
}

