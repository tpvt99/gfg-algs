// MergeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void mergeSort(int* a, int low, int high);
void mergeTwoSortedArrays(int* a, int low, int middle, int high);

int main()
{
    int a[] = { 32,43, 40, -10, 30, -43, 12, 4, 5,46, 6,7 ,8 ,7,987,9 ,2 ,12,1,21,12};
    mergeSort(a, 0, sizeof(a)/sizeof(a[0])-1);
    printf("array after sorting: ");
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void mergeSort(int* a, int low, int high) {
    if (low < high) {
        int middle = low + (high - low) / 2;
        mergeSort(a, low, middle);
        mergeSort(a, middle + 1, high);
        mergeTwoSortedArrays(a, low, middle, high);
    }
}

// assume that low <= middle < high
void mergeTwoSortedArrays(int* a, int low, int middle, int high) {
    int i, j;
    int* c = new int[high-low+1];
    int counter = 0;
    int maxI;
    for (i = low, j = middle+1; i <= middle && j <= high;) { //because middle is round-down, so if there are 2 elements, middle+1 won't be exceed array's size
        if (a[i] <= a[j]) { // <= to ensure the stability
            c[counter++] = a[i];
            i++;
        }
        else {
            c[counter++] = a[j];
            j++;
        }
    }
    while (i <= middle)
        c[counter++] = a[i++];
    
    while (j <= high)
        c[counter++] = a[j++];
    
    for (i = low; i <= high; i++) {
        a[i] = c[i - low];
    }
    delete c;
}