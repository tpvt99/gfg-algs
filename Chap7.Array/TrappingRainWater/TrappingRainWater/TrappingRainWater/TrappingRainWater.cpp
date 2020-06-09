// TrappingRainWater.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

int trappingRainWater(int* a, int n);
int trappingRainWaterImproved(int* a, int n);

int main()
{
    int a[] = { 4, 0, 0, 1, 3, 1, 1, 2 };
    printf("Loads: %d\n", trappingRainWater(a, sizeof(a) / sizeof(a[0])));
    int b[] = { 2, 0, 2 };
    printf("Loads: %d\n", trappingRainWater(b, sizeof(b) / sizeof(b[0])));
    int c[] = { 3, 0 , 1, 2, 5 };
    printf("Loads: %d\n", trappingRainWater(c, sizeof(c) / sizeof(c[0])));
    int d[] = { 30, 20, 10 };
    printf("Loads: %d\n", trappingRainWater(d, sizeof(d) / sizeof(d[0])));
    int e[] = { 10, 20, 30 };
    printf("Loads: %d\n", trappingRainWater(e, sizeof(e) / sizeof(e[0])));


    printf("Loads: %d\n", trappingRainWaterImproved(a, sizeof(a) / sizeof(a[0])));
    printf("Loads: %d\n", trappingRainWaterImproved(b, sizeof(b) / sizeof(b[0])));
    printf("Loads: %d\n", trappingRainWaterImproved(c, sizeof(c) / sizeof(c[0])));
    printf("Loads: %d\n", trappingRainWaterImproved(d, sizeof(d) / sizeof(d[0])));
    printf("Loads: %d\n", trappingRainWaterImproved(e, sizeof(e) / sizeof(e[0])));
}

int trappingRainWater(int* a, int n) {
    int rightMax, leftMax;
    int current;
    int loads = 0;
    for (int i = 1; i < n-1; i++) {
        rightMax = leftMax = a[i];
        for (int j = 0; j < i;j++) {
            if (a[j] > leftMax)
                leftMax = a[j];
        }
        for (int j = i + 1; j < n;j++) {
            if (a[j] > rightMax)
                rightMax = a[j];
        }
        //printf("Current: %d, leftMax: %d, rightMax: %d\n", a[i], leftMax, rightMax);
        if ((leftMax <= rightMax) && (leftMax >= a[i])) {
            loads += (leftMax - a[i]);
        }
        else if (rightMax >= a[i])
            loads += (rightMax - a[i]);
    }
    return loads;
        
}

int trappingRainWaterImproved(int* a, int n) {
    int* maxRightWall = new int[n];
    int* maxLeftWall = new int[n];
    maxLeftWall[0] = a[0];
    maxRightWall[n-1] = a[n - 1];

    for (int i = 1; i < n; i++) {
        if (a[i] > maxLeftWall[i - 1])
            maxLeftWall[i] = a[i];
        else
            maxLeftWall[i] = maxLeftWall[i - 1];
    }

    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > maxRightWall[i + 1])
            maxRightWall[i] = a[i];
        else
            maxRightWall[i] = maxRightWall[i + 1];
    }

    int loads = 0;
    for (int i = 1; i < n - 1; i++) {
        //printf("Current: %d, leftMax: %d, rightMax: %d\n", a[i], maxLeftWall[i], maxRightWall[i]);
        loads += (std::min(maxLeftWall[i], maxRightWall[i]) - a[i]);
    }
    return loads;
}