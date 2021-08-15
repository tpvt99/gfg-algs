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
    int getValue() {
        return value;
    }
};

void traversal(minHeapNode *root);
bool sortFrequencyMap(std::pair<char, int> a, std::pair<char, int> b) ;
std::string huffmanEncoding(minHeapNode **root, std::string string);
std::string efficientHuffmanEncoding(minHeapNode **root, std::string string);
std::string huffmanDecoding(minHeapNode *root, std::string binaryString);
void encode(minHeapNode *root, std::string str, std::unordered_map<char, std::string> &encodeMap);

int main() {
    std::string c = "affdeedffbffdedffdeb";
    minHeapNode *root;
    std::string binaryString = huffmanEncoding(&root, c);
    std::string originalString = huffmanDecoding(root, binaryString);
    std::cout << "Binary string: " << binaryString << std::endl;
    std::cout << "Original string: " << originalString << std::endl;
    std::cout << "---------------------" << std::endl;

    minHeapNode *root2;
    binaryString = efficientHuffmanEncoding(&root2, c);
    originalString = huffmanDecoding(root2, binaryString);
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

std::string efficientHuffmanEncoding(minHeapNode **root, std::string string) {
    // Find the frequency of characters
    std::unordered_map<char, int> frequencyMap;
    for (char c: string) {
        frequencyMap[c] += 1;
    }
    std::vector<std::pair<char, int>> elems (frequencyMap.begin(), frequencyMap.end());
    std::sort(elems.begin(), elems.end(), sortFrequencyMap);

    // Push into min heap first k elements
    auto compare {
        [](minHeapNode *l, minHeapNode *r) {
            return std::abs(l->getValue())>std::abs(r->getValue());
        }};
    std::priority_queue<minHeapNode *, std::vector<minHeapNode*>, decltype(compare)> q(compare);

    for (auto &item: elems) {
        std::string c;
        c += item.first;
        minHeapNode *node = new minHeapNode(c, item.second);
        q.push(node);
    }

    while (q.size() > 1) {
        minHeapNode *low1 = q.top();
        q.pop();
        minHeapNode *low2 = q.top();
        q.pop();
        minHeapNode *newNode = new minHeapNode("", low1->getValue() + low2->getValue());
        newNode->setLeftNode(low1);
        newNode->setRightNode(low2);
        q.push(newNode);
    }

    *root = q.top();
    q.pop();
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

