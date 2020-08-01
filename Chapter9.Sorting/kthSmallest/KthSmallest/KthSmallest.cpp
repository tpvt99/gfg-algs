// KthSmallest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <cstdlib>

void swap(int* a, int* b);
int lomutoPartition(int* a, int low, int high, bool useRandom);
int kthSmallest(int* a, int n, int k);
void qSort(int* a, int low, int high);

int main()
{
    srand((unsigned)time(0));

    int a[] = { 4, 10, 1, 0, 6, 9, 2, 10, 20, 30, 40, 60, -1, -4, -5, -6 };
    //printf("%d smallest is: %d\n", 3, kthSmallest(a, sizeof(a) / sizeof(a[0]), 3));
    printf("%d smallest is: %d\n", 5, kthSmallest(a, sizeof(a) / sizeof(a[0]), 5));

    printf("Array after sorting: ");
    qSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
    for (int i = 0; i < sizeof(a) / sizeof(a[0]);i++) {
        printf("%d ", a[i]);
    }
    std::cout << std::endl;
    printf("%d smallest is %d\n", 3, a[3-1]);
    printf("%d smallest is %d\n", 5, a[5-1]);
}

void qSort(int* a, int low, int high) {
    begin:
    if (low < high) {
        int p = lomutoPartition(a, low, high, false);
        qSort(a, low, p - 1);
        low = p + 1;
        goto begin;
    }
    
}

int kthSmallest(int* a, int n, int k) {
    int low = 0;
    int high = n - 1;
    while (true) {
        int p = lomutoPartition(a, low, high, true);
        printf("hihi\n");
        if ((k - 1) == p) {
            return a[p];
        }
        else if ((k - 1) < p) {
            low = low;
            high = p - 1;
        }
        else if ((k - 1) > p ) {
            low = p + 1;
            high = high;
        }
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int lomutoPartition(int* a, int low, int high, bool useRandom) {
    if (useRandom) {
        int randIndex = (rand() % (high-low+1)) + 1;
        swap(&a[randIndex], &a[high]);
    }
    int pivot = a[high];
    int i = low-1;
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return i + 1;
}

