// LeftRotate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void leftRotateByOne(int* arr, int n);
void leftRotateByD(int* arr, int n, int d);
void leftRotateByDImproved(int* arr, int n, int d);

int main()
{
    int arr[] = { -12,32,43,54,65 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Array before left rotate by 1: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nArray after left rotate by 1: ");
    leftRotateByOne(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    int d = 3;
    std::cout << std::endl;
    leftRotateByDImproved(arr, n, d);
    printf("\nArray before left rotate by %d: ", d);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void leftRotateByOne(int* arr, int n) {
    int temp = *(arr);
    for (int i = 0; i < n - 1; i++)
        *(arr + i) = *(arr + i + 1);
    *(arr + n - 1) = temp;
}

// O(n) Time O(d) Space
void leftRotateByD(int* arr, int n, int d) {
    int* temp = new int[d];
    int index_chosen;
    for (int i = 0; i < n;i++) {
        index_chosen = i + d;
        if (i < d)
            *(temp + i) = *(arr + i);
        if (index_chosen < n) {
            *(arr + i) = *(arr + index_chosen);
        }
        else if (index_chosen >= n) {
            index_chosen = index_chosen % n;
            *(arr + i) = *(temp + index_chosen);
        }
    }
}
// O(n) Time O(1) Space
void leftRotateByDImproved(int* arr, int n, int d) {
    int temp;
    for (int i = d; i < n; i++) {
        temp = arr[i - d];
        arr[i - d] = arr[i];
        arr[i] = temp;
    }
    for (int i = 0; i < d - (n % d); i++)
        leftRotateByOne(arr + n-d, d);
}

