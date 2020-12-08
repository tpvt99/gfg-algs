#include <iostream>
#include <stack>
void naiveMethod(int *arr, int n);
void betterMethod(int *arr, int n);

int main() {
    int a[] = {13, 15, 12, 14, 16, 8, 6, 4, 10, 30};
    int b[] = {10, 20, 30, 40};
    int c[] = {40, 30, 20, 10};

    naiveMethod(a, sizeof(a)/sizeof(a[0]));
    naiveMethod(b, sizeof(b)/sizeof(b[0]));
    naiveMethod(c, sizeof(c)/sizeof(c[0]));
    std::cout << "----" << std::endl;
    betterMethod(a, sizeof(a)/sizeof(a[0]));
    betterMethod(b, sizeof(b)/sizeof(b[0]));
    betterMethod(c, sizeof(c)/sizeof(c[0]));

    return 0;
}

void naiveMethod(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        int span = 1;
        for (int k = i-1; k >= 0; k--) {
            if (arr[k] <= arr[i])
                span++;
            else
                break;
        }
        std::cout << span << " ";
    }
    std::cout << "\n";
}

void betterMethod(int *arr, int n) {
    std::stack<int> m;
    m.push(arr[0]);
    std::cout << 1 << " ";
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[m.top()]) {
            m.push(i);
            std::cout << 1 << " ";
        } else {
            while ((!m.empty()) && arr[i] >= arr[m.top()])
                m.pop();
            if (m.empty()) {
                std::cout << i+1 << " ";
            } else {
                std::cout << i - m.top() << " ";
            }
            m.push(i);
        }
    }
    std::cout << "\n";
}
