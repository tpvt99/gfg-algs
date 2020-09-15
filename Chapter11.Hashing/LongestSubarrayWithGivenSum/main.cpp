#include <iostream>
#include <unordered_map>

int longestSubarray(int *a, int n, int sum);

int main() {
    int a[] = {5, 8, -4, -4, 9, -2, 2};
    longestSubarray(a, sizeof(a)/sizeof(a[0]), 0);
    int b[] = {3, -2, -1};
    longestSubarray(b, sizeof(a)/sizeof(a[0]), 0);
    int c[] = {8, 3, 7};
    longestSubarray(c, sizeof(c)/sizeof(c[0]), 0);
    int d[] = {3, 2, 0, 0};
    longestSubarray(d, sizeof(d)/sizeof(d[0]), 5);
    int e[] = {8, 3, 1, 5, 6, -6, 2, 2};
    longestSubarray(e, sizeof(e)/sizeof(e[0]), 4);
    return 0;
}

int longestSubarray(int *a, int n, int sum) {
    std::unordered_map<int, int> m;
    int prefix_sum = 0;
    int max_length = 0;
    for (int i = 0; i < n; i++) {
        prefix_sum += a[i];
        auto it = m.find(prefix_sum - sum);
        if (it != m.end()) {
            if (i-it->second > max_length) {
                max_length = i - it->second;
            }
        } else {
            m.insert({prefix_sum, i});
        }
        if (prefix_sum == sum) // Corner case. happens only at the end -> hence must add 1
            max_length = i+1;
    }
    printf("Max length: %d\n", max_length);
    return max_length;
}
