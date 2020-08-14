// CoutingSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void countingSort(int* a, int n, int k);

int main()
{
    int a[] = { 1, 4, 4, 1, 0, 1, 2, 3, 4, 1, 2, 4 };
    countingSort(a, sizeof(a) / sizeof(a[0]), 5);
    printf("Array after sort: ");
    for (int i = 0;i < sizeof(a) / sizeof(a[0]);i++) {
        printf("%d ", a[i]);
    }
}

void countingSort(int* a, int n, int k) {
    int* counts_k = new int[k];
    // Initialize to be 0
    for (int i = 0; i < k;i++) {
        counts_k[i] = 0;
    }
    // Counts each elements and increment in counts_k array
    for (int i = 0; i < n;i++) {
        counts_k[a[i]] += 1;
    }
    // Reassign back to original a
    int counter = 0;
    for (int i = 0; i < k;i++) {
        for (int j = 0; j < counts_k[i];j++) {
            a[counter++] = i;
        }
    }
}
