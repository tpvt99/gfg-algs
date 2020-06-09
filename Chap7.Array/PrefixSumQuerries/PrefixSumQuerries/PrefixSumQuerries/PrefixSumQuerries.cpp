// PrefixSumQuerries.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int a[] = { 1, 8, 4, 6, 10, 9, 20 };
int cumulativeSum[7] = { 0 };

int querrySum(int left, int right);

int main()
{
    int sum = 0;
    for (int i = 0; i < sizeof(a) / sizeof(a[0]);i++) {
        sum += a[i];
        cumulativeSum[i] = sum;
    }
    printf("Sum between 0 and 3: %d\n", querrySum(0, 3));
    printf("Sum between 0 and 6: %d\n", querrySum(0, 6));
    printf("Sum between 1 and 4: %d\n", querrySum(1, 4));
    printf("Sum between 3 and 6: %d\n", querrySum(3, 6));
    printf("Sum between 2 and 5: %d\n", querrySum(2, 5));

}

int querrySum(int left, int right) {
    int rightSum = cumulativeSum[right];
    int leftSum = 0;
    if (left > 0)
        leftSum = cumulativeSum[left - 1];
    return rightSum - leftSum;
}