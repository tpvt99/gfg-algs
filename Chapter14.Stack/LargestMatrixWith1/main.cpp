#include <iostream>
#include <stack>

int largestRectangular(int *arr, int n);
int largestMatrix(int arr[][2], int row, int col);

int main() {
    int a[][4] = {{0, 1, 1, 0}, {1,1,1,1}, {1,1,1,1},{1,1,0,0}};
    int b[][3] = {{0,1,1},{1,1,1},{0,1,1}};
    int c[][2] = {{0,0},{0,0}};
    int d[][2] = {{0,0},{0,1}};
    int e[][3] = {{1,1,1}};

    std::cout << largestMatrix(c, 2, 2) << std::endl;

    return 0;
}

int largestRectangular(int *arr, int n) {
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

int largestMatrix(int arr[][2], int row, int col) {
    int max {0};
    int *temp {new int[col]};
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            temp[c] += arr[r][c];
        }
        int *passedArray = new int[col];
        for (int c = 0; c < col; c++) {
            if (arr[r][c] == 0)
                passedArray[c] = 0;
            else
                passedArray[c] = temp[c];
        }
        max = std::max(max, largestRectangular(passedArray, col));
    }
    return max;
}