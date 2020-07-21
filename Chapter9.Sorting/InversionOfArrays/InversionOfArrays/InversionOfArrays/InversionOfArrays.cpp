// InversionOfArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int inspiredMergedSort(int* a, int low, int high);
int countInversion(int* a, int low, int middle, int high);

int main()
{
    int a[] = { 2,3,2,2,3};
    printf("Number of inversion: %d\n", inspiredMergedSort(a, 0, 4));
}

int inspiredMergedSort(int* a, int low, int high) {
    int n = 0;
    if (low < high) {
        int middle = (high + low) / 2;
        return + inspiredMergedSort(a, low, middle) + inspiredMergedSort(a, middle + 1, high) + countInversion(a, low, middle, high);
    }
    return 0;
}

int countInversion(int* a, int low, int middle, int high) {
    int i = low;
    int j = middle + 1;
    int* c = new int[high - low + 1];
    int counter = 0;
    int count = 0;
    while (i <= middle && j <= high) {
        if (a[i] > a[j]) {
            count += (high - middle - (j-middle-1));
            c[counter] = a[i];
            i++;
            counter += 1;
            
        }
        else if (a[i] <= a[j]) {
            c[counter] = a[j];
            j++;
            counter += 1;
        }
    }
    while (i <= middle) {
        c[counter++] = a[i++];
    }
    while (j <= high) {
        c[counter++] = a[j++];
    }
    for (i = low; i <= high; i++) {
        a[i] = c[i - low];
    }
    delete c;
    return count;
}