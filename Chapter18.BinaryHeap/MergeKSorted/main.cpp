#include <iostream>
#include <queue>

void mergeKSorted(int **arr, int rows, int col[3]);

int main() {
    int **arr = new int *[3];
    arr[0] = new int[3];
    arr[0][0] = 10;
    arr[0][1] = 20;
    arr[0][2] = 30;
    arr[1] = new int[2];
    arr[1][0] = 5;
    arr[1][1] = 15;
    arr[2] = new int[4];
    arr[2][0] = 1;
    arr[2][1] = 9;
    arr[2][2] = 11;
    arr[2][3] = 18;
    int cols[3] = {3, 2, 4};
    mergeKSorted(arr, 3, cols);
    return 0;
}

void mergeKSorted(int **arr, int rows, int col[3]) {
    // Create a min heap
    auto compare {
            [](std::pair<int, std::pair<int,int>> a, std::pair<int, std::pair<int,int>> b) {
                return a.first > b.first;
            }};
    std::priority_queue<std::pair<int, std::pair<int,int>>, std::vector<std::pair<int, std::pair<int,int>>>, decltype(compare)> pq(compare);
    // Add first k elements of first column
    for (int i = 0; i < rows; i++) {
        pq.push({arr[i][0], {i,0}});
    }
    while (true) {
        std::pair<int, std::pair<int, int>> top = pq.top();
        pq.pop();
        std::cout << top.first << " ";
        int rowIndex = top.second.first;
        int colIndex = top.second.second;
        if (colIndex < col[rowIndex] -1) {
            pq.push({arr[rowIndex][colIndex+1], {rowIndex, colIndex+1}});
        }
        if (pq.empty())
            break;
    }

}
