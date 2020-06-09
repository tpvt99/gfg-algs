// BinarySearchLeftIndex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int leftMostIndex(int* arr, int n, int x);

int main()
{
    int a[] = { 2, 2, 3, 3, 3, 3 };
    int b[] = { 1,2,3,4,5,6,8,9,9,9,9 };
    printf("Left most of 3 in arr: %d\n", leftMostIndex(a, sizeof(a) / sizeof(a[0]), 3));
    printf("Left most of 9 in arr: %d\n", leftMostIndex(b, sizeof(b) / sizeof(b[0]), 9));

    std::cout << "Hello World!\n";
}

int leftMostIndex(int* arr, int n, int x) {
    int leftIndex = -1;
    int low = 0;
    int high = n - 1;
    while (low <= high) {
       int middle = (low + high) / 2;
       if (arr[middle] == x) {
           leftIndex = middle;
       }

       if (arr[middle] >= x) {
           low = low;
           high = middle - 1;
       }
       else if (arr[middle] < x) {
           low = middle + 1;
           high = high;
       }
    }
    return leftIndex;
}