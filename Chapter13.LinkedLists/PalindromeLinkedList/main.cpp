#include <iostream>
#include <stack>

struct Node {
    int data;
    Node *next;
    Node (int x) {
        data = x;
        next = nullptr;
    }
};

bool isPalindrome(Node *head);
bool isPalindromeStack(Node *head);
bool isPalindromeEfficient(Node *head);

int main() {
    Node *head = new Node(20);
    head->next = new Node(15);
    std::cout << "palindrom 20->15: " << isPalindrome(head) << std::endl;
    std::cout << "palindrom 20->15: " << isPalindromeStack(head) << std::endl;
    std::cout << "palindrom 20->15: " << isPalindromeEfficient(head) << std::endl;


    head->next->next = new Node(9);
    std::cout << "palindrom 20->20->10: " << isPalindrome(head) << std::endl;
    std::cout << "palindrom 20->20->10: " << isPalindromeStack(head) << std::endl;
    std::cout << "palindrom 20->20->10: " << isPalindromeEfficient(head) << std::endl;


    head->next->next->next = new Node(15);
    head->next->next->next->next = new Node(20);

    std::cout << "palindrom 20->20->10->20->20: " << isPalindrome(head) << std::endl;
    std::cout << "palindrom 20->20->10->20->20: " << isPalindromeStack(head) << std::endl;
    std::cout << "palindrom 20->20->10->20->20: " << isPalindromeEfficient(head) << std::endl;


    return 0;
}

bool isPalindrome(Node *head) {
    if (head == nullptr)
        return 0;
    if (head->next == nullptr)
        return 1;
    Node *cur = head;
    while (cur != nullptr) {
        Node *slow = head;
        Node *fast = cur->next;
        int isSlowPassingCur = 0;
        // Traverse to max_length - cur_index node
        while(fast != nullptr) {
            if (slow == cur)
                isSlowPassingCur = 1;
            slow = slow->next;
            fast = fast->next;

        }
        if (isSlowPassingCur == 0)
            return 1;
        if (cur->data != slow->data)
            return 0;
        cur = cur->next;
    }
    return 1;
}

bool isPalindromeStack(Node *head) {
    std::stack<int>m;
    Node *cur = head;
    while (cur != nullptr) {
        m.push(cur->data);
        cur = cur->next;
    }
    while(head != nullptr) {
        if (m.top() != head->data)
            return 0;
        m.pop();
        head = head->next;
    }
    return 1;
}

bool isPalindromeEfficient(Node *head) {
    // Finding the middle node
    Node *slow = head;
    Node *fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // Reverse from middle->next to the end
    Node *prev = nullptr;
    Node *cur = slow->next;
    while (cur != nullptr) {
        Node *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    slow->next = prev;
    // Start from head
    slow = slow->next;
    while(slow != nullptr) {
        if (slow->data != head->data)
            return 0;
        slow = slow->next;
        head = head->next;
    }
    return 1;

}