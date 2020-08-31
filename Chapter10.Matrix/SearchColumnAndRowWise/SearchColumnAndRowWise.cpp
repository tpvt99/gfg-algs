// SearchColumnAndRowWise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void searchElement(int** matrix, int row, int col, int element);

int main()
{
    int** matrix;
    int row = 4;
    int col = 4;

    matrix = new int* [row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new int[col];
    }

    matrix[0][0] = 10;
    matrix[0][1] = 20;
    matrix[0][2] = 30;
    matrix[0][3] = 40;

    matrix[1][0] = 15;
    matrix[1][1] = 25;
    matrix[1][2] = 35;
    matrix[1][3] = 45;

    matrix[2][0] = 27;
    matrix[2][1] = 29;
    matrix[2][2] = 37;
    matrix[2][3] = 48;

    matrix[3][0] = 32;
    matrix[3][1] = 33;
    matrix[3][2] = 39;
    matrix[3][3] = 50;

    searchElement(matrix, row, col, 1);
}

void searchElement(int** matrix, int row, int col, int element) {
    // Search from top right
    for (int i = 0, j = col - 1;;) {
        if (matrix[i][j] == element) {
            printf("Found element at %d, %d\n", i, j);
            return;
        }
        if (element < matrix[i][j]) {
            j -= 1;
        }
        else {
            i += 1;
        }
        if (i >= 0 && i < row && j >= 0 && j < col)
            continue;
        else {
            printf("Matrix does not contain this element\n");
            return;
        }
    }
}