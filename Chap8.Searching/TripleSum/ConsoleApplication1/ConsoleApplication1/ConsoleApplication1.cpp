// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool pairOfSum(int* a, int skip_index, int low, int high, int x);
bool tripleOfSum(int* a, int n, int x);


int main()
{
    int a[] = { 2, 3, 4, 8, 9, 20, 40 };
    printf("%d\n", tripleOfSum(a, sizeof(a) / sizeof(a[0]), 100));

}

bool tripleOfSum(int* a, int n, int x) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    for (int i = 0; i < n; i++) {
        int new_x = x - a[i];
        bool result = pairOfSum(a, i, 0, n - 1, new_x);
        printf("index skipped: %d, result: %d\n", i, result);
        if (result == true)
            return true;
    }
    return false;
}

bool pairOfSum(int* a, int skip_index, int low, int high, int x) {
    if (low == skip_index)
        low += 1;
    if (high == skip_index)
        high -= 1;
    while (low < high) {
        printf("low: %d, high:%d, sum: %d\n", low, high, a[low]+a[high]);
        if (a[low] + a[high] == x)
            return true;
        else if (a[low] + a[high] < x) {
            low += 1;
            if (low == skip_index)
                low += 1;
        }
        else {
            high -= 1;
            if (high == skip_index)
                high -= 1;
        }
    }
    return false;
}