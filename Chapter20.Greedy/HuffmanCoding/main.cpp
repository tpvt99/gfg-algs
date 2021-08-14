#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>

class minHeapNode {
private:
    minHeapNode *left {nullptr};
    minHeapNode *right {nullptr};
    std::string str {""};
    int value;
public:
    minHeapNode(std::string str, int v) {
        this->str = str;
        this->value = v;
    }
    void setLeftNode(minHeapNode *left) {
        this->left = left;
    }
    void setRightNode(minHeapNode *right) {
        this->right = right;
    }
    void setString(std::string str) {
        this->str = str;
    }
    void printNode() {
        std::cout << str << ": " << value << std::endl;
    }
    minHeapNode* getLeftNode() {
        return left;
    }
    minHeapNode* getRightNode() {
        return right;
    }
    std::string getString() {
        return str;
    }
};

void traversal(minHeapNode *root);
bool sortFrequencyMap(std::pair<char, int> a, std::pair<char, int> b) ;
std::string huffmanEncoding(minHeapNode **root, std::string string);
std::string huffmanDecoding(minHeapNode *root, std::string binaryString);
void encode(minHeapNode *root, std::string str, std::unordered_map<char, std::string> &encodeMap);

int main() {
    std::string c = "affdeedffbffdedffdeb";
    minHeapNode *root;
    std::string binaryString = huffmanEncoding(&root, c);
    std::string originalString = huffmanDecoding(root, binaryString);
    std::cout << "Binary string: " << binaryString << std::endl;
    std::cout << "Original string: " << originalString << std::endl;
    return 0;
}

bool sortFrequencyMap(std::pair<char, int> a, std::pair<char, int> b) {
    return a.second > b.second;
}

std::string huffmanEncoding(minHeapNode **root, std::string string) {
    std::unordered_map<char, int> frequencyMap;
    for (char c: string) {
        frequencyMap[c] += 1;
    }
    std::vector<std::pair<char, int>> elems (frequencyMap.begin(), frequencyMap.end());
    std::sort(elems.begin(), elems.end(), sortFrequencyMap);

    int sum = 0;
    for (auto &item: elems)
        sum += item.second;

    *root = new minHeapNode("", sum);
    minHeapNode *parent = *root;
    while (true) {
        std::pair<char, int> currentMax = elems.at(0);
        if (sum > currentMax.second) {
            int other = sum - currentMax.second;
            if (currentMax.second < other) {
                std::string s;
                s.push_back(currentMax.first);
                auto *leftNode = new minHeapNode(s, currentMax.second);
                auto *rightNode = new minHeapNode("", other);
                parent->setLeftNode(leftNode);
                parent->setRightNode(rightNode);
                parent = rightNode;
            } else {
                std::string s;
                s.push_back(currentMax.first);
                auto *rightNode = new minHeapNode(s, currentMax.second);
                auto *leftNode = new minHeapNode("", other);
                parent->setLeftNode(leftNode);
                parent->setRightNode(rightNode);
                parent = leftNode;
            }
        }
        if (sum == currentMax.second) {
            std::string s;
            s.push_back(currentMax.first);
            parent->setString(s);
            break;
        }
        sum -= currentMax.second;
        elems.erase(elems.begin());
    }

    // Encode
    std::unordered_map<char, std::string> encodeMap;
    encode(*root, "", encodeMap);
    for (auto &item: encodeMap) {
        std::cout << item.first << " : " << item.second << std::endl;
    }

    std::string binaryString = "";
    for (char c: string) {
        binaryString += encodeMap[c];
    }
    return binaryString;
}

std::string huffmanDecoding(minHeapNode *root, std::string binaryString) {
    std::string originalString = "";

    minHeapNode *tempParent = root;
    for (char c: binaryString) {
        if (c == '0') {
            tempParent = tempParent->getLeftNode();
        } else {
            tempParent = tempParent->getRightNode();
        }
        if (!tempParent->getString().empty()) {
            originalString += tempParent->getString();
            tempParent = root;
        }
    }

    return originalString;
}

void encode(minHeapNode *root, std::string str, std::unordered_map<char, std::string> &encodeMap) {
    if (root == nullptr)
        return;
    if (!root->getString().empty()) {
        encodeMap[root->getString().at(0)] = str;
        return;
    }
    encode(root->getLeftNode(), str + "0", encodeMap);
    encode(root->getRightNode(), str + "1", encodeMap);
}

void traversal(minHeapNode *root) {
    if (root == nullptr)
        return;
    root->printNode();
    traversal(root->getLeftNode());
    traversal(root->getRightNode());
}

