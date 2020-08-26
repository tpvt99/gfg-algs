// TransposeMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

void transpose(std::vector<std::vector<int>>& matrix, int n);

int main()
{
    std::vector<std::vector<int>> matrix;
    int counter = 0;
    for (int i = 0; i < 4; i++) {
        std::vector<int> inner;
        for (int j = 0; j < 4; j++) {
            inner.push_back(counter++);
        }
        matrix.push_back(inner);
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%3d ", matrix.at(i).at(j));
        }
        std::cout << std::endl;
    }
    transpose(matrix, 4);
    std::cout << "Transpose matrix: \n";

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%3d ", matrix.at(i).at(j));
        }
        std::cout << std::endl;
    }
}

void transpose(std::vector<std::vector<int>>& matrix, int n) {
    for (int minRow = 0, minCol = 0;minRow<n && minCol<n;minRow++, minCol++) {
        int i = minRow, j = minCol;
        for (;j < n;j++) {
            std::swap(matrix.at(i).at(j), matrix.at(j).at(i));
        }
    }
}