#include <iostream>

class MinHeap {
    int *arr;
    int capacity;
    int size;

    public:
        MinHeap(int capacity) {
            this->capacity = capacity;
            this->arr = new int[this->capacity];
            this->size = 0;
        }

        int left(int i) {
            return 2*i+1;
        }

        int right(int i) {
            return 2*i+2;
        }

        int parent(int i) {
            return (i-1)/2;
        }

        void insert(int x) {
           if (this->size > this->capacity)
               return;
           this->arr[this->size] = x;
           int parentIndex = parent(this->size);
           int i = this->size;
           while (parentIndex >= 0 && arr[parentIndex] > arr[i]) {
               // Swap parentIndex and i
               std::swap(arr[parentIndex], arr[i]);
               i = parentIndex;
               parentIndex = parent(i);
           }
            this->size = this->size + 1;
        }

        void printArray() {
            for(int i = 0; i < this->size; i++) {
                std::cout << arr[i] << " ";
            }
        }
};

int main() {
    MinHeap heap(10);
    heap.insert(10);
    heap.insert(20);
    heap.insert(15);
    heap.insert(45);
    heap.insert(50);
    heap.insert(100);
    heap.insert(25);
    heap.insert(40);
    heap.insert(12);
    heap.printArray();
    return 0;
}
