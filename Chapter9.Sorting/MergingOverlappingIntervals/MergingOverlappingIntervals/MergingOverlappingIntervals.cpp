// MergingOverlappingIntervals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <utility>

bool checkOverlapping(std::pair<int, int> a, std::pair<int, int> b);
void qSort(std::pair<int, int>* pairs, int low, int high);
int partition(std::pair<int, int>* pairs, int low, int high);


int main()
{
    std::pair<int, int> pairs[] = { {1,3}, {2,5}, {10,20}, {30,40}, {25, 90}, {10,20}, {1,9}, {2,7} };
    qSort(pairs, 0, sizeof(pairs) / sizeof(pairs[0])-1);
    printf("{");
    for (int i = 0; i < sizeof(pairs) / sizeof(pairs[0]); i++) {
        printf("{%d, %d} ", pairs[i].first, pairs[i].second);
    }
}

bool checkOverlapping(std::pair<int, int> a, std::pair<int, int> b) {
    if (a.first <= b.second && b.first <= a.second)
        return true;
    return false;
}


void qSort(std::pair<int, int>* pairs, int low, int high) {
    if (low < high) {
        int p = partition(pairs, low, high);
        qSort(pairs, low, p - 1);
        qSort(pairs, p + 1, high);
    }
}

int partition(std::pair<int, int>* pairs, int low, int high) {
    std::pair<int, int> pivot = pairs[high];
    int i = -1;
    for (int j = low; j < high; j++) {
        if (pairs[j].first < pivot.first) {
            i++;
            std::swap(pairs[j], pairs[i]);
        }
    }
    i++;
    std::swap(pairs[i], pivot);
    return i;
}