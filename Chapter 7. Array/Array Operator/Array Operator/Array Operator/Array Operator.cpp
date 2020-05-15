// Array Operator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>

int deleteElement(int* a, int n, int x);

int main()
{
    int a[10] = { 10,20,30,40,50 };
    int n = 5;
    printf("Original array: ");
    for (int i = 0; i < n;i++)
        printf("%d ", a[i]);

    n = deleteElement(a, n, 60);
    printf("\nAfter deleting element 60: ");
    for (int i = 0; i < n;i++)
        printf("%d ", a[i]);

    n = deleteElement(a, n, 20);
    printf("\nAfter deleting element %d: ", 20);
    for (int i = 0; i < n;i++)
        printf("%d ", a[i]);
}



int deleteElement(int* a, int n, int x) {
    int index=-1;
    for (int i = 0; i < n; i++) {
        if (*(a + i) == x) {
            index = i;
            break;
        }
    }

    if (index == -1)
        return n;

    for (int i = index; i < n-1; i++) {
        *(a + i) = *(a + i + 1);
    }
    return n - 1;
}