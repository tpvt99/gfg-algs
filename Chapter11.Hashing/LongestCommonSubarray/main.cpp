#include <iostream>
#include <unordered_map>

int longestSubarrayWith0Sum(int *a, int n);
int betterMethod(int *a, int *b, int n);

int main() {
    int a1[] = {0, 1, 0, 0, 0, 0};
    int a2[] = {1, 0, 1, 0, 0, 1};
    int b1[] = {0, 0, 0};
    int b2[] = {1, 1, 1};
    int c1[] = {0, 0, 1, 0};
    int c2[] = {1, 1, 1, 1};
    betterMethod(a1, a2, sizeof(a1)/sizeof(a1[0]));
    betterMethod(b1, b2, sizeof(b1)/sizeof(b1[0]));
    betterMethod(c1, c2, sizeof(c1)/sizeof(c1[0]));
    return 0;
}

int longestSubarrayWith0Sum(int *a, int n) {
    std::unordered_map<int, int> m;
    int prefix_sum = 0;
    int max_length = 0;
    for (int i = 0; i < n; i++) {
        prefix_sum += a[i];
        if (prefix_sum == 0) {
            max_length = i+1;
        }
        auto it = m.find(prefix_sum);
        if (it != m.end()) {
            max_length = std::max(max_length, i - it->second);
        } else {
            m.insert({prefix_sum, i});
        }
    }
    return max_length;
}

int betterMethod(int *a, int *b, int n) {
    int *new_array = new int[n];
    for (int i = 0; i < n; i++) {
        new_array[i] = a[i] - b[i];
    }
    int r = longestSubarrayWith0Sum(new_array, n);
    printf("Longest common subarray: %d\n", r);
    return r;
}