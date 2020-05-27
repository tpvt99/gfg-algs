// SlidingWindowNbonacci.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void printNbonacci(int n, int numberDisplay);

int main()
{
    printNbonacci(2, 12);
}

void printNbonacci(int n, int numberDisplay) {
    int* arrayVal = new int[n];
    int sumVal = 1;
    for (int i = 0; i < numberDisplay; i++) {
        printf("Array: ");
        for (int j = 0;j < n;j++)
            printf("%d ", *(arrayVal + j));
        printf("\n");

        if (i < n - 1) {
            *(arrayVal + i) = 0;
            printf("0 ");
        }
        else if (i == n - 1) {
            *(arrayVal + i) = 1;
            printf("1 ");
        }
        else {
            printf("%d ", sumVal);
            int oldSum = sumVal;
            sumVal = 2 * sumVal - (*arrayVal);
            for (int j = 0;j < n - 1;j++)
                *(arrayVal + j) = *(arrayVal + j + 1);
            *(arrayVal + n - 1) = oldSum;
            
            
        }
        printf("-----");
            
    }
}