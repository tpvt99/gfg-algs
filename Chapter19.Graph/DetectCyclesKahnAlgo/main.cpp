#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

void addEdge(std::vector<int> adj[], int u, int v);
void initializeArray1(std::vector<int> adj[]);
bool detectCycle(std::vector<int> adj[], int V);
int *findIndegree(std::vector<int> adj[], int V);

int main() {
    int V = 5;
    std::vector<int> adj[V];
    initializeArray1(adj);
    std::cout << detectCycle(adj, V);
    return 0;
}

void addEdge(std::vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

void initializeArray1(std::vector<int> adj[]) {
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 3, 0);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
}

int *findIndegree(std::vector<int> adj[], int V) {
    int *indegrees = new int[V];
    for (int i = 0; i <V;i++)
        indegrees[i] = 0;
    for (int i = 0; i <V; i++) {
        for (auto toVertice: adj[i])
            indegrees[toVertice] = indegrees[toVertice] + 1;
    }
    return indegrees;
}

bool detectCycle(std::vector<int> adj[], int V) {
    int *indegree = findIndegree(adj, V);
    std::queue<int> q;
    for (int i = 0; i<V; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }
    int count = 0;
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        count++;
        for (auto adjency: adj[top]) {
            indegree[adjency]--;
            if (indegree[adjency] == 0)
                q.push(adjency);
        }
    }
    if (count == V)// For Kahn, it works in acyclic. So if it traverses all the vertice -> must be acyclic -> return false
        return false;
    return true;
}