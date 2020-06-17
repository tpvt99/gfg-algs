// BinarySearchPeak.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int peakElement(int* a, int n) {
    
    int low = 0;
    int high = n - 1;
    if (n == 1)
        return a[0];
    while (low <= high) {
        int middle = (low + high) / 2;
        if (middle == 0 && a[middle] >= a[middle + 1])
            return a[middle];
        else if (middle == n - 1 && a[middle] >= a[middle - 1])
            return a[middle];
        else if (a[middle - 1] <= a[middle] && a[middle] >= a[middle + 1])
            return a[middle];
        else if (a[middle - 1] >= a[middle] && a[middle] >= a[middle + 1]) {
            low = low;
            high = middle - 1;
        }
        else if (a[middle - 1] >= a[middle] && a[middle] <= a[middle + 1]) {
            low = low;
            high = middle - 1;
        }
        else if (a[middle - 1] <= a[middle] && a[middle] <= a[middle + 1]) {
            low = middle + 1;
            high = high;
        }
    }
}

int main()
{
    int a[] = { 20, 3, 4 };
    int b[] = { 1, 2, 20 };
    int c[] = { 5, 10, 20, 15, 7 };
    int d[] = { 10, 30, 40, 55,1,2,3,4,5,6,7,8,9,10,11,12,23,34,45,56,576, 7 };
    printf("Peak element: %d\n", peakElement(a, sizeof(a) / sizeof(a[0])));
    printf("Peak element: %d\n", peakElement(b, sizeof(b) / sizeof(b[0])));
    printf("Peak element: %d\n", peakElement(c, sizeof(c) / sizeof(c[0])));
    printf("Peak element: %d\n", peakElement(d, sizeof(d) / sizeof(d[0])));
}
