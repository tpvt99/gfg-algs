#include <iostream>
#include <queue>
#include <vector>

void printKthLargestElement(int *arr, int n, int k);
void method2(int *arr, int n, int k);

int main() {
    int arr[] = {5, 20, 10, 8, 3};
    printKthLargestElement(arr, sizeof(arr)/sizeof(arr[0]), 2);
    std::cout << std::endl;
    method2(arr, sizeof(arr)/sizeof(arr[0]), 2);
    return 0;
}

void printKthLargestElement(int *arr, int n, int k) {
    std::priority_queue<int> pq;
    for (int i =0; i < n; i++)
        pq.push(*(arr+i));
    for (int i=0; i<k;i++) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
}

void method2(int *arr, int n, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    // Build min heap with k
    for (int i = 0; i <k;i++)
        pq.push(*(arr+i));
    // For every element, if it is bigger than top of minHeap, pop it out and add this element
    for (int i = k; i < n; i++) {
        if (arr[i] > pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    // Print
    for (int i = 0; i < k; i++) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
}
