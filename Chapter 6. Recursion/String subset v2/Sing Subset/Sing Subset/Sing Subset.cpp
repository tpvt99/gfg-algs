// Sing Subset.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

void sub_string(string ,  string, int);

int main()
{
    std::cout << "Hello World!\n";
    sub_string("", "ABC", 0);
}

void sub_string(string orig = "", string str ="ABC", int index = 0) {
    if (index == str.size()) {
        cout << orig << endl;
    }
    else {
        sub_string(orig, str, index + 1);
            sub_string(orig + str[index], str, index + 1);
    }
        

}