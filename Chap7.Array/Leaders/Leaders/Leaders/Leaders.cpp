// Leaders.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void findLeaders(int* arr, int n);

int main()
{
    int a[] = { 7, 10, 4, 3, 6, 5, 2 };
    printf("Leaders are: ");
    findLeaders(a, 7);
}

void findLeaders(int* arr, int n) {
    int max_from_right = *(arr + n - 1);
    cout << max_from_right << " ";
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > max_from_right) {
            cout << arr[i] << " ";
            max_from_right = arr[i];
        }
    }
}
