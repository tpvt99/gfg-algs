#include <iostream>
#include <deque>
void maxSubGroup(const int* arr, int n, int k);
int main() {
    int arr[] {10, 5, 8, 2, 12, 15, 6, 7, 10};
    maxSubGroup(arr, sizeof(arr)/sizeof(arr[0]), 3);
    return 0;
}

void maxSubGroup(const int* arr, int n, int k) {
    std::deque<int> m;
    m.push_back(0);
    for (int i = 1; i < k; i++) {
        // For each elements to be inserted, pop the rear until the rear is bigger than current elements
        while (true) {
            if ((!m.empty()) && (arr[i] >= arr[m.back()])) {
                m.pop_back();
            } else {
                m.push_back(i);
                break;
            }
        }
    }
    for (int i = k; i < n; i++) {
        std::cout << arr[m.front()] << " ";
        while (!m.empty() && (i - m.front() >= k)) { // Max element at front is the first element of previous window -> need to pop out
            m.pop_front();
        }
        while (true) {
            if ((!m.empty()) && (arr[i] >= arr[m.back()])) {
                m.pop_back();
            } else {
                m.push_back(i);
                break;
            }
        }
    }
    std::cout << arr[m.front()] << " ";
}
