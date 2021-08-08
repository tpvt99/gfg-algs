#include <iostream>
#include <vector>
#include <algorithm>

class Work {
private:
    int m_from;
    int m_to;
    bool m_visited{0};
public:
    Work(int from, int to) {
        m_from = from;
        m_to = to;
    }
    bool isOverlapping(Work &other) {
        return (m_from < other.m_to) && (m_to > other.m_from);
    }
    void unionWork(Work &other) {
        if (other.m_from < m_from)
            m_from = other.m_from;
        if (other.m_to > m_to)
            m_to = other.m_to;
    }
    void setVisited() {
        m_visited = 1;
    }
    void unsetVisited() {
        m_visited = 0;
    }
    int getEndTime() {
        return m_to;
    }
    int getBeginTime() {
        return m_from;
    }
};

int activitySelection(std::vector<Work> works, Work currentTime);
int activitySelectionEfficient(std::vector<Work> works);
int helper(std::vector<Work> works);
void initialize1(std::vector<Work> &works);
void initialize2(std::vector<Work> &works);
bool sort(Work work1, Work work2);

int main() {
    std::vector<Work> works;
    initialize2(works);
    std::cout << helper(works) << std::endl;
    std::cout << activitySelectionEfficient(works) << std::endl;
    return 0;
}

bool sort(Work work1, Work work2) {
    return work1.getEndTime() < work2.getEndTime();
}

void initialize1(std::vector<Work> &works) {
    works.push_back({2,3});
    works.push_back({1, 4});
    works.push_back({5,8});
    works.push_back({6,10});
}

void initialize2(std::vector<Work> &works) {
    works.push_back({1,3});
    works.push_back({2, 4});
    works.push_back({3,8});
    works.push_back({10,11});
}

int helper(std::vector<Work> works) {
    int n = 0;
    for (Work work: works) {
        work.setVisited();
        int result = activitySelection(works, work);
        n = std::max(result, n);
    }
    return n;
}

int activitySelection(std::vector<Work> works, Work currentTime) {
    int maxN = 0;
    for (Work nextTime: works) {
        int n = 0;
        if (!currentTime.isOverlapping(nextTime)) {
            nextTime.setVisited();
            currentTime.unionWork(nextTime);
            n = activitySelection(works, currentTime);
            maxN = std::max(n, maxN);
            nextTime.unsetVisited();
        }
    }
    return 1 + maxN;
}

int activitySelectionEfficient(std::vector<Work> works) {
    std::sort(works.begin(), works.end(), sort);
    Work newWork({works.at(0).getBeginTime(), works.at(0).getEndTime()});
    int n = 1;
    for (int i = 1 ; i < works.size(); i++) {
        Work currentWork = works.at(i);
        if (!newWork.isOverlapping(currentWork)) {
            newWork.unionWork(currentWork);
            n += 1;
        }
    }
    return n;
}