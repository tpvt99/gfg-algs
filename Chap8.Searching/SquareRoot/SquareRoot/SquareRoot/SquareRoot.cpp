// SquareRoot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int find_squareRoot( int x);
int squareRoot(int low, int high, int x);

int main()
{
    printf("Square root of 4: %d\n", find_squareRoot(4));
    printf("Square root of 15: %d\n", find_squareRoot(15));
    printf("Square root of 25: %d\n", find_squareRoot(25));
    printf("Square root of 167: %d\n", find_squareRoot(167));
    printf("Square root of 81: %d\n", find_squareRoot(81));
}

int find_squareRoot( int x) {
    int low = 0;
    int high = x;
    return squareRoot(low, high, x);
}

int squareRoot(int low, int high, int x) {
    int middle = (low + high) / 2;

    if (middle * middle == x)
        return middle;
    else if (middle * middle > x)
        return squareRoot(low, middle - 1, x);
    else if ((middle * middle < x) && ((middle + 1) * (middle + 1) > x))
        return middle;
    else if (middle * middle < x)
        return squareRoot(middle + 1, low, x);
}