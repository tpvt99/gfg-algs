#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>


void bucketSort(int *a, int n, int k);
void insertionSort(std::vector<int> &v);

int main() {
    int a[] = {30, 40,10, 80, 5, 12, 70};
    bucketSort(a, sizeof(a)/sizeof(a[0]), 4);
    printf("Array after sort: ");
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
        printf("%d ", a[i]);
    }
    return 0;
}

void bucketSort(int *a, int n, int k) {
    std::vector<int> b[k];
    int maxValue = *std::max_element(a, a+k);
    int range = static_cast<int>(maxValue/k) + 1;
    for (int i = 0; i < n;i++) {
        int index = static_cast<int>(a[i]/range);
        b[index].push_back(a[i]);
    }

    printf("Bucket after assigning: ");
    for (int i = 0; i <k;i++) {
        printf("Bucket %d: ", i);
        for (int z : b[i]) {
            printf("%d ", z);
        }
        printf("\n");
    }

    for (int i = 0; i < k; i++) {
        insertionSort(b[i]);
    }

    int index = 0;
    for (int i = 0 ; i < k; i++) {
        for (int z: b[i]) {
            a[index++] = z;
        }
    }
}

void insertionSort(std::vector<int> &v) {
    if (v.size() <= 1)
        return;
    for (int i = 1; i < v.size(); i++) {
        int num = v.at(i);
        int j;
        for (j = i-1; j >= 0; j--) {
            if (v.at(j) > num) {
                v.at(j+1) = v.at(j);
            } else {
                break;
            }
        }
        v.at(j+1) = num;
    }
}