// SpiralTraversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define DEBUG 0

void SpiralTraversal(int** matrix, int row, int col);
void efficientSpiralTraversal(int** matrix, int row, int col);
void efficientBoundaryElements(int** matrix, int rowStart, int colStart, int row, int col);

int main()
{
    int** matrix;

    int row = 5;
    int col = 3;

    matrix = new int* [row];
    for (int i = 0; i < row;i++) {
        matrix[i] = new int[col];
    }
    int counter = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = counter++;
        }
    }

    printf("Original matrix: \n");
    for (int i = 0; i < row;i++) {
        for (int j = 0; j < col;j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Boundary elements: ");
    efficientSpiralTraversal(matrix, row, col);
    printf("\n");

    SpiralTraversal(matrix, row, col);


}


void SpiralTraversal(int** matrix, int row, int col) {
    for (int minRow = 0, minCol = 0;;minRow++, minCol++) {
        int maxRow = row - minRow - 1;
        int maxCol = col - minCol - 1;
        if (maxRow < minRow || maxCol < minCol)
            break;
        // Col++
        int i = minRow;
        int j;
        for (j = minCol; j <= maxCol; j++) {
#if DEBUG
            printf("i: %d, j: %d\n", i, j);
#else
            printf("%d ", matrix[i][j]);
#endif
        }
        j--;
        printf("\n");
        //Row++
        for (i = i + 1;i <= maxRow;i++) {
#if DEBUG
            printf("i: %d, j: %d\n", i, j);
#else
            printf("%d ", matrix[i][j]);
#endif
        }
        i--;
        printf("\n");
        //Col--;
        for (j = j - 1;i > minRow && j >= minCol;j--) {
#if DEBUG
            printf("i: %d, j: %d\n", i, j);
#else
            printf("%d ", matrix[i][j]);
#endif
        }
        j++;
        printf("\n");
        // Row--
        for (i = i - 1;i > minRow && j < maxCol; i--) {
#if DEBUG
            printf("i: %d, j: %d\n", i, j);
#else
            printf("%d ", matrix[i][j]);
#endif
        }
        printf("\n");

    }
}

void efficientSpiralTraversal(int** matrix, int row, int col) {
    int top = 0, right = col - 1, bot = row - 1, left = 0;
    while (true) {
        // Top -> Right
        for (int k = left; k <= right; k++) {
            printf("%d ", matrix[top][k]);
        }
        top++;
        // Right -> Bot
        for (int k = top; k <= bot; k++) {
            printf("%d ", matrix[k][right]);
        }
        right--;
        // Bot -> Left
        if (top <= bot) {
            for (int k = right; k >= left; k--) {
                printf("%d ", matrix[bot][k]);
            }
            bot--;
        }
        // Left -> Top
        if (left <= right) {
            for (int k = bot; k >= top; k--) {
                printf("%d ", matrix[k][left]);
            }
            left++;
        }
        if (top > bot || left > right) {
            break;
        }
    }
}

