// SmallestMissingIntegers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int findMissingSmallestInteger(int* arr, int n);
int partition(int* arr, int n);

int main()
{
    int a[] = { -1,2,3,4,98,- 6,1,5,6,9,8 };
    int b[] = { 1,2,3,4,5 };
    int c[] = { -1,-2,-3,-4,-5 };
    int d[] = { -47, - 50, 31, - 3, - 12, 9, 1, - 15, - 16, - 11, 42, - 35, - 23, - 46, - 21, - 1, 14 ,35, - 21, - 7 ,- 15, 27, - 50, - 12, 21, - 1, 39 ,17, 38 };
    int e[] = { -47, 1, 4, 49, -18, 10, 26, 18, -11, -38, -24, 36, 44 ,-11, 45, 20 ,-16, 28, 17, -49 ,47, -48 ,-33, 42, 2, 6, -49 ,30 ,36 - 9, 15, 39, -6, -31, -10,
        -21, -19, -33, 47, 21, 31, 25, -41, -23, 17, 6, 47, 3, 36, 15, -44, 33 ,-31 ,-26 ,-22, 21, -18, -21 ,-47, -31, 20, 18 ,-42, -35 ,-10, -1, 46, -27, -32 ,
        -5 ,-4, 1, -29, 5, 29 ,38, 14 ,-22 ,-9, 0, 43, -50, -16, 14 ,-26 };

    //printf("Smallest of a: %d\n", findMissingSmallestInteger(a, sizeof(a) / sizeof(a[0])));
    //printf("Smallest of b: %d\n", findMissingSmallestInteger(b, sizeof(b) / sizeof(b[0])));
    //printf("Smallest of c: %d\n", findMissingSmallestInteger(c, sizeof(c) / sizeof(c[0])));
    //printf("Smallest of d: %d\n", findMissingSmallestInteger(d, sizeof(d) / sizeof(d[0])));
    printf("Smallest of e: %d\n", findMissingSmallestInteger(e, sizeof(e) / sizeof(e[0])));

}

int partition(int* arr, int n) {
    int first_pos = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= 0) {
            int temp = arr[i];
            arr[i] = arr[first_pos];
            arr[first_pos] = temp;
            count += 1;
            first_pos++;
        }
    }
    return count;
}

int findMissingSmallestInteger(int* arr, int n) {
    int positiveIndex = partition(arr, n);

    printf("Array after partition %d : ",positiveIndex);
    for (int i = 0; i < n;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (int i = positiveIndex; i < n; i++) {
        int index = abs(arr[i]) + positiveIndex-1;
        if (index >= n || index < 0)
            continue;

        if (arr[index] >=0)
            arr[index] = -arr[index];

        printf("Array after iter %d : ", i);
        for (int j = positiveIndex; j < n;j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");
    }

    printf("Array after partition : ");
    for (int i = positiveIndex; i < n;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (int i = positiveIndex; i < n;i++) {
        if (arr[i] >= 0)
            return i-positiveIndex + 1;
    }
    return n - positiveIndex  + 1; // Return the maximum if arrays all increments by 1
}