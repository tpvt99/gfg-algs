// Sum subset.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <numeric>
#include <list>

using namespace std;

int sum_subset(vector<int>, vector<int>, int, int);

int main()
{
    std::cout << "Hello World!\n";
    vector<int> i = { 10, 20, 15 };
    vector<int> empty_vec = {};
    int n = sum_subset(empty_vec, i, 0, 0);
    cout << n << endl;
}

int sum_subset(vector<int> recurs_lists, vector<int> orig_lists, int sum, int index) {
    if (index == orig_lists.size()) {
        if (accumulate(recurs_lists.begin(), recurs_lists.end(), 0) == sum)
            return 1;
        else return 0;
    }
    else {
        vector<int> new_vector = recurs_lists;
        new_vector.insert(new_vector.end(), orig_lists.at(index));
        int a = sum_subset(new_vector, orig_lists, sum, index + 1);
        int b = sum_subset(recurs_lists, orig_lists, sum, index + 1);
        return a + b;
    }
}

