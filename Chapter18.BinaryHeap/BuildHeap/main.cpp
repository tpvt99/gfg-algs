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
    MinHeap(int *array, int n) {
        arr = array;
        capacity = n;
        size=n;
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

    void heapify(int violateIndex) { // heapifyDown
        int currentIndex = violateIndex;
        while (true) {
            int leftIndex = left(currentIndex);
            int rightIndex = right(currentIndex);
            int minIndex = -1;
            if (leftIndex < this->size) {
                if (arr[leftIndex] < arr[currentIndex]) {
                    minIndex = leftIndex;
                }
            }
            if (rightIndex < this->size) {
                if (arr[rightIndex] < arr[currentIndex]) {
                    if (minIndex == -1)
                        minIndex = rightIndex;
                    else
                    if (arr[minIndex] > arr[rightIndex])
                        minIndex = rightIndex;
                }
            }
            if (minIndex != -1) {
                std::swap(arr[currentIndex], arr[minIndex]);
            } else
                break;
            currentIndex = minIndex;
        }

    }
    void printArray() {
        for(int i = 0; i < this->size; i++) {
            std::cout << arr[i] << " ";
        }
    }

};

void buildHeap(int *arr, int n) {
    MinHeap heap(arr, n);
    for (int i =(n-2)/2; i >= 0; i--) {
        heap.heapify(i);
    }
}

int main() {
    int arr[] = {10, 5, 20, 2, 4, 8};
    buildHeap(arr, sizeof(arr)/sizeof(arr[0]));
    for(auto x : arr)
        std::cout << x << " ";
    return 0;
}
