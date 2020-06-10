
// BinarySearchInfinite.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int inFiniteBinarySearch(int* arr, int x);
int indexSearch(int* arr, int n, int x);

int main()
{
    int a[] = { 2, 2, 3, 5, 10, 20, 89, 100, 102, 109, 200, 300, 400, 500, 600, 700, 901, 904, 1920, 19202, 3232323 };
    int b[] = { 1,2,3,4,5,6,8,9,10, 154, 190 };
    printf("Left most of 3 in arr: %d\n", inFiniteBinarySearch(a, 300));
    printf("Left most of 9 in arr: %d\n", inFiniteBinarySearch(b, 153));

    std::cout << "Hello World!\n";
}

int inFiniteBinarySearch(int* arr,  int x) {
    int index;
    int middle = 1;
    while (arr[middle] < x) {
        middle *= 2;
    }
    return indexSearch(arr, middle+1, x);
}

int indexSearch(int* arr, int n, int x) {
    int leftIndex = -1;
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int middle = (low + high) / 2;
        if (arr[middle] == x) {
            leftIndex = middle;
            break;
        }

        if (arr[middle] > x) {
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