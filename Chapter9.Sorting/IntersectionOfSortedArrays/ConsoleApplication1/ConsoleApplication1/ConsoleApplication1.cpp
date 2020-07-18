// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void intersectionOfTwoSortedArrays(int* a, int* b, int n, int m);

int main()
{
    int a[] = { 1,4,6,8,9,9,9,9,10,12,15,19,20 };
    int b[] = { -10,-5,-0, 1, 8, 9, 9, 9, 15, 15, 20,30,40,50 };
    intersectionOfTwoSortedArrays(a, b, sizeof(a) / sizeof(a[0]), sizeof(b) / sizeof(b[0]));
}

void intersectionOfTwoSortedArrays(int* a, int* b, int n, int m) {
    int i, j;
    int previousNumber = 0;
    int flag = 0;
    for (i = 0, j = 0; i < n && j < m;) {
        if (a[i] < b[j]) {
            i++;
        }
        else if (a[i] > b[j]) {
            j++;
        }
        else if (a[i] == b[j]) {
            if (flag == 0) {
                flag = 1;
                previousNumber = a[i];
                std::cout << a[i] << " ";
                i++;
                j++;
            }
            else if (flag == 1) {
                if (a[i] != previousNumber) {
                    previousNumber = a[i];
                    std::cout << a[i] << " ";
                }
                i++;
                j++;
            }
        }
    }
}