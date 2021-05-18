#include <iostream>
#include <queue>
#include <vector>

void sortKSorted(int *arr, int n, int k);

int main() {
    int arr[] = {9, 8, 7, 18, 19, 17};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    sortKSorted(arr, n, k);
    for (auto x : arr) {
        std::cout << x << " ";
    }
    return 0;
}

void sortKSorted(int *arr, int n, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int z = 0;
    for (int i = 0; i < n; i++) {
        if (i > k) {
            int temp = pq.top();
            pq.pop();
            arr[z++] = temp;
        }
        pq.push(arr[i]);
    }
    while (!pq.empty()) {
        arr[z++] = pq.top();
        pq.pop();
    }
}