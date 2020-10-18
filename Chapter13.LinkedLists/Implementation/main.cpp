#include <iostream>

typedef struct Node{
    int item;
    struct Node * next;
} Node;

void addNode(Node **head, int item);
void printNode(Node *head);

int main() {
    Node *head = nullptr;
    addNode(&head, 10);
    printNode(head);
    return 0;
}

void addNode(Node **head, int item) {
    Node *node = static_cast<Node *>(malloc(sizeof(Node)));
    if (node == nullptr) {
        std::cout << "Cannot allocate new node\n";
        return;
    }
    node->item = item;

    if (*head == nullptr) {
        *head = node;
        node->next = nullptr;
        return;
    }

    Node *end;
    for(end = *head; end->next != nullptr; end=end->next){
        ;
    }

    end->next = node;
    node->next = nullptr;
}

void printNode(Node *head) {
    for (; head != nullptr; head = head->next) {
        printf("%d -> ", head->item);
    }
    printf("NULL\n");
}

