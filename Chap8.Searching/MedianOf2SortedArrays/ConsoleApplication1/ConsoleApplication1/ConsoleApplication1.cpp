// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void medianOfSortedArrays(int* a, int* b, int low_a, int high_a, int low_b, int high_b);
void betterMedianOfSortedArrays(int* a, int* b, int n_a, int n_b);

int main()
{
    int a[] = { 1,2,3,4,5,6};
    int b[] = { 10,20,30,40,50, 60, 70 };
    medianOfSortedArrays(a, b, 0, sizeof(a) / sizeof(a[0]) - 1, 0, sizeof(b) / sizeof(b[0])-1);
}

void betterMedianOfSortedArrays(int* a, int* b, int n_a, int n_b) {
    int n, * ptr, *other_ptr;
    if (n_a <= n_b) {
        ptr = a;
        other_ptr = b;
        n = n_a; 
    }
    else {
        ptr = b;
        n = n_b;
        other_ptr = a;
    }

    int low = 0;
    int high = n - 1;
    int i1, i2;
    float median;
    while (true) {
        int i1 = (low + high) / 2;
        int i2 = (int)((n_a + n_b + 1) / 2) - i1;
        if (i1 == 0) {
            median = (ptr[i1] + other_ptr[i2 - 1]) / 2;
        }
    }
}

// Naive Solution O(n) using mergeSort
void medianOfSortedArrays(int* a, int* b, int low_a, int high_a, int low_b, int high_b) {
    int numbers = high_a - low_a + high_b - low_b + 2;
    int median = numbers / 2;
    if (numbers % 2 == 0)
        median = median - 1;
    int counter = 0;
    int i, j;
    bool i_change = false;
    bool t = numbers % 2;
    float median_sum = 0.f;
    for (i = low_a, j = low_b; i <= high_a && j <= high_b; ) {
        
        if (a[i] <= b[j]) {
            i++;
            i_change = true;
        }
        else if (a[i] > b[j]) {
            j++;
            i_change = false;
        }
        if (counter == median) {
            median_sum = median_sum + (i_change ? a[i-1] : b[j-1]);
            if (numbers % 2 == 0) {
                median += 1;
                numbers -= 1;
            }
            else {
                median = -1;
            }
            printf("median: %d, counter: %d, median add: %d\n", median, counter, (i_change ? a[i-1] : b[j-1]));
        }
        counter++;
        
        
    }
    for (;i <= high_a;i++) {
        if (counter == median) {
            median_sum = median_sum + a[i];
            if (numbers % 2 == 0) {
                median += 1;
                numbers -= 1;
            }
            else {
                median = -1;
            }
            printf("median: %d, counter: %d, median add: %d\n", median, counter, (i_change ? a[i - 1] : b[j - 1]));
        }

        counter++;
    }
    for (;j <= high_b;j++) {
        if (counter == median) {
            median_sum = median_sum + b[j];
            if (numbers % 2 == 0) {
                median += 1;
                numbers -= 1;
            }
            else {
                median = -1;
            }
            printf("median: %d, counter: %d, median add: %d\n", median, counter, (i_change ? a[i - 1] : b[j - 1]));
        }
        counter++;
    }
    printf("median_sum: %f, median: %f\n", median_sum, (t) ? median_sum : median_sum/2);
}

