#include <iostream>
#include <unordered_set>

void findSumOfPairs(int *a, int n, int sum);

int main() {
    int a[] = {3, 2, 8, 15, -8};
    findSumOfPairs(a, sizeof(a) /sizeof(a[0]), 17);
    int b[] = {12, 98, -32, -43, 1 , 0, -32};
    findSumOfPairs(b, sizeof(b) /sizeof(b[0]), -33);
    int c[] = {11, 5,5,6};
    findSumOfPairs(c, sizeof(c) /sizeof(c[0]), 10);
    return 0;
}

void findSumOfPairs(int *a, int n, int sum) {
    using std::unordered_set;
    unordered_set<int> m;
    for (int i = 0; i < n; i++) {
        if (m.find(a[i]) == m.end()) {
            m.insert(sum - a[i]);
        } else {
            printf("There is a pair: %d and %d\n", a[i], sum - a[i]);
            return;
        }
    }
    printf("There is no such pair.\n");
}
