//
//  main.c
//  Project2Ctest
//
//  Created by Nathan Blais on 12/2/18.
//  Copyright © 2018 Nathan Blais. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int newBars(int total_bars,int *WraperNum);

int maxBars(int *BarPrice, int *WraperNum, int *CustMoney);

//$ <- this means sudo code in C portion.

int main() {
//It first asks user to enter the price of each BobCat Bar.
    int BarPrice = 0;
    //printf("Enter the price of each BobCat Bar");
    //$input amount and save it to BarPr
    BarPrice = 5; //sumilate imput
    
//It then asks user to enter the number of bar wrappers needed to exchange for a new bar.
    int WraperNum = 0;
   // printf("Enter the number of bar wrappers needed to exchange for a new bar.");
    //$input amount and save it to WraperNum
    WraperNum = 2; //sumilate imput
    
//It then asks user to enter how much money he/she has.
    int CustMoney = 0;
    //printf("Enter how much money you have");
    //$input amount and save it to CustMoney
    CustMoney = 4; //sumilate imput
    
//It then calls maxBars function to perform calculation of the maximum BobCat Bars the user will receive based on the information entered.
    int total_bars = 0;
    total_bars = maxBars(&BarPrice, &WraperNum, &CustMoney);
    
//It then prints out a statement about the maximum BobCat Bars the user will receive.
    printf("With $%d, you will receive a maximum of %d BobCat Bars!.\n",CustMoney ,total_bars);
    return 0;
}

int maxBars(int *BarPrice, int *WraperNum, int *CustMoney){
    int total_bars = 0;
    total_bars = *CustMoney / *BarPrice ;
    printf("Good! Let me run the numbers ...\n");
    if (total_bars != 0){
        printf("You first buy %d bars.\n", total_bars);
        total_bars += newBars(total_bars, WraperNum);
    }
    else
        ;
        
    return total_bars;
}

int newBars(int total_bars,int *WraperNum){ //total_bars will be used for current # of wrapers
    total_bars = total_bars / *WraperNum;
    if(total_bars == 0)
        return 0;
    printf("Then, you will get another %d bars.\n", total_bars  );
    total_bars += newBars(total_bars, WraperNum);
    return total_bars;
}
