// SlidingWindow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int maximumKWindow(int* a, int n, int k);
int checkSumSubArray(int* a, int n, int sum);

int main()
{
    int a[] = { -1, -2, -3, -9, -10 };
    int b[] = { 1, 8, 30, -5, 20, 7 };
    int c[] = { 5, -10, 6, 90,3 };

    printf("Max sum: %d\n", maximumKWindow(a, sizeof(a) / sizeof(a[0]), 3));
    printf("Max sum: %d\n", maximumKWindow(b, sizeof(b) / sizeof(b[0]), 3));
    printf("Max sum: %d\n", maximumKWindow(c, sizeof(c) / sizeof(c[0]), 2));

    int d[] = { 1,4,20,3,10,5 };
    int e[] = { 1,4,0,0,3,10,5 };
    int f[] = { 2, 4 };

    printf("Check sum: %d\n", checkSumSubArray(d, sizeof(d) / sizeof(d[0]), 33));
    printf("Check sum: %d\n", checkSumSubArray(e, sizeof(e) / sizeof(e[0]), 7));
    printf("Check sum: %d\n", checkSumSubArray(f, sizeof(f) / sizeof(f[0]), 4));
}

int maximumKWindow(int* a, int n, int k) {
    int sum = 0;
    int maxSum = a[0];
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (i >= k)
            sum -= a[i - k];
        if (sum >= maxSum)
            maxSum = sum;
    }
    return maxSum;
}

int checkSumSubArray(int* a, int n, int sum) {
    int sumVal = 0;
    int firstIndex = 0;
    for (int i = 0; i < n; i++) {
        sumVal += a[i];
        if (sumVal == sum)
            return 1;
        else if (sumVal > sum) {
            for (;firstIndex < i;firstIndex++) {
                sumVal -= a[firstIndex];
                if (sumVal < sum)
                    break;
                else if (sumVal == sum)
                    return 1;
            }
        }
    }
    return 0;
}