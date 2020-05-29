// PrefixSumEquilibriumPoint.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int querry(int* prefixSum, int left, int right);
bool equilibriumPoint(int* a, int n);
bool improvedEquilibriumPoint(int* a, int n);

int main()
{
    int a[] = { 3, 4, 8, -9, 20, 6 };
    int b[] = { 4, 2, -2 };
    int c[] = { 2, -2, 4 };
    int d[] = { 4, 2, 2 };

    printf("True/False: %d\n", equilibriumPoint(a, sizeof(a) / sizeof(a[0])));
    printf("True/False: %d\n", equilibriumPoint(b, sizeof(b) / sizeof(b[0])));
    printf("True/False: %d\n", equilibriumPoint(c, sizeof(c) / sizeof(c[0])));
    printf("True/False: %d\n", equilibriumPoint(d, sizeof(d) / sizeof(d[0])));

    printf("True/False: %d\n", improvedEquilibriumPoint(a, sizeof(a) / sizeof(a[0])));
    printf("True/False: %d\n", improvedEquilibriumPoint(b, sizeof(b) / sizeof(b[0])));
    printf("True/False: %d\n", improvedEquilibriumPoint(c, sizeof(c) / sizeof(c[0])));
    printf("True/False: %d\n", improvedEquilibriumPoint(d, sizeof(d) / sizeof(d[0])));
}

int querry(int* prefixSum, int left, int right) {
    if (left == 0)
        return prefixSum[right];
    else
        return prefixSum[right] - prefixSum[left - 1];
}

bool equilibriumPoint(int* a, int n) {
    int* prefixSum = new int[n];
    prefixSum[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + a[i];
    }
    int leftSum, rightSum;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            leftSum = 0;
            rightSum = querry(prefixSum, 1, n - 1);
        }
        else if (i == n - 1) {
            leftSum = querry(prefixSum, 0, i - 1);
            rightSum = 0;
        }
        else {
            leftSum = querry(prefixSum, 0, i - 1);
            rightSum = querry(prefixSum, i + 1, n - 1);
        }
        if (leftSum == rightSum)
            return true;
    }
    return false;
}

bool improvedEquilibriumPoint(int* a, int n) {
    int left = 0;
    int right = n - 1;
    int leftSum = 0;
    int rightSum = 0;
    while (left != right) {
        int tempLeftSum = leftSum + a[left];
        int tempRightSum = rightSum + a[right];
        if (tempLeftSum <= tempRightSum) {
            leftSum += a[left];
            left += 1; 
        }
        else if (tempLeftSum > tempRightSum) {
            rightSum += a[right];
            right -= 1;
        }
    }
    if (leftSum == rightSum)
        return true;
    return false;


}