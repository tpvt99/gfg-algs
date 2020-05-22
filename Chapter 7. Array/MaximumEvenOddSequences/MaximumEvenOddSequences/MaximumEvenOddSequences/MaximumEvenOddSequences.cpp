// MaximumEvenOddSequences.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

int maximumLengthEvenOdd(int* a, int n);

int main()
{
    int a[] = { 10,12,14,7,8 };
    int b[] = { 10,20,30 };
    int c[] = { 7,10,13,14 };

    printf("Max odd-even sequence: %d\n", maximumLengthEvenOdd(a, sizeof(a) / sizeof(a[0])));
    printf("Max odd-even sequence: %d\n", maximumLengthEvenOdd(b, sizeof(b) / sizeof(b[0])));
    printf("Max odd-even sequence: %d\n", maximumLengthEvenOdd(c, sizeof(c) / sizeof(c[0])));
}

int maximumLengthEvenOdd(int* a, int n) {
    int maxLength = 1;
    int isEven = a[0] % 2;
    int currentLength = 1;
    for (int i = 1; i < n; i++) {
        if ((a[i] % 2) != isEven) {
            currentLength += 1;
        }
        else {
            currentLength = 1;
        }
        maxLength = std::max(currentLength, maxLength);
        isEven = a[i] % 2;
    }
    return maxLength;
}