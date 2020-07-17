// InsertionSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void insertionSortAscending(int* a, int n);
void insertionSortDescending(int* a, int n);

int main()
{
    int a[] = { 3,4,51,2,-9,-5,-12,32,43,54,76,87 };
    int b[] = { 1,3,4,6,8 };
    int c[] = { 9, 7, 5, 4, 1, -12 };

    insertionSortAscending(a, sizeof(a) / sizeof(a[0]));
    insertionSortAscending(b, sizeof(b) / sizeof(b[0]));
    insertionSortAscending(c, sizeof(c) / sizeof(c[0]));

    insertionSortDescending(a, sizeof(a) / sizeof(a[0]));
    insertionSortDescending(b, sizeof(b) / sizeof(b[0]));
    insertionSortDescending(c, sizeof(c) / sizeof(c[0]));

}

void insertionSortAscending(int* a, int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int current_index = i-1;
        while (current_index >= 0 && a[current_index] > key) {
            a[current_index + 1] = a[current_index];
            current_index -= 1;
        }
        a[current_index + 1] = key;
    }
    
    printf("Array after ascendingly sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insertionSortDescending(int* a, int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int current_index = i - 1;
        while (current_index >= 0 && a[current_index] < key) {
            a[current_index + 1] = a[current_index];
            current_index -= 1;
        }
        a[current_index + 1] = key;
    }

    printf("Array after ascendingly sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
