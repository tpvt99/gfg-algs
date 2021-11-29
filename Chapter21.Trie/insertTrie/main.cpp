#include <iostream>

class TrieNode {
private:
    TrieNode * child[26];
    bool isEnd;
public:
    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
    TrieNode *getNodeAtIndex(int index) {
        return this->child[index];
    }
    void setNode(TrieNode *node, int index) {
        child[index] = node;
    }
    void setIsEnd() {
        isEnd = true;
    }
    bool getIsEnd() {
        return isEnd;
    }
};

void insertAWord(TrieNode *trie, std::string string);
bool searchAWord(TrieNode *trie, std::string word);

int main() {
    TrieNode *trieNode = new TrieNode();
    insertAWord(trieNode, "bad");
    insertAWord(trieNode, "bat");
    insertAWord(trieNode, "geek");
    insertAWord(trieNode, "geeks");
    insertAWord(trieNode, "cat");
    insertAWord(trieNode, "cut");
    std::cout << searchAWord(trieNode, "baxx") << std::endl;
    std::cout << searchAWord(trieNode, "bad") << std::endl;
    std::cout << searchAWord(trieNode, "badd") << std::endl;
    std::cout << searchAWord(trieNode, "geeks") << std::endl;


}

void insertAWord(TrieNode *trie, std::string string) {
    for (char &c : string) {
        int index = c - 'a';
        TrieNode *node = trie->getNodeAtIndex(index);
        if (node == nullptr) {
            node = new TrieNode();
            trie->setNode(node, index);
        }
        trie = node;
    }
    trie->setIsEnd();
}

bool searchAWord(TrieNode *trie, std::string word) {
    for (char &c : word) {
        int index = c - 'a';
        TrieNode *node = trie->getNodeAtIndex(index);
        if (node == nullptr)
            return false;
        trie = node;
    }
    if (trie->getIsEnd() == true)
        return true;
    return false;
}
