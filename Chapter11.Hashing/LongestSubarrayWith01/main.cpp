#include <iostream>
#include <unordered_map>

int naiveMethod(int *a, int n);
void increase(int *count_0s, int *count_1s, int a_i);
int longestSubarrayWith0sSum(int *a, int n);
int betterMethod(int *a, int n);

int main() {
    int a[] = {1, 0, 1, 1, 1, 0, 0};
    int b[] = {1, 1, 1, 1};
    int c[] = {0, 0, 1, 1, 1, 1, 0};
    naiveMethod(a, sizeof(a)/sizeof(a[0]));
    naiveMethod(b, sizeof(b)/sizeof(b[0]));
    naiveMethod(c, sizeof(c)/sizeof(c[0]));
    betterMethod(a, sizeof(a)/sizeof(a[0]));
    betterMethod(b, sizeof(b)/sizeof(b[0]));
    betterMethod(c, sizeof(c)/sizeof(c[0]));
    return 0;
}


void increase(int *count_0s, int *count_1s, int a_i) {
    if (a_i == 0)
        (*count_0s)++;
    else
        (*count_1s)++;
}
int naiveMethod(int *a, int n) {
    int max_length = 0;
    for (int i = 0; i < n; i++) {
        int count_0s = 0;
        int count_1s = 0;
        increase(&count_0s, &count_1s, a[i]);
        for (int j = i+1; j <n;j++) {
            increase(&count_0s, &count_1s, a[j]);
            if (count_1s == count_0s) {
                max_length = std::max(max_length, 2*count_1s);
            }
        }
    }
    printf("Longest length: %d\n", max_length);
}

int longestSubarrayWith0sSum(int *a, int n) {
    std::unordered_map<int, int> m;
    int prefix_sum = 0;
    int max_length = 0;
    for (int i = 0; i <n; i++) {
        prefix_sum += a[i];
        if (prefix_sum == 0)
            max_length = i+1;
        if (m.find(prefix_sum) != m.end()) {
            max_length = std::max(max_length, i-m.find(prefix_sum)->second);
        } else {
            m.insert({prefix_sum, i});
        }
    }
    return max_length;
}
int betterMethod(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] == 0)
            a[i]=-1;
    }
    int results = longestSubarrayWith0sSum(a, n);
    printf("Longest length: %d\n",results);
    return results;
}
