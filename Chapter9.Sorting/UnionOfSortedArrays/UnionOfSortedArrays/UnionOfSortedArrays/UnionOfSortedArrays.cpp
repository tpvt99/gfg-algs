// UnionOfSortedArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void unionOfTwoSortedArrays(int* a, int* b, int m, int n);

int main()
{
    int a[] = {1,2,3,5,5,6,7,8,9 };
    int b[] = { 1,3,6,9 };
    unionOfTwoSortedArrays(a, b, sizeof(a) / sizeof(a[0]), sizeof(b) / sizeof(b[0]));
}

void unionOfTwoSortedArrays(int* a, int* b, int m, int n) {
    int i = 0;
    int j = 0;
    int previousNumber = 0;
    if (a[0] < b[0])
        previousNumber = a[0];
    else
        previousNumber = b[0];
    std::cout << previousNumber << " ";
    while (i < m && j < n) {
        if (a[i] == previousNumber) {
            i++;
            continue;
        }
        
        if (b[j] == previousNumber) {
            j++;
            continue;
        }
        if (a[i] < b[j]) {
            previousNumber = a[i];
            i++;
        }
        else {
            previousNumber = b[j];
            j++;
        }
        std::cout << previousNumber << " ";
    }
    while (i < m) {
        if (a[i] != previousNumber) {
            previousNumber = a[i];
            std::cout << previousNumber << " ";
        }
        i++;
    }
    while (j < n) {
        if (b[j] != previousNumber) {
            previousNumber = b[j];
            std::cout << previousNumber << " ";
        }
        j++;
    }
}