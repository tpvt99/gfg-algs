#include <iostream>
#include <algorithm>
#include <unordered_set>

int naiveMethod(int *a, int n);
int cmp_func(const void *a, const void *b);

int betterMethod(int *a, int n);

int main() {
    int a[] = {1, 9, 3, 4, 2, 20};
    naiveMethod(a, sizeof(a)/sizeof(a[0]));
    int b[] = {8, 20, 7, 30};
    naiveMethod(b, sizeof(b)/sizeof(b[0]));
    int c[] = {10, 20, 30};
    naiveMethod(c, sizeof(c)/sizeof(c[0]));
    return 0;
}

int naiveMethod(int *a, int n) {
    // SOrt the array
    std::qsort(a, n, sizeof(a[0]), cmp_func);
    printf("Array after sorted: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    int max_sequence = 1;
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] - 1 == a[i-1]) {
            count++;
            max_sequence = std::max(count, max_sequence);
        }  else {
            count = 1;
        }
    }
    printf("Max sequence: %d\n", max_sequence);
    return max_sequence;
}

int cmp_func(const void *a, const void *b) {
    const int *p1 = static_cast<const int *>(a);
    const int *p2 = static_cast<const int *>(b);
    if (*p1 < *p2) {
        return -1;
    } else if (*p1 == *p2)
        return 0;
    else
        return 1;
}

int betterMethod(int *a, int n) {
    std::unordered_set<int> m;
    for (int i = 0; i < n;i++)
        m.insert(a[i]);
    int max_length = 0;
    for (int i = 0; i < n; i++) {
        int curr_number = a[i];
        // Search backwards
        int count = 1;
        int find_number = curr_number-1;
        while (m.find(find_number) != m.end()) {
            count++;
            m.erase(find_number);
            find_number--;
        }
        // Search forwards
        find_number = curr_number +1;
        while (m.find(find_number) != m.end()) {
            count++;
            m.erase(find_number);
            find_number++;
        }
        max_length = std::max(count, max_length);
    }
    printf("Max sequence: %d\n", max_length);
    return max_length;
}
