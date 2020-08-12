// CycleSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

// only for distinct elements
void cycleSort(int* a, int n);

void improvedCycleSort(int* a, int n);

int main()
{
    int a[] = { 20, 40, 50, 10, 30, 20, 50, 30, 30, 10, 40 };
    improvedCycleSort(a, sizeof(a) / sizeof(a[0]));
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
        printf("%d ", a[i]);
    }
}

void cycleSort(int* a, int n) {
    for (int i = 0; i < n;i++) {
        while (1) {
            int count = 0; // count how many numbers less than a[i]            
            for (int j = 0; j < n; j++) {
                if (a[j] < a[i]) {
                    count += 1;
                }
            }
            std::swap(a[count], a[i]);
            if (count == i) {
                break;
            }
            //printf("i: %d count: %d, first_cycle: %d, old_value: %d\n", i, count, first_cycle, old_value_at_first_cycle);
            for (int i = 0; i < n; i++) {
                printf("%d ", a[i]);
            }
            printf("\n");
        }
    }
}

void improvedCycleSort(int* a, int n) {
    for (int cs = 0; cs < n - 1;cs++) {
        int pos = cs;
        int item = a[cs];
        for (int i = cs+1; i < n; i++) {
            if (a[i] < item) {
                pos++;
            }
        }
        std::swap(item, a[pos]);
        while (pos != cs) {
            pos = cs;
            for (int i = cs+1; i < n; i++) {
                if (a[i] < item) {
                    pos++;
                }
            }
            std::swap(item, a[pos]);
        }
    }
}