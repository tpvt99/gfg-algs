// RotateMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

void rotateMatrixBy90(std::vector<std::vector<int>> &matrix, int n);
void transpose(std::vector<std::vector<int>>& matrix, int n);

int main()
{
    std::vector<std::vector<int>> matrix;
    int counter = 0;
    for (int i = 0; i < 4; i++) {
        std::vector<int> temp;
        for (int j = 0; j < 4;j++) {
            temp.push_back(counter++);
        }
        matrix.push_back(temp);
    }

    printf("Matrix before rotated: \n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4;j++) {
            printf("%3d ", matrix.at(i).at(j));
        }
        printf("\n");
    }
    rotateMatrixBy90(matrix, 4);
    printf("\nMatrix after rotated: \n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4;j++) {
            printf("%3d ", matrix.at(i).at(j));
        }
        printf("\n");
    }
}

void transpose(std::vector<std::vector<int>>& matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n;j++) {
            std::swap(matrix.at(i).at(j), matrix.at(j).at(i));
        }
    }
}

void rotateMatrixBy90(std::vector<std::vector<int>>& matrix, int n) {
    transpose(matrix, n);
    for (int i = 0; i < n; i++) {
        for (int start = 0, end = n - 1; start < end; start++, end--) {
            std::swap(matrix.at(start).at(i), matrix.at(end).at(i));
        }
    }
}