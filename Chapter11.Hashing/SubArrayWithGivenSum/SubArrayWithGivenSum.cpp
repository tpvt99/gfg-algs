// SubArrayWithGivenSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_set>

bool isSubArrayGivenSum(int* a, int n, int sum);

int main()
{
    int a[] = { 5, 8, 6, 13, 3, -1 };
    isSubArrayGivenSum(a, sizeof(a) / sizeof(a[0]), 22);
    isSubArrayGivenSum(a, sizeof(a) / sizeof(a[0]), 23);
    int b[] = { 6, 13, 3 };
    isSubArrayGivenSum(b, sizeof(b) / sizeof(b[0]), 22);
}

bool isSubArrayGivenSum(int* a, int n, int sum) {
    std::unordered_set<int>m;
    int prefix_sum = 0;
    for (int i = 0; i < n; i++) {
        prefix_sum += a[i];
        if (m.find(prefix_sum - sum) != m.end()) {
            std::cout << "Yes" << std::endl;
            return true;
        }
        if (prefix_sum == sum) {
            std::cout << "Yes" << std::endl;
            return true;
        }

        m.insert(prefix_sum);
    }
    std::cout << "No" << std::endl;
    return false;
}
