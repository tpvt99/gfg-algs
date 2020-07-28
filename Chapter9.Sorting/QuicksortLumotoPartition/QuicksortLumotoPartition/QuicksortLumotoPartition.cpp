// QuicksortLumotoPartition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int lumotoParition(int* a, int low, int high);
void quickSort(int* a, int low, int high);

int main()
{
    int a[] = { 10, 80, 30, 20, 70, 90, 50};
    quickSort(a, 0, sizeof(a) / sizeof(a[0])-1);

    printf("Array: ");
    for (int i = 0; i <= sizeof(a) / sizeof(a[0]) - 1;i++) {
        printf("%d ", a[i]);
    }

}

void quickSort(int* a, int low, int high) {
    if (low < high) {
        int p = lumotoParition(a, low, high);
        quickSort(a, low, p-1);
        quickSort(a, p + 1, high);
    }
}

int lumotoParition(int* a, int low, int high) {
    int i = low-1;
    int j = low;
    int pivot = a[high];
    for (;j < high;j++) {
        if (a[j] <= pivot) {
            i++;
            int temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }
    int temp = a[i+1];
    a[i+1] = pivot;
    a[high] = temp;
    return i + 1;
}