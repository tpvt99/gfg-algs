#include <iostream>
#include <string>
#include <stack>

std::string reverseWords(std::string str);
std::string reverseWordsStack(std::string str);
std::string inplaceReverse(std::string str);

int main() {
    std::string a ="welcome to geeks for geeks";
    std::string b= "abc";
    std::string c = "i love coding";
    std::cout << reverseWords(a) << "|" << std::endl;
    std::cout << reverseWords(b) << "|" << std::endl;
    std::cout << reverseWords(c) << "|" << std::endl;
    std::cout << reverseWordsStack(a) << "|" << std::endl;
    std::cout << reverseWordsStack(b) << "|" << std::endl;
    std::cout << reverseWordsStack(c) << "|" << std::endl;
    std::cout << inplaceReverse(a) << "|" << std::endl;
    std::cout << inplaceReverse(b) << "|" << std::endl;
    std::cout << inplaceReverse(c) << "|" << std::endl;
    return 0;
}

std::string reverseWords(std::string str) {
    std::string newString = "";
    int i, end;
    for (i = str.length()-1, end = str.length()-1; i >=0; i--) {
        if (str[i] == ' ') {
            newString += str.substr(i+1, end-i);
            newString += " ";
            end = i-1;
        }
    }
    newString += str.substr(i+1, end-i);
    return newString;
}

std::string reverseWordsStack(std::string str) {
    std::stack<std::string> s;
    int i, beg;
    for (i = 0, beg = 0; i < str.length();i++) {
        if (str[i] == ' ') {
            s.push(str.substr(beg, i - beg));
            beg = i+1;
        }
    }
    s.push(str.substr(beg, i-beg));
    std::string newString = "";
    while (! s.empty()) {
        newString += static_cast<std::string>(s.top());
        s.pop();
        if (s.size() > 0)
            newString += " ";
    }
    return newString;
}

std::string inplaceReverse(std::string str) {
    // Reverse words
    for (int i = 0, j = str.length()-1; i < j; i++, j--) {
        std::swap(str[i], str[j]);
    }
    //std::cout << str << std::endl;
    // Find the words
    int i, beg;
    for (i =0, beg = 0; i < str.length(); i++) {
        if (str[i] == ' ') { // Reverse words in this word
            for (int k = beg, j = i-1; k < j; k++, j--) {
                std::swap(str[k], str[j]);
            }
            beg = i+1;
        }
    }
    // Reverse last word
    for (int k = beg, j = i-1; k < j; k++, j--) {
        std::swap(str[k], str[j]);
    }
    return str;
}