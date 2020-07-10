// MoveZerosToEnd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void move(int* arr, int n);

int main()
{
    int a[] = { 0,0,1,2,4,5,6,0,0 };
    int b[] = { 1,3,4,4,5};
    move(a, sizeof(a) / sizeof(a[0]));
    move(b, sizeof(b) / sizeof(b[0]));
}

void move(int* arr, int n) {
    int zero_count = 0;
    int first_zero_index = -1;
    for (int i = 0; i < n;i++) {
        if (arr[i] == 0)
            zero_count += 1;
        if (arr[i] == 0 && first_zero_index == -1)
            first_zero_index = i;
    }
    if (first_zero_index == -1)
        first_zero_index = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0 && i >= first_zero_index) {
            arr[first_zero_index++] = arr[i];
        }
    }
    for (int i = first_zero_index; i < n;i++)
        arr[i] = 0;

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}