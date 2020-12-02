#include <iostream>
#include <stack>
#include <string>

bool isBalancedParenthesis(std::string str);

int main() {
    std::cout << isBalancedParenthesis("{[]}") << std::endl;
    std::cout << isBalancedParenthesis("{[}]") << std::endl;
    std::cout << isBalancedParenthesis("{[]}{}()((())") << std::endl;
    std::cout << isBalancedParenthesis("()))))") << std::endl;

    return 0;
}

bool isBalancedParenthesis(std::string str) {
    std::stack<char> m;
    for (char c : str) {
        switch(c) {
            case '(': case '{': case '[': {
                m.push(c);
                break;
            }
            case ')': case '}': case ']': {
                if (m.empty())
                    return 0;
                char top_item = m.top();
                if ((c == ')' && top_item != '(' )||
                    (c == ']' && top_item != '[' )||
                    (c == ')' && top_item != '(' )) {
                    return 0;
                }
                m.pop();
                break;
            }
        }
    }
    if (m.empty())
        return 1;
    return 0;
}


