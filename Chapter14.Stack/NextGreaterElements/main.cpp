#include <iostream>
#include <stack>

void nextGreaterElement(int *arr, int n);

int main() {
    int a[] = {5, 15, 10, 8, 6, 12, 9, 18};
    int b[] = {10, 15, 20, 25};
    int c[] = {25, 20, 15, 10};

    nextGreaterElement(a, sizeof(a) / sizeof(a[1]));
    nextGreaterElement(b, sizeof(b) / sizeof(b[1]));
    nextGreaterElement(c, sizeof(c) / sizeof(c[1]));

    return 0;
}

void nextGreaterElement(int *arr, int n) {
    std::stack<int> m;
    m.push(arr[n-1]);
    std::cout << -1 << " ";
    for (int i = n-2; i >= 0; i--) {
        if (arr[i] < m.top()) {
            std::cout << m.top() << " ";
        } else {
            while ((!m.empty()) && m.top() <= arr[i])
                m.pop();
            if (m.empty())
                std::cout << -1 << " ";
            else
                std::cout << m.top() << " ";
        }
        m.push(arr[i]);
    }
    std::cout << "\n";
}
