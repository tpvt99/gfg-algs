// PassingToFunctions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void print(int** b, int m, int n);

int main()
{
    int** matrix;
    matrix = new int *[2];
    for (int i = 0; i < 2; i++) {
        *(matrix + i) = new int[4];
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = i + j;
        }
    }
    
    print(matrix, 2, 4);

}

void print(int** b, int m, int n) {
    for (int i = 0; i < m;i++) {
        for (int j = 0; j < n;j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
}
