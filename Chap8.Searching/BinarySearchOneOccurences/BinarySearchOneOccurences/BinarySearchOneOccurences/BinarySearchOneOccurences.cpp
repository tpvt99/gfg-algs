// BinarySearchLeftIndex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int leftMostIndex(int* arr, int low, int high, int x);
int findOccurence(int* arr, int n, int x);
int rightMostIndex(int* arr, int low, int high, int x);

int main()
{
    int a[] = { 0,0,1,1,1,1,1};
    int b[] = { 1,1,1,1,1,1,1 };
    printf("Occurence of 3 in arr: %d\n", findOccurence(a, sizeof(a) / sizeof(a[0]), 1));
    printf("Occurence of 9 in arr: %d\n", findOccurence(b, sizeof(b) / sizeof(b[0]), 1));

    std::cout << "Hello World!\n";
}

int leftMostIndex(int* arr, int low, int high, int n, int x) {
    int middle = (low + high) / 2;
    if (low > high)
        return -1;
    if (arr[middle] == x && ((middle == 0) || arr[middle - 1] != x))
        return middle;

    if (arr[middle] >= x)
        return leftMostIndex(arr, low, middle - 1, n, x);
    else
        return leftMostIndex(arr, middle + 1, high, n, x);
}

int rightMostIndex(int* arr, int low, int high, int n, int x) {
    int middle = (low + high) / 2;
    if (low > high)
        return -1;
    if (arr[middle] == x && ((middle == n-1) || arr[middle + 1] != x))
        return middle;

    if (arr[middle] > x)
        return rightMostIndex(arr, low, middle - 1, n, x);
    else
        return rightMostIndex(arr, middle + 1, high, n, x);
}

int findOccurence(int* arr, int n, int x) {
    int leftIndex = leftMostIndex(arr, 0, n - 1, n, x);
    int rightIndex = rightMostIndex(arr, 0, n - 1, n, x);

    return rightIndex - leftIndex + 1;
}