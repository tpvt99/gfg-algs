// StockBuyAndSell.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int stockBuyAndSell(int* arr, int n);
int stockBuyAndSellNaive(int* arr, int n, int begin, int end);

int main()
{
    std::cout << "The program finds the maximum price of sell and buy stocks\n";
    int a[] = { 1,5,3,8,12 };
    int b[] = { 30, 20, 10 };
    int c[] = { 10, 20, 30 };
    int d[] = { 1, 5, 3, 1, 2, 8 };
    printf("Maximum of array a: %d\n", stockBuyAndSell(a, sizeof(a) / sizeof(a[0])));
    printf("Maximum of array b: %d\n", stockBuyAndSell(b, sizeof(b) / sizeof(b[0])));
    printf("Maximum of array c: %d\n", stockBuyAndSell(c, sizeof(c) / sizeof(c[0])));
    printf("Maximum of array d: %d\n", stockBuyAndSell(d, sizeof(d) / sizeof(d[0])));

    printf("Maximum of array a by Naive Method: %d\n", stockBuyAndSellNaive(a, sizeof(a) / sizeof(a[0]), 0, sizeof(a) / sizeof(a[0])));
    printf("Maximum of array b by Naive Method: %d\n", stockBuyAndSellNaive(b, sizeof(b) / sizeof(b[0]), 0, sizeof(b) / sizeof(b[0])));
    printf("Maximum of array c by Naive Method: %d\n", stockBuyAndSellNaive(c, sizeof(c) / sizeof(c[0]), 0, sizeof(c) / sizeof(c[0])));
    printf("Maximum of array d by Naive Method: %d\n", stockBuyAndSellNaive(d, sizeof(d) / sizeof(d[0]), 0, sizeof(d) / sizeof(d[0])));
}

int stockBuyAndSell(int* arr, int n) {
    int price = 0;
    int buy = *arr;
    int sell = *arr;
    for (int i = 1; i < n; i++) {
        if (arr[i] > sell) {
            sell = arr[i];
        }
        else if (arr[i] < sell) {
            price += (sell - buy);
            buy = arr[i];
            sell = arr[i];
        }
    }
    price += (sell - buy);

    return price;
}

int stockBuyAndSellNaive(int* arr, int n, int begin, int end) {
    if (end <= begin)
        return 0;
    int profit = 0;
    int current_profit;
    for (int i = begin; i < end-1; i++) {
        for (int j = i + 1; j < end;j++) {
            if (arr[j] > arr[i]) {
                current_profit = (arr[j] - arr[i]) + stockBuyAndSellNaive(arr, n, begin, i - 1) + stockBuyAndSellNaive(arr, n, j + 1, end);
                if (current_profit > profit)
                    profit = current_profit;
            }
        }
    }
    return profit;
}