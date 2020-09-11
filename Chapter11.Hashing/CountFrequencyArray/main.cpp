#include <iostream>
#include <unordered_map>

void naiveMethod(int *a, int n);
void betterMethod(int *a, int n);

int main() {
    int a[] = {10, 12, 10, 15, 10, 20, 21,21, 12, 12, 12};
    int b[] = {10, 10, 10, 10};
    printf("Using naive method array a: \n");
    naiveMethod(a, sizeof(a)/sizeof(a[0]));
    printf("Using naive method array b: \n");
    naiveMethod(b, sizeof(b)/sizeof(b[0]));
    printf("Using better method \n");
    betterMethod(a, sizeof(a)/sizeof(a[0]));
    printf("Using better method \n");
    betterMethod(b, sizeof(b)/sizeof(b[0]));
    return 0;
}

// O(n^2) time and O(1) space
void naiveMethod(int *a, int n) {
    for (int i = 0; i < n;i++) {
        int flag = 0;
        for (int j = i - 1;j>=0;j--) {
            if (a[j] == a[i]) {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            continue;
        int count = 1;
        for (int j = i+1; j < n;j++) {
            if (a[i] == a[j])
                count++;
        }
        printf("%d has frequencies: %d\n", a[i], count);
    }
}

void betterMethod(int *a, int n) {
    std::unordered_map<int, int> m;
    for (int i = 0; i < n;i++) {
        auto search = m.find(a[i]);
        if (search != m.end()) {
            search->second = search->second + 1;
        } else {
            m.insert({a[i], 1});
        }
    }
    for (const auto &i : m) {
        printf("%d has frequencies: %d\n", i.first, i.second);
    }
}