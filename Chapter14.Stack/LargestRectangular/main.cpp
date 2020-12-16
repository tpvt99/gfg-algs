#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

// For each elements, iterate to left and counts intersection
int naiveMethod(int *arr, int n);

// For each elements, iterate left and right, stop when seeing elements less than current element
int differentMethod(int *arr, int n);

//
int betterMethod(int *arr, int n);
std::vector<int> prevSmaller(int *arr, int n);
std::vector<int> nextSmaller(int *arr, int n);

int efficientMethod(int *arr, int n);

int main() {
    int a[] {2, 5, 1};
    int b[] {6, 2, 5, 4, 1, 5, 6};
    int c[] {6, 2, 5, 4, 4};

    //std::cout << naiveMethod(a, sizeof(a)/sizeof(a[0])) << std::endl;
    //std::cout << naiveMethod(b, sizeof(b)/sizeof(b[0])) << std::endl;
    //std::cout << naiveMethod(c, sizeof(c)/sizeof(c[0])) << std::endl;

    //std::cout << differentMethod(a, sizeof(a)/sizeof(a[0])) << std::endl;
    //std::cout << differentMethod(b, sizeof(b)/sizeof(b[0])) << std::endl;
    //std::cout << differentMethod(c, sizeof(c)/sizeof(c[0])) << std::endl;

    std::cout << betterMethod(a, sizeof(a)/sizeof(a[0])) << std::endl;
    std::cout << betterMethod(b, sizeof(b)/sizeof(b[0])) << std::endl;
    std::cout << betterMethod(c, sizeof(c)/sizeof(c[0])) << std::endl;


    std::cout << efficientMethod(a, sizeof(a)/sizeof(a[0])) << std::endl;
    std::cout << efficientMethod(b, sizeof(b)/sizeof(b[0])) << std::endl;
    std::cout << efficientMethod(c, sizeof(c)/sizeof(c[0])) << std::endl;

    return 0;
}

int naiveMethod(int *arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        int intersection = arr[i];
        int count = 0;
        for (int j = i; j >=0; j--) {
            intersection = std::min(intersection, arr[j]);
            count += 1;
            if (intersection == 0)
                break;
            int current = intersection * count;
            if (current > max)
                max = current;
        }
    }
    return max;
}

int differentMethod(int *arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        int curr = arr[i];
        for (int j = i-1; j >=0; j--) {
            if (arr[j] >= arr[i])
                curr += arr[i];
            else
                break;
        }
        for (int j = i+1; j < n; j++) {
            if (arr[j] >= arr[i])
                curr += arr[i];
            else
                break;
        }
        max = std::max(max, curr);
    }
    return max;
}

std::vector<int> prevSmaller(int *arr, int n) {
    // bigger than top -> add to stack. also add top to vector
    // smaller than top -> pop stack until bigger than top. then add to stack. add top to vector
    std::stack<int> s;
    std::vector<int> v;
    s.push(0);
    v.push_back(-1);
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[s.top()]) {
            v.push_back(s.top());
        } else {
            while ((!s.empty()) && (arr[i] <= arr[s.top()])) {
                s.pop();
            }
            if (s.empty())
                v.push_back(-1);
            else
                v.push_back(s.top());
        }
        s.push(i);
    }
    return v;
}

std::vector<int> nextSmaller(int *arr, int n) {
    std::stack<int> s;
    std::vector<int> v;
    s.push(n-1);
    v.push_back(n);
    for (int i = n-2; i >= 0; i--) {
        if (arr[i] > arr[s.top()]) {
            v.push_back(s.top());
        } else {
            while ((!s.empty()) && (arr[i] <= arr[s.top()])) {
                s.pop();
            }
            if (s.empty())
                v.push_back(n);
            else
                v.push_back(s.top());
        }
        s.push(i);
    }
    std::reverse(v.begin(), v.end());
    return v;
}

int betterMethod(int *arr, int n) {
    std::vector<int> prev = prevSmaller(arr, n);
    std::vector<int> next = nextSmaller(arr, n);
    int max = 0;
    for (int i = 0; i < n; i++) {
        int cur = arr[i];
        cur += (i - prev[i] - 1) * arr[i];
        cur += (next[i] - i - 1) * arr[i];
        max = std::max(max, cur);
    }
    return max;
}

int efficientMethod(int *arr, int n) {
    std::stack<int> m;
    int max = 0;
    m.push(0);
    for (int i = 1; i < n; i++) {
        while ((!m.empty()) && arr[i] <= arr[m.top()]) {
            int top = m.top();
            m.pop();
            int curr = arr[top] * (m.empty()? i : (i - m.top() - 1));
            max = std::max(curr, max);
        }
        m.push(i);
    }
    while (!m.empty()) {
        int top = m.top();
        m.pop();
        int curr = arr[top] * (m.empty() ? n : (n - m.top() - 1));
        max = std::max(curr, max);
    }
    return max;
}