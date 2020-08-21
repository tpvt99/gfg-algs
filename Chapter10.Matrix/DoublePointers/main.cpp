#include <iostream>

int main() {
    int row = 3;
    int col = 2;
    int **arr;

    arr = new int *[row];
    for (int i = 0; i < row; i++) {
        *(arr+i) = new int [col];
    }

    for (int **p = arr; p < arr + row; p++) {
        printf("%p\n", p);
        for (int *num = *p; num < *p + col; num++) {
            *num = 10;
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}
