// HoarePartition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int hoardPartition(int* a, int low, int high);

int main()
{
    int a[] = { 5,7,1,10,-9,2,35,6,7,-1,-1,-1,-5 };
    hoardPartition(a, 0, sizeof(a) / sizeof(a[0]) - 1);
    
}

int hoardPartition(int* a, int low, int high) {
    int pivot = a[low];
    int i = low, j = high;
    while (true) {
        for (;;) {
            if (a[i] >= pivot)
                break;
            i++;
        }
        for (;;) {
            if (a[j] < pivot)
                break;
            j--;
        }
        if (j <= i)
            break;
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
        

        for (int i = low; i <= high;i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }

    printf("Pivot at %d: ", j);
    for (int i = low; i <= high;i++) {
        printf("%d ", a[i]);
    }
    return j;
}