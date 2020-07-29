// QuicksortHoarePartition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int hoarePartition(int* a, int low, int high);
void quickSort(int* a, int low, int high);

int main()
{
    int a[] = { 5, 3, 8, 4, 2, 7, 1, 10 };
    //int a[] = { 9,2,7,5 };
    //int p = hoarePartition(a, 0, sizeof(a) / sizeof(a[0]) - 1);
    quickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
    printf("Array after sorted : ");
    for (int i = 0; i <= sizeof(a) / sizeof(a[0]) - 1;i++) {
        printf("%d ", a[i]);
    }
}

void quickSort(int* a, int low, int high) {
    if (low < high) {
        int p = hoarePartition(a, low, high);
        quickSort(a, low, p);
        quickSort(a, p+1, high);
    }
}

int hoarePartition(int* a, int low, int high) {
    int i = low-1;
    int j = high + 1;
    int pivot = a[low];
    printf("Array before partition: ");
    for (int k = low; k <= high; k++) {
        printf("%d ", a[k]);
    }
    printf("\n");
    while (true) {
        do {
            i++;
        } while (i <= high && a[i] < pivot);

        do {
            j--;
        } while (j >= low && a[j] > pivot);
        
        if (j <= i)
            break;
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    printf("Array after partition %d: ", j);
    for (int k = low; k <= high; k++) {
        printf("%d ", a[k]);
    }
    printf("\n");
    // when stopping, i is at index >= than to pivot, and j is at index <= than pivot
    return j; // return the first index of number bigger than or equal to the pivot
}