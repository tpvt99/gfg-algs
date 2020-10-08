#include <iostream>

void longestProperPrefixSuffix(std::string str);
void anotherMethod(std::string str);
void efficientMethod(std::string str);
int compareString(std::string str1, std::string str2);

int main() {
    std::cout << "Longest Proper" << std::endl;
//longestProperPrefixSuffix("ababc");
//longestProperPrefixSuffix("aaaa");
//longestProperPrefixSuffix("abacabad");
    anotherMethod("ababc");
    anotherMethod("aaaa");
    anotherMethod("abacabad");
    anotherMethod("aaabaaaac");
    std::cout << "Efficient" << std::endl;
    efficientMethod("ababc");
    efficientMethod("aaaa");
    efficientMethod("abacabad");
    efficientMethod("aaabaaaac");
    return 0;
}

int compareString(std::string str1, std::string str2) {
    if (str1.length() != str2.length())
        return 0;

    for (int i = 0; i < str1.length();i++) {
        if (str1[i] != str2[i])
            return 0;
    }
    return 1;
}

void longestProperPrefixSuffix(std::string str) {
    for (int i = 0; i < str.length(); i++) {
        std::string pat = str.substr(0,i+1);
        int longest = 0;
        int prefix_index = 0;
        std::string prefix; // First prefix
        do {
            prefix = pat.substr(0, prefix_index);
            std::string suffix; // First suffix
            int suffix_index = pat.length();
            do {
                suffix = pat.substr(suffix_index, pat.length() - suffix_index);
                if (compareString(prefix, suffix) == 1)
                    longest = prefix.length();
                suffix_index--;
            } while(suffix_index >= 0);
            prefix_index++;
        } while (prefix_index <= i);
        std::cout << longest << " ";
    }
    std::cout << std::endl;
}

void anotherMethod(std::string str) {
    for (int i = 0; i < str.length(); i++) {
        int longest = 0;
        std::string pat = str.substr(0, i+1);
        for (int len = 1; len <= i; len++) { // Len starts at 1
            std::string prefix = pat.substr(0, len);
            std::string suffix = pat.substr(i - len + 1, len);

            // Compare String
            int k;
            for (k = 0; k < len; k++) {
                if (prefix[k] != suffix[k]) {
                    break;
                }
            }
            if (k == len) {
                longest = len;
            }
        }
        std::cout << longest << " ";
    }
    std::cout << std::endl;
}

void efficientMethod(std::string str) {
    int *array =(int *) malloc(str.length() * sizeof(int));
    array[0] = 0;
    std::cout << 0 << " ";
    int len = 0;
    for (int i = 1; i < str.length();) {
        if (str[i] == str[len]){
            array[i] = len+1;
            len++;;
            std::cout << array[i] << " ";
            i++;
        }
        else {
            if (len == 0) {
                array[i] = 0;
                std::cout << array[i] << " ";
                i++;
            } else {
                len = array[len-1];
            }
        }
    }
    std::cout << std::endl;
}