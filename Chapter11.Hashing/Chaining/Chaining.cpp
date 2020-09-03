// Chaining.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

typedef struct link_list {
    int x;
    struct link_list* next;
} link_list;

constexpr int N = 7;

void hash_insert(link_list** hash_table, int x);
void hash_delete(link_list** hash_table, int x);
link_list* hash_search(link_list** hash_table, int x);
void hash_print(link_list** hash_table);


int main()
{
    
    link_list** hash_table = new link_list *[N];
    for (int i = 0; i < N; i++) {
        hash_table[i] = NULL;
    }


    hash_insert(hash_table, 10);
    hash_insert(hash_table, 12);
    hash_insert(hash_table, 7);
    hash_insert(hash_table, 8);
    hash_insert(hash_table, 9);
    hash_insert(hash_table, 21);
    hash_insert(hash_table, 14);
    hash_insert(hash_table, 15);
    hash_insert(hash_table, 15);
    link_list* search_ele = hash_search(hash_table, 21);
    if (search_ele != NULL) {
        printf("Found the element\n");
    }
    else {
        printf("Not found\n");
    }
    hash_delete(hash_table, 21);
    hash_insert(hash_table, 21);
    hash_delete(hash_table, 31);
    hash_delete(hash_table, 10);
    hash_insert(hash_table, 10);
    hash_print(hash_table);
}

void hash_print(link_list** hash_table) {
    for (int i = 0; i < N; i++) {
        printf("%d. Top->", i);
        for (link_list *top = *(hash_table+i); top != NULL; top=top->next) {
            
            printf("%d->", top->x);
        }
        printf("NULL\n");
        if (i != N - 1) {
            printf("|\n");
            printf("|\n");
        }
        
    }
}

void hash_insert(link_list** hash_table, int x) {
    int position = x % N;
    link_list* top;
    link_list* prev;

    link_list* search = hash_search(hash_table, x);
    if (search != NULL) {
        printf("Already exists. Disregard this element.\n");
        return;
    }

    for (top = *(hash_table+position), prev = NULL;top != NULL;) {
        
        prev = top;
        top = top->next;
    }

    link_list* new_node = new link_list;
    if (new_node == NULL) {
        printf("Error when allocating data for new node.\n");
        return;
    }
    new_node->x = x;
    new_node->next = NULL;
    if (prev != NULL)
        prev->next = new_node;
    else
        *(hash_table + position) = new_node;

}

link_list* hash_search(link_list** hash_table, int x) {
    int position = x % N;
    for (link_list* top = *(hash_table + position); top != NULL;top=top->next) {
        if (top->x == x) {
            return top;
        }
    }
    return NULL;
}

void hash_delete(link_list** hash_table, int x) {
    int position = x % N;
    link_list* curr;
    link_list* prev;
    for (curr = *(hash_table + position), prev = NULL; curr != NULL; ) {
        if (curr->x == x) {
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    if (curr != NULL) {
        if (prev == NULL) {
            *(hash_table + position) = curr->next;
        }
        else {
            prev->next = curr->next;
        }
        delete curr;
    }
}