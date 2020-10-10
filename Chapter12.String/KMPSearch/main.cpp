#include <iostream>

void buildLSP(std::string str, int *arr);
void KMP(std::string str, std::string pat);

int main() {
    KMP("aaaaa", "aaaa");
    KMP("abcabcdabcd", "abcd");
    return 0;
}

void KMP(std::string str, std::string pat) {
    int *lspA= (int *) malloc(str.length() * sizeof(int));
    buildLSP(str, lspA);
    int i = 0, j = 0;
    while (i < str.length()) {
        if (str[i] == pat[j]) {
            i++;
            j++;
        }
        if (j == pat.length()) {
            std::cout << i - j << " ";
            j =  lspA[j-1];
        }
        if (i < str.length() && str[i] != pat[j]){
            if (j == 0) {
                i++;
            } else {
                j = lspA[j-1];
            }
        }
    }
    std::cout << std::endl;
}

void buildLSP(std::string str, int *array) {
    array[0] = 0;
    int len = 0;
    for (int i = 1; i < str.length();) {
        if (str[i] == str[len]){
            array[i] = len+1;
            len++;;
            i++;
        }
        else {
            if (len == 0) {
                array[i] = 0;
                i++;
            } else {
                len = array[len-1];
            }
        }
    }
}