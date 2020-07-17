// MaximumCircularSumSubArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

int naiveMethod(int* a, int n);
int improveMethod(int* a, int n);
int helperMinimumSubArray(int* a, int n);
int helperMaximumSubArray(int* a, int n);

int main()
{
    int a[] = { 5, -2, 3, 4 };
    int b[] = { 2,3,-4 };
    int c[] = { 8, -4, 3, -5, 4 };
    int d[] = { -3, 4, 6, -2 };
    int e[] = { -8,7,6 };
    int f[] = { 3,-4,5,6,-8,7 };
    int g[] = { -18 };

    printf("Max sum: %d\n", naiveMethod(a, sizeof(a) / sizeof(a[0])));
    printf("Max sum: %d\n", naiveMethod(b, sizeof(b) / sizeof(b[0])));
    printf("Max sum: %d\n", naiveMethod(c, sizeof(c) / sizeof(c[0])));
    printf("Max sum: %d\n", naiveMethod(d, sizeof(d) / sizeof(d[0])));
    printf("Max sum: %d\n", naiveMethod(e, sizeof(e) / sizeof(e[0])));
    printf("Max sum: %d\n", naiveMethod(f, sizeof(f) / sizeof(f[0])));
    printf("Max sum: %d\n", naiveMethod(g, sizeof(g) / sizeof(g[0])));

    printf("Max sum: %d\n", improveMethod(a, sizeof(a) / sizeof(a[0])));
    printf("Max sum: %d\n", improveMethod(b, sizeof(b) / sizeof(b[0])));
    printf("Max sum: %d\n", improveMethod(c, sizeof(c) / sizeof(c[0])));
    printf("Max sum: %d\n", improveMethod(d, sizeof(d) / sizeof(d[0])));
    printf("Max sum: %d\n", improveMethod(e, sizeof(e) / sizeof(e[0])));
    printf("Max sum: %d\n", improveMethod(f, sizeof(f) / sizeof(f[0])));
    printf("Max sum: %d\n", improveMethod(g, sizeof(g) / sizeof(g[0])));
}

int naiveMethod(int* a, int n) {
    int currentVal, maxVal = a[0];
    for (int i = 0; i < n ;i++) {
        currentVal = 0;
        for (int j = 0; j < n;j++) {
            currentVal += a[(j+i)%n];
            maxVal = std::max(currentVal, maxVal);
        }
    }
    return maxVal;
}

int improveMethod(int* a, int n) {
    int maxSubArray = helperMaximumSubArray(a, n);
    if (maxSubArray < 0)
        return maxSubArray;
    int temp = 0;
    for (int i = 0; i < n; i++) {
        temp += a[i];
    }
    int minSubArray = helperMinimumSubArray(a, n);
    temp = temp - minSubArray;
    return std::max(maxSubArray, temp);
}



int helperMinimumSubArray(int* a, int n) {
    int minVal = a[0];
    int currentVal = 0;
    for (int i = 0; i < n;i++) {
        currentVal += a[i];
        if (currentVal > a[i])
            currentVal = a[i];
        if (currentVal < minVal)
            minVal = currentVal;
    }
    return minVal;
}

int helperMaximumSubArray(int* a, int n) {
    int maxVal = a[0];
    int currentVal = 0;
    for (int i = 0; i < n;i++) {
        currentVal += a[i];
        if (currentVal < a[i])
            currentVal = a[i];
        if (currentVal > maxVal)
            maxVal = currentVal;
    }
    return maxVal;
}
