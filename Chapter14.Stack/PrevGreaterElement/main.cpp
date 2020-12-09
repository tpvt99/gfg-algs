#include <iostream>
#include <stack>

void prevGreaterElement(int *arr, int n);

int main() {
    int a[] = {15, 10, 18, 12, 4, 6, 2, 8};
    int b[] = {8, 10, 12};
    int c[] = {12, 10, 9};
    prevGreaterElement(a, sizeof(a)/sizeof(a[0]));
    prevGreaterElement(b, sizeof(b)/sizeof(b[0]));
    prevGreaterElement(c, sizeof(c)/sizeof(c[0]));

    return 0;
}

void prevGreaterElement(int *arr, int n) {
    std::stack<int> m;
    m.push(arr[0]);
    std::cout << -1 << " ";
    for (int i = 1; i < n; i++) {
        if (arr[i] < m.top()) {
            std::cout << m.top() << " ";
        } else {
            while(!(m.empty()) && m.top() <= arr[i])
                m.pop();
            if (m.empty())
                std::cout << -1 << " ";
            else
                std::cout << m.top() << " ";
        }
        m.push(arr[i]);
    }
    std::cout << '\n';
}
