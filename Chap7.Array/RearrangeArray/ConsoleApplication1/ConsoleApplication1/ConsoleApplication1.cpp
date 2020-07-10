// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void rearrange(int* a, int n);

int main()
{
    int a[] = { 4,0,2,1,3 };
    int b[] = { 3,2,0,1 };

    rearrange(a, 5);
    rearrange(b, 4);

}

void rearrange(int* a, int n) {
    int maxVal = n;
    for (int i = 0; i < n;i++) {
        int newValue = a[a[i]] % maxVal;
        a[i] += newValue * maxVal;
    }
    for (int i = 0;i < n;i++) {
        a[i] /= maxVal;
    }
    printf("Value: ");
    for (int i = 0; i < n;i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}