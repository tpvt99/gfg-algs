// CoutingSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

void countingSort(int* a, int n, int k);
void generalCountingSort(int* a, int n, int k);
void generalCountingSortWithAnyK(int* a, int n, int k, int min);

int main()
{
    int a[] = { 1, 4, 4, 1, 0, 1, 2, 3, 4, 1, 2, 4 };
    generalCountingSort(a, sizeof(a) / sizeof(a[0]), 5);
    printf("Array after sort: ");
    for (int i = 0;i < sizeof(a) / sizeof(a[0]);i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    int b[] = { -12, -3, -4,21, 32, 43, 12, 1, 3, 4, 5, 6, 1,2, 3,23,-1,02 };
    int k = *std::max_element(b, b + sizeof(b) / sizeof(b[0])) - *std::min_element(b, b + sizeof(b) / sizeof(b[0]))+1;
    generalCountingSortWithAnyK(b, sizeof(b) / sizeof(b[0]), k, *std::min_element(b, b + sizeof(b) / sizeof(b[0])));
    printf("Array after sort: ");
    for (int i = 0;i < sizeof(b) / sizeof(b[0]);i++) {
        printf("%d ", b[i]);
    }
}

void countingSort(int* a, int n, int k) {
    int* counts_k = new int[k];
    // Initialize to be 0
    for (int i = 0; i < k;i++) {
        counts_k[i] = 0;
    }
    // Counts each elements and increment in counts_k array
    for (int i = 0; i < n;i++) {
        counts_k[a[i]] += 1;
    }
    // Reassign back to original a
    int counter = 0;
    for (int i = 0; i < k;i++) {
        for (int j = 0; j < counts_k[i];j++) {
            a[counter++] = i;
        }
    }
}

void generalCountingSort(int* a, int n, int k) {
    int* counts = new int[k];
    // Step 1. Initialize 0s
    for (int i = 0; i < k;i++) {
        counts[i] = 0;
    }
    // Step 2. Counts frequencies
    for (int i = 0; i < n;i++) {
        counts[a[i]]++;
    }
    // Step 3. Accumulate frequencies less than or equal
    for (int i = 1;i < k;i++) {
        counts[i] = counts[i - 1] + counts[i];
    }
    // Step 4. Iterate backwards
    int* outputs = new int[n];
    for (int i = n - 1; i >= 0;i--) {
        int frequencies = counts[a[i]];
        outputs[frequencies - 1] = a[i];
        counts[a[i]] -= 1;
    }
    // Step 5. Copy back outputs[] to a[]
    for (int i = 0; i < n;i++) {
        a[i] = outputs[i];
    }
    delete[] outputs;
    delete[] counts;
}

void generalCountingSortWithAnyK(int* a, int n, int k, int min) {
    int* counts = new int[k];
    // Step 1. Initialize 0s
    for (int i = 0; i < k;i++) {
        counts[i] = 0;
    }
    // Step 2. Counts frequencies
    for (int i = 0; i < n;i++) {
        counts[a[i]-min]++;
    }
    // Step 3. Accumulate frequencies less than or equal
    for (int i = 1;i < k;i++) {
        counts[i] = counts[i - 1] + counts[i];
    }

    // Step 4. Iterate backwards
    int* outputs = new int[n];
    for (int i = n - 1; i >= 0;i--) {
        int frequencies = counts[a[i] - min];
        outputs[frequencies - 1] = a[i];
        counts[a[i] - min] -= 1;
    }
    // Step 5. Copy back outputs[] to a[]
    for (int i = 0; i < n;i++) {
        a[i] = outputs[i];
    }
    delete[] outputs;
    delete[] counts;
}