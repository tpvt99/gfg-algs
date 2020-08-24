// PrintSnakePattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void printSnakePattern(int** matrix, int row, int col) {
    printf("Snake pattern: \n");
    for (int i = 0; i < row; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < col; j++) {
                printf("%d ", matrix[i][j]);
            }
        }
        else {
            for (int j = col-1; j >=0; j--) {
                printf("%d ", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int** matrix;
    int row = 5;
    int col = 4;

    matrix = new int* [row];

    for (int i = 0; i < row; i++) {
        *(matrix + i) = new int[col];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = i + j;
        }
    }

    for (int **arr = matrix; arr < matrix + row; arr++) {
        for (int *element = *arr; element < *arr + col; element++) {
            printf("%d ", *element);
        }
        printf("\n");
    }

    printSnakePattern(matrix, row, col);

}
