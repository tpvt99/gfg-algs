#include <iostream>
#include <queue>

void median(int *arr, int n);

int main() {
    int arr[] = {25, 7, 10, 15, 20};
    median(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}

void median(int *arr, int n) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> upperPart; // minHeap
    std::priority_queue<int> lowerPart; // maxHeap
    // Put first element into first heap
    lowerPart.push(arr[0]);
    std::cout << arr[0] << " ";
    for (int i =1; i < n; i++) {
        if ((i+1) % 2 == 0) { // even number
            if (arr[i] > lowerPart.top()) {
                upperPart.push(arr[i]);
            } else {
                int top = lowerPart.top();
                lowerPart.pop();
                lowerPart.push(arr[i]);
                upperPart.push(top);
            }
            std::cout << (upperPart.top() + lowerPart.top())/2.0 << " ";
        } else {
            if (arr[i] < upperPart.top()) {
                lowerPart.push(arr[i]);
            } else {
                int top = upperPart.top();
                upperPart.pop();
                upperPart.push(arr[i]);
                lowerPart.push(top);
            }
            std::cout << lowerPart.top() << " ";
        }
    }
}