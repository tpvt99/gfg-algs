#include <iostream>
#include <algorithm>
#include <cmath>

typedef struct numIndex {
    int realNumber;
    int indexElement;
} numIndex;

void generalCountingSortWithIndex(numIndex *a, int n, int k);
void radixSort(int *a, int n);


int main() {
    int a[] = {319, 212, 006, 8, 100, 50, 1, 39, 23, 12, 30, 43, 32,2};
    radixSort(a, sizeof(a)/sizeof(a[0]));
    printf("Array after sort: ");
    for (int i = 0; i < sizeof(a)/sizeof(a[0]);i++) {
        printf("%d ", a[i]);
    }
    return 0;
}

void radixSort(int *a, int n) {
    int maxElement = *std::max_element(a, a+n);
    int numberOfDigits = int(std::log10(static_cast<float>(maxElement))) + 1;
    // Step 1. Construct the numIndex to contain the index and its corresponding number
    numIndex *newType = new numIndex[n];
    for (int i = 0; i <n; i++) {
        (newType+i)->indexElement = 0;
        (newType+i)->realNumber = a[i];
    }

    for (int digit = 0; digit < numberOfDigits; digit++) {
        for (int i = 0; i <n;i++) {
           newType[i].indexElement = (newType[i].realNumber/static_cast<int>(pow(10, digit))) % 10;
        }
        generalCountingSortWithIndex(newType, n, 10);
    }
    for (int i = 0; i <n ; i++) {
        a[i] = newType[i].realNumber;
    }
    delete[] newType;
}


void generalCountingSortWithIndex(numIndex* a, int n, int k) {
    int* counts = new int[k];
    // Step 1. Initialize 0s
    for (int i = 0; i < k;i++) {
        counts[i] = 0;
    }
    // Step 2. Counts frequencies
    for (int i = 0; i < n;i++) {
        counts[a[i].indexElement]++;
    }
    // Step 3. Accumulate frequencies less than or equal
    for (int i = 1;i < k;i++) {
        counts[i] = counts[i - 1] + counts[i];
    }
    // Step 4. Iterate backwards
    numIndex * outputs = new numIndex[n];
    for (int i = n - 1; i >= 0;i--) {
        int frequencies = counts[a[i].indexElement];
        outputs[frequencies - 1].indexElement = a[i].indexElement;
        outputs[frequencies - 1].realNumber = a[i].realNumber;
        counts[a[i].indexElement] -= 1;
    }
    // Step 5. Copy back outputs[] to a[]
    for (int i = 0; i < n;i++) {
        a[i].indexElement = outputs[i].indexElement;
        a[i].realNumber = outputs[i].realNumber;
    }
    delete[] outputs;
    delete[] counts;
}