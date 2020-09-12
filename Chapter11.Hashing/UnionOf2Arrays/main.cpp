#include <iostream>
#include <unordered_set>

void useSet(int *a, int n_a, int *b, int n_b);
void naiveMethod(int *a, int n_a, int *b, int n_b);

int main() {
    int a[] = {15, 20, 30, 20, 14, 15, 15, 15, 15};
    int b[] = {6, 9, 99, 12, 15, 15, 20};
    printf("Use hash set: ");
    useSet(a, sizeof(a)/sizeof(a[0]), b, sizeof(b)/sizeof(b[0]));
    printf("\n");
    printf("Use naive method: ");
    naiveMethod(a, sizeof(a)/sizeof(a[0]), b, sizeof(b)/sizeof(b[0]));
    return 0;
}

void useSet(int *a, int n_a, int *b, int n_b) {
    using std::unordered_set;
    unordered_set<int> m;
    for (int i = 0; i< n_a; i++) {
        m.insert(a[i]);
    }
    for (int i = 0 ; i < n_b; i++) {
        m.insert(b[i]);
    }
    for (auto it : m) {
        printf("%d ", it);
    }
}

void naiveMethod(int *a, int n_a, int *b, int n_b) {
    for (int i = 0; i < n_a; i++) {
        int flag = 0;
        for (int j = 0; j < i; j++) {
            if (a[i] == a[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            printf("%d ", a[i]);
    }
    for (int i = 0; i < n_b; i++) {
        int flag = 0;
        for (int j = i - 1; j < i; j++) {
            if (a[i] == a[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            continue;

        flag = 0;
        for (int j = 0; j < n_a; j++) {
            if (a[j] == b[i]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            printf("%d ", b[i]);

    }
}
