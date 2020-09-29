#include <iostream>
#include <string>
#include <unordered_map>

int normalMethodUsingArray(std::string str);
int betterMethodUsingArray(std::string str);

int main() {
    std::string str1 = "abcabc";
    std::string str2 = "apple";
    std::string str3 = "geeksforgeeks";
    std::cout << normalMethodUsingArray(str1) << std::endl;
    std::cout << normalMethodUsingArray(str2) << std::endl;
    std::cout << normalMethodUsingArray(str3) << std::endl;
    std::cout << betterMethodUsingArray(str1) << std::endl;
    std::cout << betterMethodUsingArray(str2) << std::endl;
    std::cout << betterMethodUsingArray(str3) << std::endl;
    return 0;
}

int normalMethodUsingArray(std::string str) {
    int temp[26] = {0};
    for (auto c : str) {
        temp[c - 'a']++;
    }

    for (int i = 0; i < str.length(); i++) {
        if (temp[str[i] - 'a'] == 1) {
            return i;
        }
    }
    return -1;
}

int betterMethodUsingArray(std::string str) {
    int temp[26] = {0};
    std::fill(temp, temp + 26, -1);
    for (int i = 0; i < str.length(); i++) {
        if (temp[str[i]-'a'] == -1) {
            temp[str[i] - 'a'] = i;
        } else if (temp[str[i] - 'a'] >= 0) {
            temp[str[i] - 'a'] = -2;
        }
    }
    int minIndex = str.length();
    for (auto val : temp) {
        if (val >= 0)
            minIndex = std::min(minIndex, val);
    }
    return minIndex == str.length() ? -1 : minIndex;
}