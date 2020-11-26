//
// Created by tpvt96 on 25/11/20.
//

#ifndef LRUDESIGN_NODE_H
#define LRUDESIGN_NODE_H

struct Node {
    int data;
    Node *next;
    Node *prev;
    Node (int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};


void testNodeImplementation();
Node * addNodeAtBegin(Node **head, int data, Node **tail);
void removeLastNode(Node **head, Node **tail);
void moveANodeToHead(Node **head, Node *node, Node **tail);

#endif //LRUDESIGN_NODE_H
