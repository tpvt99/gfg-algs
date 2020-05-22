// MaximumSumSubArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int methodNaive(int* a, int n);
int improvedMethod(int* a, int n);

int main()
{
    int a[] = { 2,3,-8,7,-1,2,3 };
    int b[] = { 5, 8, 3 };
    int c[] = { -5, -1, -3 };
    int d[] = { -3, 8, -2, 4, -5, 6 };

    printf("%d\n", methodNaive(a, sizeof(a) / sizeof(a[0])));
    printf("%d\n", methodNaive(b, sizeof(b) / sizeof(b[0])));
    printf("%d\n", methodNaive(c, sizeof(c) / sizeof(c[0])));
    printf("%d\n", methodNaive(d, sizeof(d) / sizeof(d[0])));

    printf("%d\n", improvedMethod(a, sizeof(a) / sizeof(a[0])));
    printf("%d\n", improvedMethod(b, sizeof(b) / sizeof(b[0])));
    printf("%d\n", improvedMethod(c, sizeof(c) / sizeof(c[0])));
    printf("%d\n", improvedMethod(d, sizeof(d) / sizeof(d[0])));
}

int methodNaive(int* a, int n) {
    int maxNum = a[0];
    int currentNum;
    for (int i = 0; i < n-1; i++) {
        currentNum = 0;
        for (int j = i; j < n;j++) {
            currentNum += a[j];
            if (currentNum > maxNum)
                maxNum = currentNum;
        }
    }
    return maxNum;
}

int improvedMethod(int* a, int n) {
    int currentNum = a[0];
    int newNum;
    int maxNum = a[0];
    for (int i = 1; i < n;i++) {
        newNum = currentNum + a[i];
        if (newNum >= a[i]) {
            currentNum = newNum;
        }
        else {
            currentNum = a[i];
        }
        if (currentNum > maxNum)
            maxNum = currentNum;
    }
    return maxNum;
}
