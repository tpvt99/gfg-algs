// TowerOfHanoi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void tower_of_hanoi(int, string, string, string);

int main()
{
    tower_of_hanoi(6, "A", "B", "C");
}

void tower_of_hanoi(int n, string src_col, string aux_col, string dest_col) {
    if (n == 1) {
        cout << "Moving block 1 from " << src_col << " to the position " << dest_col << endl;
        return;
    }
    tower_of_hanoi(n - 1, src_col, dest_col, aux_col);
    cout << "Moving block " << n << " from " << src_col << " to the position " << dest_col << endl;
    tower_of_hanoi(n - 1, aux_col, src_col, dest_col);
}