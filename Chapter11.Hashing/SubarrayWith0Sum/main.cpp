#include <iostream>
#include <unordered_set>

inline namespace findSum {
    bool isSubarraySum0(int *a, int n) {
        using std::unordered_set;
        int sum = 0;
        unordered_set<int> m;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (m.find(sum) != m.end()) {
                printf("Yes.\n");
                return true;
            }
            if (sum == 0) {
                printf("Yes.\n");
                return true;
            }
            m.insert(sum);
        }
        printf("No.\n");
        return false;
    }
}

int main() {
    int a[] = {1, 4, 13, -4, -10, 5};
    isSubarraySum0(a, sizeof(a)/sizeof(a[0]));
    int b[] = {3, -1, -2, 5};
    isSubarraySum0(b, sizeof(b)/sizeof(b[0]));
    return 0;
}
