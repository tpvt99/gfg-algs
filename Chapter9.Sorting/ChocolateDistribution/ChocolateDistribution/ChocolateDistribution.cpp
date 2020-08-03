// ChocolateDistribution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>

int naivePartition(int* a, int low, int high);
void quickSort(int* a, int low, int high);
int chocolateProblem(int* a, int n, int k);

#define DEBUG 0

int main()
{
    int a[] = { 7,3,2,4,9,12,56 };
    int x = chocolateProblem(a, sizeof(a)/sizeof(a[0]), 3);
    printf("Value is: %d\n", x);
}

int chocolateProblem(int* a, int n, int k) {
    // Sort the array a
    quickSort(a, 0, n - 1);
    printf("Array p:");
    for (int i = 0; i < n;i++) {
        printf("%d ", a[i]);
    }
    // Search sequentially and derive the min;
    int minVal = INT_MAX;
    for (int i = 0; i <= n - k;i++) {
        if ((a[i + k-1] - a[i]) < minVal)
            minVal = a[i + k-1] - a[i];
    }
    return minVal;
}

void quickSort(int* a, int low, int high) {
    //printf("In quick sort: low: %d, high : %d\n", low, high);
    if (low < high) {
        int p = naivePartition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int naivePartition(int* a, int low, int high) {
    int pivot = a[high];

    #if DEBUG
    printf("Before: pivot: %d, low: %d, high: %d ", pivot, low, high);
    printf(". Array: ");
    for (int i = low; i <= high; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    #endif


    int* arr = new int[high - low + 1];
    int counter = 0;
    for (int i = low; i <= high; i++) {
        if (a[i] <= pivot)
            arr[counter++] = a[i];
    }
    int p = counter - 1+low;
    for (int i = low; i <= high; i++) {
        if (a[i] > pivot)
            arr[counter++] = a[i];
    }

    for (int i = 0; i <= high - low; i++) {
        a[i + low] = arr[i];
    }
    delete arr;

    #if DEBUG

    printf("After: partition: %d ", p);
    printf(". Array: ");
    for (int i = low; i <= high; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    #endif
    return p;
}
