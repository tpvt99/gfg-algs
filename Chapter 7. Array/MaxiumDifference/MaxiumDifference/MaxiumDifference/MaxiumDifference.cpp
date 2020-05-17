// MaxiumDifference.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int maximumDifference(int* arr, int n);

int main()
{
    int a[] = { 2,3,10,6,4,8,1 };
    printf("Maximum difference of a: %d", maximumDifference(a, sizeof(a) / sizeof(a[0])));
    int b[] = { 7, 9, 5, 6,10, 3, 2 };
    printf("\nMaximum difference of b: %d", maximumDifference(b, sizeof(b) / sizeof(b[0])));
    int c[] = { 30,10,8,2 };
    printf("\nMaximum difference of c: %d", maximumDifference(c, sizeof(c) / sizeof(c[0])));

}

int maximumDifference(int* arr, int n) {
    int minElement = *arr;
    int maxVal = arr[1] - arr[0];
    for (int i = 1; i < n;i++) {
        int temp = arr[i] - minElement;
        if (temp > maxVal)
            maxVal = temp;
        if (arr[i] < minElement)
            minElement = arr[i];
    }
    return maxVal;
}