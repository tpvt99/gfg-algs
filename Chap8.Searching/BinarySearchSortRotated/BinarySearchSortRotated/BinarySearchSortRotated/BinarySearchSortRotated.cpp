// BinarySearchSortRotated.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

int maxElementInSortRotated(int* a, int n);
int searchSortedandRotatedArray(int* a, int n, int x);

int main()
{
    int a[] = { 10, 20, 40, 1, 5, 6, 7, 9 };
    int b[] = { 20, 1, 2, 3, 4, 5 };
    int c[] = { 20, 30, 40, 50, 60, 1, 2 };
    printf("Max of a: %d\n", searchSortedandRotatedArray(a, sizeof(a) / sizeof(a[0]), 3));
    printf("Max of b: %d\n", searchSortedandRotatedArray(b, sizeof(b) / sizeof(b[0]), 4));
    printf("Max of c: %d\n", searchSortedandRotatedArray(c, sizeof(c) / sizeof(c[0]), 50));
}

int maxElementInSortRotated(int* a, int n) {
    int low = 0;
    int high = n - 1;
    int maxElement = a[0];
    int maxIndex = 0;
    while (low <= high) {
        int middle = (low + high) / 2;
        if (a[middle] > maxElement) {
            maxElement = a[middle];
            maxIndex = middle;
        }
        if (a[middle] > a[low]) {
            low = middle + 1;
        }
        else {
            high = middle - 1;
        }
    }
    return maxIndex;
}

int searchSortedArray(int* a, int low, int high, int x) {
    if (low > high)
        return -1;
    int middle = (low + high) / 2;
    if (a[middle] == x)
        return 1;
    else if (a[middle] > x)
        return searchSortedArray(a, low, middle - 1, x);
    else
        return searchSortedArray(a, middle + 1, high, x);
}

int searchSortedandRotatedArray(int* a, int n, int x) {
    int maxIndex = maxElementInSortRotated(a, n);
    int firstSearch = searchSortedArray(a, 0, maxIndex, x);
    int secondSearch = -1;
    if (maxIndex != (n - 1));
        secondSearch = searchSortedArray(a, maxIndex + 1, n - 1, x);
    printf("MaxIndex: %d First search: %d, second search: %d\n", maxIndex, firstSearch, secondSearch);
    return std::max(firstSearch, secondSearch);

}