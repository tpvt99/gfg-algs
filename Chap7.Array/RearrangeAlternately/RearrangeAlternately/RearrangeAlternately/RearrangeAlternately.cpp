// RearrangeAlternately.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void rearrangeAlternately(int* a, int n);

int main()
{
    int a[] = { 1,2,4,6,7,8,9 };
    int b[] = { 3,4,5,7,10,12 };
    int c[] = { 2,2,5,6,8,9,10,12 };
    int d[] = { 1,1,3,3,10,10 };

    rearrangeAlternately(a, sizeof(a) / sizeof(a[0]));
    rearrangeAlternately(b, sizeof(b) / sizeof(b[0]));
    rearrangeAlternately(c, sizeof(c) / sizeof(c[0]));
    rearrangeAlternately(d, sizeof(d) / sizeof(d[0]));

}

void rearrangeAlternately(int* a, int n) {
    int srcMaxIndex = n - 1;
    int srcMinIndex = 0;
    int destMaxIndex = 0;
    int destMinIndex = 1;
    int maxNumber = a[n - 1];

    while (srcMinIndex <= srcMaxIndex) {
        int srcMax = a[srcMaxIndex];
        if (srcMax <= maxNumber)
            srcMax = srcMax;
        else
            srcMax = srcMax % maxNumber;
        a[destMaxIndex] = a[destMaxIndex] + srcMax * maxNumber;

        if (destMinIndex >= n)
            break;

        int srcMin = a[srcMinIndex];
        if (srcMin <= maxNumber)
            srcMin = srcMin;
        else
            srcMin = srcMin % maxNumber;
        a[destMinIndex] = a[destMinIndex] + srcMin * maxNumber;
        srcMaxIndex -= 1;
        srcMinIndex += 1;
        destMaxIndex += 2;
        destMinIndex += 2;
    }

    for (int i = 0; i < n;i++) {
        if (a[i] % maxNumber != 0)
            a[i] = a[i] / maxNumber;
        else
            a[i] = a[i] / maxNumber - 1;

    }
    
    printf("Array after rearanged: ");
    for (int i = 0; i < n;i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}