// FrequencyInLimitedArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void countFrequencyNumbers(int* a, int n);

int main()
{
    int a[] = { 1,3,4,5,3,2,4,5,4,3,10 };
    countFrequencyNumbers(a, sizeof(a) / sizeof(a[0]));
}

void countFrequencyNumbers(int* a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = a[i] - 1;
    }
    for (int i = 0; i < n; i++) {
        a[a[i] % n] = a[a[i] % n] + n;
    }
    for (int i = 0; i < n; i++) {
        printf("There are %d of %d\n", a[i] / n, i + 1);
    }
}