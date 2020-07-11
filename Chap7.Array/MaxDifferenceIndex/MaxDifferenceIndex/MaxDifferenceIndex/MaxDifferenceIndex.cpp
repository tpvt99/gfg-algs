// MaxDifferenceIndex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int maxDiffIndex(int* a, int n);

int main()
{
    int a[] = { 34, 8, 10, 3, 2, 80, 30 ,33, 1 };
    printf("Max diff: %d\n", maxDiffIndex(a, sizeof(a) / sizeof(a[0])));
}

int maxDiffIndex(int* a, int n) {
    int minFromLeft = a[0];
    int maxFromRight = a[n - 1];
    int *minLeftArray = new int[n];
    int *maxRightArray = new int[n];

    printf("MinLeft array: ");
    for (int i = 0; i < n; i++) {
        if (a[i] < minFromLeft) {
            minFromLeft = a[i];
        }
        minLeftArray[i] = minFromLeft;
        printf("%d ", minLeftArray[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > maxFromRight) {
            maxFromRight = a[i];
        }
        maxRightArray[i] = maxFromRight;
    }

    printf("\nmaxRight array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", maxRightArray[i]);
    }
    printf("\n");


    int maxDiff = 0;
    for (int first = 0, second = 0; (first <= n - 1) && (second <= n - 1);) {
        printf("Second: %d [%d] and first: %d [%d] with maxDiff: %d\n", second, 
            maxRightArray[second], first, minLeftArray[first],  maxDiff);
        if (maxRightArray[second] >= minLeftArray[first]) {
            if (second - first > maxDiff)
                maxDiff = second - first;
            second++;
        }
        else {
            first++;
        }
        
    }
    return maxDiff;
}