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
int i = 0;
int z = 2000000000;

void for_fcn(void);
void while_fcn(void);

void for_fcn(void)
{
    for (i = 0; i < z; i++)
    {
        fibo = num1 + num2;
        //Sprintf("Fibonacci-sequence: %d \n", fibo);
        num1 = num2;
        num2 = fibo;
    }
}

void while_fcn(void)
{
    while (i < z)
    {
        fibo = num1 + num2;
        //printf("Fibonacci-sequence: %d \n", fibo);
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

    printf("FOR-loop: \n");
    timeStart = clock();
    for_fcn();
    timeEnd = clock();
    printf("Number of calculations: %d\n", i);
    TimeFor = timeEnd - timeStart;
    printf("Start: %d, End: %d, Duration: %d\n", timeStart, timeEnd, TimeFor);
    num1 = 0;
    num2 = 1;
    i = 0;

    printf("WHILE-loop: \n");
    timeStart = clock();
    while_fcn();
    timeEnd = clock();
    printf("Number of calculations: %d\n", i);
    TimeWhile = timeEnd - timeStart;
    printf("Start: %d, End: %d, Duration: %d\n", timeStart, timeEnd, TimeWhile);

    if (TimeFor > TimeWhile)
    {
        printf("\nWHILE-loop is faster!!!\n");
    }
    else if (TimeFor < TimeWhile)
    {
        printf("\nFOR-loop is faster!!!\n");
    }
    else
    {
        printf("\nFOR- and WHILE-loop are equally fast!!!\n");
    }

    return 0;
}
