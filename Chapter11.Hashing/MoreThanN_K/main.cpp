#include <iostream>
#include <unordered_map>

void betterMethod(int *a, int n, int k);

int main() {
    int a[] = {30, 10, 20, 20, 10, 20, 30, 30};
    betterMethod(a, sizeof(a)/sizeof(a[0]), 4);
    int b[] = {30, 10, 20, 30, 30, 40, 30, 40, 30};
    betterMethod(b, sizeof(b)/sizeof(b[0]), 2);
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
