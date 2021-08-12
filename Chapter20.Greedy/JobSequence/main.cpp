#include <iostream>
#include <vector>
#include <algorithm>

class Job {
private:
    int deadline;
    int profit;
public:
    Job(int d, int p) {
        deadline = d;
        profit = p;
    }
    int getDeadline() {
        return deadline;
    }
    int getProfit() {
        return profit;
    }
};

bool sortJobByProfit(Job j1, Job j2);
void initializeJobs(std::vector<Job> &jobs);
void maxProfit(std::vector<Job> jobs);

int main() {
    std::vector<Job> jobs;
    initializeJobs(jobs);
    maxProfit(jobs);
    return 0;
}

bool sortJobByProfit(Job j1, Job j2) {
    return j1.getProfit() > j2.getProfit();
}

void initializeJobs(std::vector<Job> &jobs) {
    jobs.push_back({2, 100});
    jobs.push_back({1, 50});
    jobs.push_back({2, 10});
    jobs.push_back({1, 20});
    jobs.push_back({3, 30});
}

bool sortJobByDeadline(Job j1, Job j2) {
    return j1.getDeadline() < j2.getDeadline();
}

void maxProfit(std::vector<Job> jobs) {
    std::sort(jobs.begin(), jobs.end(), sortJobByProfit);
    int maxArraysize = std::max_element(jobs.begin(), jobs.end(), sortJobByDeadline)->getDeadline();

    int *markArray = new int[maxArraysize];
    for (int i = 0; i < maxArraysize; i++)
        markArray[i] = 0;
    int profits = 0;
    for (Job job : jobs) {
        int deadline = job.getDeadline();
        bool marked = false;
        for (int i = deadline-1; i >= 0; i--) {
            if (!markArray[i]) {
                markArray[i] = 1;
                marked = true;
                break;
            }
        }
        if (marked)
            profits += job.getProfit();
    }
    std::cout << profits;
}