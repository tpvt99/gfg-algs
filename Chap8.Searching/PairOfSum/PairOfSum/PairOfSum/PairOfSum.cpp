// PairOfSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool pairOfSum(int* a, int n, int x);

int main()
{
    int a[] = { 2, 4, 8, 9, 11, 12, 20, 30 };
    printf("%d\n", pairOfSum(a, sizeof(a) / sizeof(a[0]), 51));
}

bool pairOfSum(int* a, int n, int x) {
    int low = 0;
    int high = n - 1;
    while (low < high) {
        if (a[low] + a[high] == x)
            return true;
        else if (a[low] + a[high] < x)
            low += 1;
        else
            high -= 1;
    }
    return false;
}