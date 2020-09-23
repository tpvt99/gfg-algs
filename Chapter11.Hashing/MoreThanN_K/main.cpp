#include <iostream>
#include <unordered_map>

void betterMethod(int *a, int n, int k);
void efficientMethod(int *a, int n, int k);

int main() {
    int a[] = {30, 10, 20, 20, 10, 20, 30, 30};
    int b[] = {30, 10, 20, 30, 30, 40, 30, 40, 30};
    betterMethod(a, sizeof(a)/sizeof(a[0]), 4);
    betterMethod(b, sizeof(b)/sizeof(b[0]), 2);
    efficientMethod(a, sizeof(a)/sizeof(a[0]), 4);
    efficientMethod(b, sizeof(b)/sizeof(b[0]), 2);
    return 0;
}

void betterMethod(int *a, int n, int k) {
    int r = n /k;
    std::unordered_map<int , int> m;
    for (int i = 0; i<n;i++){
        m[a[i]]++;
    }
    for (auto it : m) {
        if (it.second > r)
            printf("%d ", it.first);
    }
    printf("\n");
}

void efficientMethod(int *a, int n, int k) {
    std::unordered_map<int, int>  m;
    for (int i = 0; i<n;i++) {
        if (m.find(a[i]) != m.end()) {
            m[a[i]]++;
        } else if (m.size() < k-1) {
            m.insert({a[i], 1});
        } else {
            for (auto it: m) {
                it.second--;
                if (it.second ==0)
                    m.erase(it.first);
            }
        }
    }
    int r = n/k;
    for (auto it: m) {
        int count = 0;
        for (int i = 0; i < n;i++) {
            if (a[i] == it.first)
                count++;
        }
        if (count > r)
            std::cout << it.first << " ";
    }
    printf("\n");
}
