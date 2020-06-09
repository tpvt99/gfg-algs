// ArrayReverse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void reverse_array(int* a, int n);

int main()
{
    std::cout << "This program reverses an array\n";
    int a[] = { 10,20,30,40,50 };
    int n = 5;
    printf("Array before reversing: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    reverse_array(a, n);
    printf("\nArray after reversing: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    int b[] = { 12, 32, 43, 54 };
    n = 4;
    printf("\nArray before reversing: ");
    for (int i = 0; i < n; i++)
        printf("%d ", b[i]);
    reverse_array(b, n);
    printf("\nArray after reversing: ");
    for (int i = 0; i < n; i++)
        printf("%d ", b[i]);
}



void reverse_array(int* a, int n) {
    int* beg = a;
    int* end = a + n-1;
    while (end > beg) {
        int temp = *end;
        *end = *beg;
        *beg = temp;
        end--;
        beg++;
    }
}