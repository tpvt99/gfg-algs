// SegregateArray012s.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void naiveSegregate(int* a, int n);
void lomutoSegregate(int* a, int n);
void hoardSegregate(int* a, int n);

int main()
{
    int a[] = { 0,1,2,1,1,1,2,2,0,0,0,2,1,1,2,1,1,2,1,2,2,2,0,1,2 };
    hoardSegregate(a, sizeof(a)/sizeof(a[0]));
    printf("Array: ");
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        printf("%d ", a[i]);
    }

}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void lomutoSegregate(int* a, int n) {
    int i = -1, j = -1;
    for (int k = 0; k < n;k++) {
        if (a[k] == 1) {
            j++;
            swap(&a[k], &a[j]);
        }
        else if (a[k] == 0) {
            i++;
            swap(&a[i], &a[k]);
            j++;
            swap(&a[j], &a[k]);
        }
    }
}

void hoardSegregate(int* a, int n) {
    int low = -1, middle = -1, high = n;
    int i = 0;
    while ((middle + 1) <= (high - 1)) {
        switch (a[i]) {
        case 2: high--;
            swap(&a[i], &a[high]);
            break;
        case 1: middle++;
            i++;
            break;
        case 0: low++;
            swap(&a[low], &a[i]);
            i++;
            middle++;
            break;
        }
    }
}

void naiveSegregate(int* a, int n) {
    int* new_arr = new int[n];
    int counter = 0;
    int i;
    for (i = 0; i < n;i++) {
        if (a[i] == 0) {
            new_arr[counter++] = a[i];
        }
    }
    for (i = 0; i < n; i++) {
        if (a[i] == 1) {
            new_arr[counter++] = a[i];
        }
    }
    for (i = 0; i < n; i++) {
        if (a[i] == 2) {
            new_arr[counter++] = a[i];
        }
    }
    for (i = 0; i < n; i++) {
        a[i] = new_arr[i];
    }
    delete new_arr;
}
