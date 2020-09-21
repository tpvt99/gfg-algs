#include <iostream>
#include <unordered_map>

void outputDistinctElements(int *a, int n, int k);

int main() {
    int a[] = {1, 4, 5, 6, 7, 8, 3, 4};
    outputDistinctElements(a, sizeof(a)/sizeof(a[0]), 3);
    int b[] = {10, 20, 20, 10, 30, 40, 10};
    outputDistinctElements(b, sizeof(b)/sizeof(b[0]), 4);
    int c[] = {10, 10, 10, 10};
    outputDistinctElements(c, sizeof(c)/sizeof(c[0]), 3);
    return 0;
}

void outputDistinctElements(int *a, int n, int k) {
    std::unordered_map<int, int> m;
    for (int i = 0; i <k; i++) {
        m[a[i]]++;
    }
    printf("%d ", static_cast<int>(m.size()));
    for (int i = k; i <n;i++) {
        m[a[i]]++;
        m[a[i-k]]--;
        if (m.find(a[i-k])->second == 0)
            m.erase(a[i-k]);
        printf("%d ", static_cast<int>(m.size()));
    }
    printf("\n");
}
