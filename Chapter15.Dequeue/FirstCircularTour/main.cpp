#include <iostream>

int circularTour(int *petrol, int *dist, int n);

int main() {
    int petrol[] = {8, 9, 4};
    int dist[] = {5, 10, 12};
    std::cout << circularTour(petrol, dist, 3);
    return 0;
}

int circularTour(int *petrol, int *dist, int n) {
    int sum = 0;
    int start = 0;
    int prev_petrol = 0;
    for (int i = 0; i < n;i++) {
        sum += (petrol[i] - dist[i]);
        if (sum < 0) {
            prev_petrol += sum;
            sum = 0;
            start = i+1;

        }
    }
    return (sum + prev_petrol >= 0) ? start + 1 : -1;

}
