#include <iostream>
#include <queue>
#include <unordered_map>

void method(int *arr, int n, int k, int x);

int main() {
    int arr[] = {10, 15, 7, 3 , 4};
    method(arr, sizeof(arr)/sizeof(arr[0]), 2, 8);
    return 0;
}

void method(int *arr, int n, int k, int x) {
    // Push into max heap first k elements
    auto compare {
        [x](int l, int r) {
            return std::abs(l-x)<std::abs(r-x);
        }};
    std::priority_queue<int, std::vector<int>, decltype(compare)> q(compare);

    int maxDiff = std::abs(arr[0] - x);
    for (int i = 0; i<k;i++) {
        q.push(arr[i]);
        if (std::abs(arr[i] - x) > maxDiff)
            maxDiff = std::abs(arr[i] - x);
    }
    for (int i = k; i<n;i++) {
        // If current element - x has absolute value less than maxDiff, push into pq and pop the top
        if (std::abs(arr[i] - x) < maxDiff) {
            q.pop();
            q.push(arr[i]);
            maxDiff = std::abs(q.top() - x);
        }
    }
    for (int i = 0; i <k; i++) {
        std::cout << q.top()<< " ";
        q.pop();
    }
}