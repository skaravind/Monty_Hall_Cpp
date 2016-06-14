//
//  main.cpp
//  monty hall
//
//  Created by Aravind Krishnan on 06/05/16.
//  Copyright © 2016 Aravind Krishnan. All rights reserved.
//
//Guys I made a program that checks the monty hall paradox! Please write your opinions about it.
//to check the monty hall paradox
#include <iostream>
#include<stdio.h>
#include<time.h>
int wrng,ch,choice,i,j;
long g;
char ag = 'y';
int main()
{
while(ag=='y'||ag=='Y')
{
    long n = 0,count = 0;
    printf("\n\nWELCOME TO THE MONTY HALL PARADOX TESTER!!\n\n\n");
    printf("How many trials do want to test? : ");
    scanf("%ld",&g);
    printf("NOW CHOOSE ANY OPTION BELOW....");
    printf("\n\n1. Stay with the choice of computer for all trials.");
    printf("\n\n2. Switch the choice which the computer chooses.");
    printf("\n\nYOUR CHOICE (1/2) : ");
    scanf("%d",&ch);
    if(ch==1)
    {
        while(n!=g)
        {
            srand(time(0)+n);
            int doors[3] = {0,0,0};
            i = rand()%3;
            doors[i] = 1;
            choice = rand()%3;
            if(doors[choice]==1)
                count++;
            n++;
        }
    }
    else
    {
        while(n!=g)
        {
            srand(time(0)+n);
            int doors[3] = {0,0,0};
            i = rand()%3;
            doors[i] = 1;
            choice = rand()%3;
            for(int k=0;k<3;k++)
            {
                if(doors[k]==0)
                {
                    if(k!=choice)
                        wrng=k;
                }
                else
                    continue;
            }
            int choice1;
            while(1)
            {
                choice1 = rand()%3;
                if(choice1!=choice && choice1!=wrng)
                    goto lb;
                else
                    continue;
            }
        lb:
            if(doors[choice1]==1)
                count++;
            n++;
        }
    }
    printf("OUT OF , %ld YOU WOULD WIN : %ld",g,count);
    printf("\n\n\nTEST AGAIN?...(Y/N) : ");
    scanf("%s",&ag);
    if(ag == 'N' || ag == 'n')
        return 0;
    else if (ag != 'Y' || ag != 'y')
        printf("INVALID RESPONSE");
}
}
