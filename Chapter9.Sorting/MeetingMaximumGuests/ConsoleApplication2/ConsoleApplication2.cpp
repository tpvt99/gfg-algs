// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>

int comp_func(const void* p1, const void* p2);


int main()
{
    int arrival_time[] = {900, 850, 930, 945};
    int departure_time[] = { 1000, 910, 1000, 1200 };

    // Step 1: sort the arrival time and departure time
    qsort(arrival_time, sizeof(arrival_time) / sizeof(arrival_time[0]), sizeof(arrival_time[0]), comp_func);
    qsort(departure_time, sizeof(departure_time) / sizeof(departure_time[0]), sizeof(departure_time[0]), comp_func);


    for (int i = 0; i < 4; i++) {
        printf("%d ", arrival_time[i]);
    }
    printf("\n");
    for (int i = 0; i < 4; i++) {
        printf("%d ", departure_time[i]);
    }

    // Step 2: find the the maximum guests

    int i = 0, j = 0;
    int counter = 0;
    int max_guests = 0;
    while (i < sizeof(arrival_time) / sizeof(arrival_time[0])) {
        if (arrival_time[i] <= departure_time[j]) {
            i++;
            counter += 1;
        }
        else {
            j++;
            counter -= 1;
        }
        max_guests = std::max(max_guests, counter);
    }
    printf("Max guests are: %d", max_guests);
}

int comp_func(const void* p1, const void* p2) {
    const int* q1 = (const int*)p1;
    const int* q2 = (const int*)p2;
    if (*q1 < *q2)
        return -1;
    else if (*q1 == *q2)
        return 0;
    else
        return 1;
}