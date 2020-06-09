// RemoveDuplicates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define N 100

int removeDuplicates(int* a, int n);
int removeDuplicates_NoNeedSpace(int* a, int n);

int main()
{
    std::cout << "Program to remove duplicates in sorted array!\n";
    int a[] = { 10,10,10,20,30,40,50,50,60,60,60 };
    int n = sizeof(a) / sizeof(a[0]);
    n = removeDuplicates_NoNeedSpace(a, n);
    printf("Index: %d\n", n);
    std::cout << "After remove duplicates: ";
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

int removeDuplicates(int* a, int n) {
    int b[N];
    int index = 0;

    for (int i = 0; i < n-1;i++) {
        if (*(a + i) != *(a + i + 1)) {
            b[index] = *(a + i);
            index += 1;
        }
    }
    b[index++] = a[n - 1];

    for (int i = 0; i < index;i++) {
        a[i] = b[i];
    }
    return index;
}

int removeDuplicates_NoNeedSpace(int* a, int n) {
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[index]) {
            index += 1;
            a[index] = a[i];
        }
    }
    return index + 1;
}