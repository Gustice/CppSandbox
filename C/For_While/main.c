/**
 * @file    main.c
 * @author  VG-13
 * 
 * @brief   C-Programm with a for loop and a while loop 
 *          Compilation and source-dumps are generated with 'runMe.sh'.
 * @version 0.1
 * @date    08.05.2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "stdio.h"
#include "time.h"

int num1 = 0;
int num2 = 1;
int fibo = 0;
int i = 0 ;
int z = 2000000000;

void for_fcn(void);
void while_fcn(void);

void for_fcn(void)
{
    for(i=0; i<z; i++)
    {
        fibo = num1 + num2;
        //Sprintf("Fibonacci-Folge: %d \n", fibo);
        num1 = num2;
        num2 = fibo;
    }
}

void while_fcn(void)
{
    while(i<z)
    {
        fibo = num1 + num2;
        //printf("Fibonacci-Folge: %d \n", fibo);
        num1 = num2;  
        num2 = fibo;
        i++;
    }
}


/* Main to call all functions */
int main(int argc, char const *argv[])
{
    int timeStart;
    int timeEnd;
    int TimeFor = 0;
    int TimeWhile = 0;

    printf("FOR-Schleife: \n");
    timeStart = clock();
    for_fcn();
    timeEnd = clock();
    printf("Anzahl Berechnungen: %d\n", i);
    TimeFor = timeEnd-timeStart;
    printf("Start: %d, Ende: %d, Dauer: %d\n", timeStart, timeEnd, TimeFor);
    num1 = 0;
    num2 = 1;
    i = 0 ;


    printf("WHILE-Schleife: \n");
    timeStart = clock();
    while_fcn();
    timeEnd = clock();
    printf("Anzahl Berechnungen: %d\n", i);
    TimeWhile = timeEnd-timeStart;
    printf("Start: %d, Ende: %d, Dauer: %d\n", timeStart, timeEnd, TimeWhile);

    if(TimeFor > TimeWhile)
    {
        printf("\nDie WHILE-Schleife ist schneller !!!\n");
    }
    else if (TimeFor < TimeWhile)
    {
        printf("\nDie FOR-Schleife ist schneller !!!\n");
    }
    else
    {
        printf("\nFOR- und WHILE-Schleife sind gleich schnell !!!\n");
    } 

    return 0;
}
