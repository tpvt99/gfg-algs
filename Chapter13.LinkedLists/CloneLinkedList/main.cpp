#include <iostream>
#include <unordered_map>
struct Node {
    int data;
    Node *next;
    Node *random;
    Node (int x) {
        data = x;
        next = nullptr;
        random = nullptr;
    }
};

void printNode(Node *head);
void printNodeData(Node *head);
Node *clone(Node *head);
Node *efficientClone(Node *head);

int main() {
    Node *head = new Node(10);
    Node *temp = new Node(5);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    Node *temp3 = new Node(15);

    head->next = temp;
    temp->next =temp1;
    temp1->next = temp2;
    temp2->next = temp3;

    head->random = head;
    temp->random =temp2;
    temp1->random = head;
    temp2->random = temp;
    temp3->random = temp1;

    Node *head2 = efficientClone(head);
    printNode(head);
    printNode(head2);


    return 0;
}

Node *clone(Node *head) {
    std::unordered_map<Node *, Node *>m;
    Node *initHead = head;
    while (head != nullptr) {
        m.insert({head, new Node(head->data)});
        head = head->next;
    }
    head = initHead;
    while (head != nullptr) {
        Node *newNode = m.find(head)->second;
        if (head->next != nullptr)
            newNode->next = m.find(head->next)->second;
        if (head->random != nullptr)
            newNode->random = m.find(head->random)->second;
        head = head->next;
    }
    return m.find(initHead)->second;
}

Node *efficientClone(Node *head) {
    // Step 1, create consecutive nodes
    Node *cur = head;
    while (cur != nullptr) {
        Node *next = cur->next;
        cur->next = new Node(cur->data);
        cur->next->next = next;
        cur = next;
    }
    // Step 2, link random node
    cur = head;
    while (cur != nullptr) {
        if (cur->random != nullptr) {
            cur->next->random = cur->random->next;
        } else {
            cur->next->random = nullptr;
        }
        cur = cur->next->next;
    }
    // Step 3, unlink the nodes
    cur = head;
    Node *new_head = cur->next;
    while (cur->next != nullptr) {
        Node *next = cur->next;
        cur->next = cur->next->next;
        cur = next;
    }
    return new_head;
}

void printNode(Node *head) {
    Node *initHead = head;
    std::cout << "Address: ";
    while (head != nullptr) {
        std::cout << head << "->";
        head = head->next;
    }
    printf("NULL\n");
    std::cout << "Random address: ";
    head = initHead;
    while (head != nullptr) {
        std::cout << "Current: " << head << " point to random: " << head->random << std::endl;
        head = head->next;
    }
}

void printNodeData(Node *head) {
    while (head != nullptr) {
        std::cout << head->data << "->";
        head = head->next;
    }
    printf("NULL\n");

}