// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

void medianOfSortedArrays(int* a, int* b, int low_a, int high_a, int low_b, int high_b);
void betterMedianOfSortedArrays(int* a, int* b, int n_a, int n_b);
void sortedAndBetterMedianOfSortedArrays(int* a, int* b, int n_a, int n_b);


int main()
{
    int a[] = { 1,5,9,10,15,48,99 };
    int b[] = { 3,20,21,25,30};
    medianOfSortedArrays(a, b, 0, sizeof(a) / sizeof(a[0]) - 1, 0, sizeof(b) / sizeof(b[0])-1);
    betterMedianOfSortedArrays(a, b,  sizeof(a) / sizeof(a[0]), sizeof(b) / sizeof(b[0]));
    sortedAndBetterMedianOfSortedArrays(a, b, sizeof(a) / sizeof(a[0]), sizeof(b) / sizeof(b[0]));

}

void betterMedianOfSortedArrays(int* a, int* b, int n_a, int n_b) {
    int n, other_n, * ptr, *other_ptr;
    if (n_a <= n_b) {
        ptr = a;
        other_ptr = b;
        n = n_a;
        other_n = n_b;
    }
    else {
        ptr = b;
        n = n_b;
        other_ptr = a;
        other_n = n_a;
    }

    int low = 0;
    int high = n; // This must be n, not n-1
    int i1, i2;
    float median;
    while (true) {
        int i1 = (low + high) / 2;
        int i2 = (int)((n_a + n_b + 1) / 2) - i1;

        if (i1 == 0) {
            if (i2 > (other_n - 1)) {
                if ((n_a + n_b) % 2 == 0) {
                    printf("Median is: %.2f\n", (other_ptr[other_n - 1] + ptr[0]) / 2.0);
                    return;
                }
                else {
                    printf("Median is: %d\n", other_ptr[other_n - 1]);
                    return;
                }
            }
            else if (i2 <= (n_b - 1)) {
                if ((n_a + n_b) % 2 == 0) {
                    printf("Median is: %.2f\n", (other_ptr[i2 - 1] + min(ptr[i1], other_ptr[i2])) / 2.0);
                    return;
                }
                else {
                    printf("Median is: %d\n", other_ptr[i2 - 1]);
                    return;
                }
            }
        }
        
        if (i1 > (n-1)) {
            if (i2 == 0) {
                if ((n_a + n_b) % 2 == 0) {
                    printf("Median is: %.2f\n", (other_ptr[0] + ptr[n-1]) / 2.0);
                    return;
                }
                else {
                    printf("Median is: %d\n", ptr[n_a - 1]);
                    return;
                }
            }
            else if (i2 > 0) {
                if ((n_a + n_b) % 2 == 0) {
                    printf("Median is: %.2f\n", (max(ptr[n - 1], other_ptr[i2-1]) + other_ptr[i2]) / 2.0);
                    return;
                }
                else {
                    printf("Median is: %d\n", max(other_ptr[i2 - 1], ptr[n-1]));
                    return;
                }
            }
        }

        if (ptr[i1 - 1] <= other_ptr[i2] && other_ptr[i2 - 1] <= ptr[i1]) {
            if ((n_a + n_b) % 2 == 0) {
                printf("Median is: %.2f\n", (max(ptr[i1 - 1], other_ptr[i2 - 1]) + min(ptr[i1], other_ptr[i2])) / 2.0);
                return;
            }
            else {
                printf("Median is: %d\n", max(ptr[i1 - 1], other_ptr[i2 - 1]));
                return;
            }
        }
        else if (ptr[i1 - 1] > other_ptr[i2]) {
            high = i1 - 1;
        }
        else if (other_ptr[i2 - 1] > ptr[i1]) {
            low = i1 + 1;
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

void sortedAndBetterMedianOfSortedArrays(int* a, int* b, int n_a, int n_b) {
    int n, other_n, * ptr, * other_ptr;
    if (n_a <= n_b) {
        ptr = a;
        other_ptr = b;
        n = n_a;
        other_n = n_b;
    }
    else {
        ptr = b;
        n = n_b;
        other_ptr = a;
        other_n = n_a;
    }

    int low = 0;
    int high = n;
    int i1, i2;
    int min1, max1, min2, max2;
    while (true) {
        int i1 = (low + high) / 2;
        int i2 = (int)((n_a + n_b + 1) / 2) - i1;

        max1 = (i1 == 0) ? INT_MIN : ptr[i1 - 1];
        max2 = (i2 == 0) ? INT_MIN : other_ptr[i2 - 1];
        min1 = (i1 == n) ? INT_MAX : ptr[i1];
        min2 = (i2 == (other_n - 1)) ? INT_MAX : other_ptr[i2];
        

        if (max1 <= min2 && max2 <= min1) {
            if ((n_a + n_b) % 2 == 0) {
                printf("Median is: %.2f\n", (max(max1,max2) + min(min1, min2)) / 2.0);
                return;
            }
            else {
                printf("Median is: %d\n", max(max1, max2));
                return;
            }
        }
        else if (max1 > min2) {
            high = i1 - 1;
        }
        else if (max2 > min1) {
            low = i1 + 1;
        }
    }
}