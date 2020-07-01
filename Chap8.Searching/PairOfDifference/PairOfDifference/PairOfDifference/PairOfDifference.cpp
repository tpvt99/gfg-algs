// PairOfDifference.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void findPairsDifference(int* a, int low, int high, int diff);

int main()
{
    int arr[] = { 1, 3, 4, 5, 6, 7, 8, 10, 12, 16, 20, 40, 60, 99 };
    findPairsDifference(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1, 20);
}

void findPairsDifference(int* a, int low, int high, int diff) {
    int* small_ptr = a;
    int *big_ptr = a + 1;
    while (big_ptr <= a+high) {
        if (*big_ptr - *small_ptr == diff) {
            printf("|%d-%d|=%d\n", *big_ptr, *small_ptr, diff);
            return;
        }
        else if (*big_ptr - *small_ptr < diff) {
            big_ptr++;
        }
        else if (*big_ptr - *small_ptr > diff) {
            small_ptr++;
        }
    }
    printf("No pairs");
    return;
}