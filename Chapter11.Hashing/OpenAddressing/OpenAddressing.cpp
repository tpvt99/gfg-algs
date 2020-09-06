// OpenAddressing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Hashing {
    
public:
    int* array;
    int count = 0;
    int slots = 0;
    Hashing(int slots) {
        Hashing::array = new int[slots];
        for (int i = 0; i < slots;i++) {
            Hashing::array[i] = -1;
        }
        Hashing::slots = slots;
    }

    void print() {
        for (int i = 0; i < slots;i++) {
            printf("%d ", Hashing::array[i]);
        }
        printf("\n");
    }

    void insert(int key) {
        if (Hashing::count == Hashing::slots) {
            printf("Hash table is full\n");
            return;
        }
        if (Hashing::search(key)) {
            printf("Key existed. Disregard this key\n");
            return;
        }
        int prob = key % slots;
        int offset = (slots - 1) - (key % (slots-1));
        while ((Hashing::array[prob] != -1) && (Hashing::array[prob] != -2)) {
            prob = (prob + offset) % slots;
        }
        Hashing:array[prob] = key;
    }

    bool search(int key) {
        int prob = key % slots;
        int offset = (slots - 1) - (key % (slots - 1));
        for (int i = 0; i < slots;i++) {
            if (Hashing::array[(prob + i * offset) % slots] == key) {
                return true;
            }
            else if (Hashing::array[(prob + i * offset) % slots] == -1) {
                return false;
            }
        }
        return false;
    }

    void hashDelete(int key) {
        int prob = key % slots;
        int offset = (slots - 1) - (key % (slots - 1));
        for (int i = 0; i < slots;i++) {
            if (Hashing::array[(prob + i * offset) % slots] == key) {
                Hashing::array[(prob + i * offset) % slots] = -2;
                return;
            }
            else if (Hashing::array[(prob + i * offset) % slots] == -1) {
                printf("No key: %d. Hence no deletion occurs\n", key);
                return;
            }
        }
        printf("No key: %d. Hence no deletion occurs\n", key);
        return ;
    }
};

int main()
{
    Hashing myHash(7);

    myHash.insert(10);
    myHash.insert(5);
    myHash.insert(1);
    myHash.insert(1212);
    myHash.insert(76);
    myHash.insert(34);
    myHash.print();
    if (myHash.search(5)) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }
    if (myHash.search(3)) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }
    myHash.insert(4);
    myHash.print();
    if (myHash.search(1212)) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }
    if (myHash.search(19)) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }
    myHash.hashDelete(5);
    myHash.hashDelete(1);
    myHash.hashDelete(1233);
    myHash.hashDelete(34);
    myHash.hashDelete(3);
    myHash.print();
    if (myHash.search(1212)) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }
    if (myHash.search(10)) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }
    myHash.insert(34);
    myHash.insert(54);
    myHash.print();
}
