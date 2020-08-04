// SegregatePositiveNegative.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void naiveMethod(int* a, int low, int high);
void lumotoMethod(int* a, int low, int high);
void swap(int* a, int* b);

int main()
{
    int a[] = { -4, 23, 3,92,-1,-2,-5,-66,100,4,5 };
    naiveMethod(a, 0, sizeof(a) / sizeof(a[0]) - 1);
    printf("Array with naiveMethod: ");
    for (int i = 0; i < sizeof(a) / sizeof(a[0]);i++) {
        printf("%d ", a[i]);
    }
    int b[] = { -4, 23, 3,92,-1,-2,-5,-66,100,4,5 };
    lumotoMethod(a, 0, sizeof(a) / sizeof(a[0]) - 1);
    printf("\nArray with lumotoMethod: ");
    for (int i = 0; i < sizeof(a) / sizeof(a[0]);i++) {
        printf("%d ", a[i]);
    }
}

void naiveMethod(int* a, int low, int high) {
    int* arr = new int[high - low + 1];
    int counter = 0;
    for (int i = low; i <= high; i++) {
        if (a[i] < 0)
            arr[counter++] = a[i];
    }

    for (int i = low;i <= high;i++) {
        if (a[i] >= 0)
            arr[counter++] = a[i];
    }

    for (int i = low;i <= high;i++) {
        a[i] = arr[i];
    }
    delete arr;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void lumotoMethod(int* a, int low, int high) {
    int i = -1;
    for (int j = 0; j <= high; j++) {
        if (a[j] < 0) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
}