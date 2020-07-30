// QuickSortTailCallElimination.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <cstdlib>


int lomutoParition(int* a, int low, int high);
void quickSort(int* a, int low, int high);

int main()
{
    srand((unsigned) time(0));
    int a[] = { 10, 80, 30, 20, 70, 90, 50, 1, 2, 3, 4, 90, 94, 3, 4, 5,23, 432,-0,-12,-23,-23,-23,-23 };
    quickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);

    printf("Array: ");
    for (int i = 0; i <= sizeof(a) / sizeof(a[0]) - 1;i++) {
        printf("%d ", a[i]);
    }

}

void quickSort(int* a, int low, int high) {
    begin:
    if (low < high) {
        int p = lomutoParition(a, low, high);
        quickSort(a, low, p - 1);
        low = p + 1;
        high = high;
        goto begin;
    }
}

int lomutoParition(int* a, int low, int high) {
    int i = low - 1;
    int j = low;
    // randomized pivot
    int random_index = (rand() % (high - low+1)) + low;
    // swap [random_index] element with [high] element
    int temp = a[high];
    a[high] = a[random_index];
    a[random_index] = temp;

    int pivot = a[high];
    for (;j < high;j++) {
        if (a[j] <= pivot) {
            i++;
            int temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }
    temp = a[i + 1];
    a[i + 1] = pivot;
    a[high] = temp;
    return i + 1;
}