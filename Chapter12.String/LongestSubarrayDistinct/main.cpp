#include <iostream>
#include <unordered_map>

int longestSubarray(std::string str);
int improvedVersion(std::string str);

int main() {
    std::cout << longestSubarray("abcdabc") << std::endl;
    std::cout << longestSubarray("aaa") << std::endl;
    std::cout << longestSubarray("") << std::endl;
    std::cout << longestSubarray("abaacdbab") << std::endl;
    std::cout << "Improved Version" << std::endl;
    std::cout << improvedVersion("abcdabc") << std::endl;
    std::cout << improvedVersion("aaa") << std::endl;
    std::cout << improvedVersion("") << std::endl;
    std::cout << improvedVersion("abaacdbab") << std::endl;
    return 0;
}

int longestSubarray(std::string str) {
    std::unordered_map<int, int> m;
    int maxLength = 0;
    int tempMaxLength = 0;
    for (int i = 0; i < str.length();) {
        int key = str[i] - 'a';
        if (m.find(key) == m.end()) {
            m.insert({key, i});
            tempMaxLength +=1;
            i++;
        } else {
            int initialIndex = m.find(key)->second;
            maxLength = std::max(tempMaxLength, i - initialIndex);
            m.clear();
            tempMaxLength = 0;
            i = initialIndex+1;
        }
    }
    maxLength = std::max(maxLength, tempMaxLength);
    return maxLength;
}

int improvedVersion(std::string str) {
    std::unordered_map<int, int> m;
    int maxLength = 0;
    int currLength = 0;
    for (int i = 0; i < str.length();i++) {
        int key = str[i] - 'a';
        if (m.find(key) == m.end()) {
            m.insert({key, i});
            currLength +=1;
        } else {
            int duplicatedIndex = m.find(key)->second;
            if (i - duplicatedIndex <= currLength) {
                maxLength = std::max(maxLength, currLength);
                currLength = i - duplicatedIndex;
            } else {
                currLength+=1;
            }
            m.find(key)->second = i;
        }
    }
    maxLength = std::max(maxLength, currLength);
    return maxLength;
}
