#include <iostream>
#include <unordered_set>

struct Node {
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printNode(Node *head);
void intersection(Node *head1, Node *head2);
void efficientMethod(Node *head1, Node *head2);

int main() {
    Node *head1 = nullptr;
    head1 = new Node(10);
    head1->next = new Node(17);
    head1->next->next = new Node(19);
    Node *temp = new Node(20);
    head1->next->next->next = temp;
    head1->next->next->next->next = new Node(21);

    Node * head2 = new Node(28);
    head2->next = new Node(28);
    //head2->next->next = temp;

    printNode(head1);
    printNode(head2);
    intersection(head1, head2);
    efficientMethod(head1, head2);
    return 0;
}

void printNode(Node *head) {
    while (head != nullptr) {
        std::cout << head->data << "->";
        head = head->next;
    }
    printf("NULL\n");
}

void intersection(Node *head1, Node *head2) {
    std::unordered_set<Node *> m;
    while(head1 != nullptr) {
        m.insert(head1);
        head1 = head1->next;
    }
    while (head2 != nullptr) {
        if (m.find(head2) != m.end()) {
            std::cout << head2->data << std::endl;
            return;
        }
        head2 = head2->next;
    }
    std::cout << -1<< std::endl;

}

void efficientMethod(Node *head1, Node *head2) {
    int c1 {0};
    int c2 {0};
    Node *init_head1 = head1;
    Node *init_head2 = head2;
    while (head1 != nullptr) {
        c1 += 1;
        head1 = head1->next;
    }
    while (head2 != nullptr) {
        c2 += 1;
        head2 = head2->next;
    }
    int a = std::abs(c2 - c1);
    Node *head;
    Node *otherHead;
    if (c2 > c1) {
        head = init_head2;
        otherHead = init_head1;
    }
    else {
        otherHead = init_head2;
        head = init_head1;
    }
    for (int i = 0; i < a; i++) {
        head = head->next;
        i++;
    }
    while (head != nullptr && otherHead != nullptr) {
        if (head->data == otherHead->data) {
            std::cout << head->data << std::endl;
            return;
        }
        head = head->next;
        otherHead = otherHead->next;
    }
    std::cout << -1 << std::endl;

}


