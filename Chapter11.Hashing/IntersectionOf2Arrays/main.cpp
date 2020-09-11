#include <iostream>
#include <unordered_map>
#include <unordered_set>

void useMap(int *a, int n_a, int *b, int n_b);
void useSet(int *a, int n_a, int *b, int n_b);

int main() {
    int a[] = {1, 10, 10, 20, 30, 40, 90, 56, 56};
    int b[] = {10, 90, 23, 445, 55, 30, 30, 40};
    useMap(a, sizeof(a)/sizeof(a[0]), b, sizeof(b)/sizeof(b[0]));
    useSet(a, sizeof(a)/sizeof(a[0]), b, sizeof(b)/sizeof(b[0]));
    return 0;
}

void useMap(int *a, int n_a, int *b, int n_b) {
    using std::unordered_map;
    unordered_map<int, int> m;
    for (int i = 0; i < n_a; i++) { // Initialize all keys with value 1. No increase value even duplicates
        auto search = m.find(a[i]);
        if (search == m.end())
            m.insert({a[i], 1});
    }
    for (int i = 0; i < n_b; i++) { // Search keys, if found, increase. If not, do nothing because that is not intersect
        auto search = m.find(b[i]);
        if (search != m.end())
            (search->second)++;
    }

    printf("Intersection of 2 arrays are: ");
    for (auto it : m) {
        if (it.second > 1) {
            printf("%d ", it.first);
        }
    }
    printf("\n");
}

void useSet(int *a, int n_a, int *b, int n_b) {
    using std::unordered_set;
    unordered_set<int>m;
    for (int i = 0; i < n_a; i++) {
        m.insert(a[i]);
    }

    printf("Intersection of 2 arrays are: ");
    for (int i = 0; i < n_b; i++) {
        if (m.count(b[i]) == 1) {
            m.erase(b[i]);
            printf("%d ", b[i]);
        }
    }
}