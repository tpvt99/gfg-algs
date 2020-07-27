// LumotoPartition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int lumotoPartition(int* a, int low, int high);

int main()
{
    int a[] = { 10, 80, 30, 90, 40, 50 };
    lumotoPartition(a, 0, sizeof(a) / sizeof(a[0]) - 1);
}

int lumotoPartition(int* a, int low, int high) {
    int pivot = a[high];
    int i = low-1;
    int j = low;
    for (;j < high;j++) {
        if (a[j] <= pivot) {
            int temp = a[j];
            a[j] = a[i+1];
            a[i+1] = temp;
            i++;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = pivot;
    a[high] = temp;

    printf("Parition index at %d and array: ", i + 1);
    for (int i = 0; i <= high; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return i + 1;
}