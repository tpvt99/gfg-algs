// MajorityElements.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int majorityElements(int* a, int n);

int main()
{
    int a[] = { 8, 3, 4, 8,8 };
    int b[] = { 3, 7,4,7,7,5 };
    int c[] = { 1,1,2,2,2,2,2,1,1 };
    int d[] = { 4, 4, 2,2,2,4,4 };

    printf("Index of majority of a: %d\n", majorityElements(a, sizeof(a) / sizeof(a[0])));
    printf("Index of majority of b: %d\n", majorityElements(b, sizeof(b) / sizeof(b[0])));
    printf("Index of majority of c: %d\n", majorityElements(c, sizeof(c) / sizeof(c[0])));
    printf("Index of majority of d: %d\n", majorityElements(d, sizeof(d) / sizeof(d[0])));
}

int majorityElements(int* a, int n) {
    int candidate = a[0], count = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == candidate) {
            count += 1;
        }
        else
            count -= 1;
        if (count == 0) {
            candidate = a[i];
            count = 1;
        }
    }
    count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == candidate) {
            count += 1;
        }
        if (count > n / 2)
            return i;
    }
    return -1;
}