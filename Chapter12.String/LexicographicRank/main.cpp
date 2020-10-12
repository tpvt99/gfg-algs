#include <iostream>
#include <string>

int lexicographicRank(std::string str);
int optimized(std::string str);

int main() {
    std::cout << lexicographicRank("abc") << std::endl;
    std::cout << lexicographicRank("bac") << std::endl;
    std::cout << lexicographicRank("dcba") << std::endl;
    std::cout << lexicographicRank("string") << std::endl;

    std::cout << optimized("abc") << std::endl;
    std::cout << optimized("bac") << std::endl;
    std::cout << optimized("dcba") << std::endl;
    std::cout << optimized("string") << std::endl;
    return 0;
}

int lexicographicRank(std::string str) {
    int charArray[26]{};
    int rank{};

    for (char c: str) {
        charArray[c-'a'] = 1;
    }

    int permutation = 1;
    for (int i = 1; i < str.length(); i++) {
        permutation *= i;
    }

    for (int i = 0; i < str.length(); i++) {
        int order{0};
        for (int j = 0; j < str[i]-'a'; j++) {
            if (charArray[j]) {
                order+=1;
            }
        }
        charArray[str[i] - 'a']=0;
        rank += order * permutation;
        if (str.length()-i-1 > 0)
            permutation /= (str.length()-i-1);
    }
    return rank+1;
}

int optimized(std::string str) {
    int charArray[26]{};
    int rank{};

    for (int i = 0; i < str.length(); i++) {
        charArray[str[i]-'a'] = 1;
    }

    for (int i = 1; i < 26; i++) {
        charArray[i]+= charArray[i-1];
    }

    int permutation = 1;
    for (int i = 1; i <= str.length(); i++) {
        permutation *= i;
    }

    for (int i = 0; i < str.length(); i++) {
        permutation /= (str.length()-i);
        int order = charArray[str[i]-'a']-1;
        rank += order * permutation;
        for (int j = str[i] - 'a'; j < 26;j++) {
            charArray[j]--;
        }
    }
    return rank+1;

}