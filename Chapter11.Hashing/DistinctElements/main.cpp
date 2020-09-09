#include <iostream>
#include <unordered_set>

int countDistinctElements(int *a, int n);

int main() {
    int a[] = {1,2,3};
    int b[] = {1,1,1};
    int c[] = {12,32,43, -12, 32,32,32};
    printf("Number of distinct elements in a: %d\n", countDistinctElements(a, sizeof(a)/sizeof(a[0])));
    printf("Number of distinct elements in b: %d\n", countDistinctElements(b, sizeof(b)/sizeof(b[0])));
    printf("Number of distinct elements in c: %d\n", countDistinctElements(c, sizeof(c)/sizeof(c[0])));
    return 0;
}

int countDistinctElements(int *a, int n) {
    std::unordered_set<int> m;
    for (int i = 0; i < n; i++) {
        m.insert(a[i]);
    }
    return m.size();
}
