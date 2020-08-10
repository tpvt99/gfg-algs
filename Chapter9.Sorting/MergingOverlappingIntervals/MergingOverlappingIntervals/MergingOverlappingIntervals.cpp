// MergingOverlappingIntervals.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <utility>
#include <algorithm>

bool checkOverlapping(std::pair<int, int> a, std::pair<int, int> b);
void qSort(std::pair<int, int>* pairs, int low, int high);
int partition(std::pair<int, int>* pairs, int low, int high);
void mergeOverlapping(std::pair<int, int>* pairs, int n);

#define DEBUG 0

int main()
{
    std::pair<int, int> pairs[] = { {1,3}, {2,5}, {10,39}, {30,40}, {25, 90}, {10,20}, {1,9}, {2,7} };
    mergeOverlapping(pairs, sizeof(pairs) / sizeof(pairs[0]));
}

void mergeOverlapping(std::pair<int, int>* pairs, int n) {
    // Step 1: Sort the pair
    qSort(pairs, 0, n - 1);
    printf("Pair after merged: {");
    for (int i = 0; i < n-1; i++) {
        printf("{%d, %d} ", pairs[i].first, pairs[i].second);
    }
    printf("}\n");
    printf("Pairs after merged:");
    // Step 2, loop through each elements and merge with nearby
    std::pair<int, int> mergedPair = pairs[0];
    for (int i = 1; i < n; i++) {
        if (checkOverlapping(mergedPair, pairs[i])) {
            mergedPair.second = std::max(mergedPair.second, pairs[i].second);
        }
        else {
            printf("{%d, %d} ", mergedPair.first, mergedPair.second);
            mergedPair = pairs[i];
        }
    }
    printf("{%d, %d} ", mergedPair.first, mergedPair.second);
}

bool checkOverlapping(std::pair<int, int> a, std::pair<int, int> b) {
    if (a.first <= b.second && b.first <= a.second)
        return true;
    return false;
}


void qSort(std::pair<int, int>* pairs, int low, int high) {
    if (low < high) {
#if DEBUG
        printf("Before partition: low %d, high %d: ", low, high);
        for (int i = low; i <= high; i++) {
            printf("{%d, %d} ", pairs[i].first, pairs[i].second);
        }
        printf("\n");
#endif
        int p = partition(pairs, low, high);
#if DEBUG
        printf("After partition: p %d ", p);
        for (int i = low; i <= high; i++) {
            printf("{%d, %d} ", pairs[i].first, pairs[i].second);
        }
        printf("\n");
#endif
        qSort(pairs, low, p - 1);
        qSort(pairs, p + 1, high);
    }
}

int partition(std::pair<int, int>* pairs, int low, int high) {
    std::pair<int, int> pivot = pairs[high];
    int i = low-1;
    for (int j = low; j < high; j++) {
        if (pairs[j].first < pivot.first) {
            i++;
            std::swap(pairs[j], pairs[i]);
        }
    }
    i++;
    std::swap(pairs[i], pairs[high]);
    return i;
}