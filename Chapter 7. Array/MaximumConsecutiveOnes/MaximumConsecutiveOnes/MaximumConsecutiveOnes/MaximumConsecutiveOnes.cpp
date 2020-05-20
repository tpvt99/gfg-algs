// MaximumConsecutiveOnes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int maximumOnes(int* a, int n);

int main()
{
    int a[] = { 1,0,1,1,1,1,0,1,1 };
    printf("Max a: %d\n", maximumOnes(a, sizeof(a) / sizeof(a[0])));
    int b[] = { 1,1,1,1 };
    printf("Max a: %d\n", maximumOnes(b, sizeof(b) / sizeof(b[0])));
    int c[] = { 0,1,1,0,1,0 };
    printf("Max a: %d\n", maximumOnes(c, sizeof(c) / sizeof(c[0])));
}


int maximumOnes(int* a, int n) {
    int count = 0;
    int maxCount = 0;
    for (int i = 0; i < n;i++) {
        if (a[i] == 0)
            count = 0;
        else
            count += 1;
        if (count > maxCount)
            maxCount = count;
    }
    return maxCount;
}
