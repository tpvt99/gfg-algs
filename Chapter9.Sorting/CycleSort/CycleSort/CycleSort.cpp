// CycleSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

#define DEBUG 0

// only for distinct elements
void cycleSort(int* a, int n);

void improvedCycleSort(int* a, int n);

int main()
{
    int a[] = { 20, 40, 30, 10, 20, 20, 30, 40, 90, 70, 10, 40, 30, 20};
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
#if DEBUG
        printf("First cycle at cs: %d, item: %d ..", cs, item);
        printf("Array: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
#endif
        for (int i = cs+1; i < n; i++) {
            if (a[i] < item && a[i] != a[cs]) {
                pos++;
            }
        }
#if DEBUG
        printf("that leads to new pos: %d\n", pos);
#endif
        if (pos == cs)
            continue;

        while (item == a[pos])
            pos++;

        std::swap(item, a[pos]);
#if DEBUG

        printf("Array after swap: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
#endif
        while (pos != cs) {
            pos = cs;
#if DEBUG

            printf("Next cycle at pos: %d and  item: %d", pos, item);
            printf("Array: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", a[i]);
            }
            printf("\n");
#endif
            for (int i = cs+1; i < n; i++) {
#if DEBUG
                printf("item: %d and i : %d, a[i]: %d and cs: %d, a[cs]: %d\n", item, i, a[i], cs, a[cs]);
#endif
                if (a[i] < item) {
                    pos++;
                }
            }
            while (item == a[pos])
                pos++;

            std::swap(item, a[pos]);
#if DEBUG

            printf("that leads to new pos: %d\n", pos);
            printf("Array after swap: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", a[i]);
            }
            printf("\n");
#endif
        }
    }
}