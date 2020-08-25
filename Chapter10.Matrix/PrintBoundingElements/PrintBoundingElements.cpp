// PrintBoundingElements.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define DEBUG 1

void printBoundaryElements(int** matrix, int row, int col);

int main()
{
    int** matrix;

    int row = 3;
    int col = 5;

    matrix = new int* [row];
    for (int i = 0; i < row;i++) {
        matrix[i] = new int[col];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = i * j;
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
    printBoundaryElements(matrix, row, col);
}


void printBoundaryElements(int** matrix, int row, int col) {
    for (int minRow = 0, minCol = 0;;minRow++,minCol++) {
            int maxRow = row - minRow-1;
            int maxCol = col - minCol-1;
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
            for (i = i+1;i <= maxRow;i++) {
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
            for (i = i - 1;i > minRow &&  j < maxCol; i--) {
#if DEBUG
                printf("i: %d, j: %d\n", i, j);
#else
                printf("%d ", matrix[i][j]);
#endif
            }
            printf("\n");
        
    }
}
