#include <iostream>
#include <queue>
#include <vector>

int purchaseMaxItems(int *arr, int n, int sum);

int main() {
    int arr[] = {1, 12, 5, 111, 200};
    int sum = 1000;
    std::cout << purchaseMaxItems(arr, sizeof(arr)/sizeof(arr[0]), sum) << std::endl;
    return 0;
}

int purchaseMaxItems(int *arr, int n, int sum) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
    }
    int currentSum = 0;
    int count = 0;
    while (count <=n && currentSum < sum) {
        currentSum += pq.top();
        pq.pop();
        count+=1;
    }
    return count-1;
}