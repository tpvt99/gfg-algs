#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

void addEdge(std::vector<int> adj[], int u, int v);
void initializeArray1(std::vector<int> adj[]);
void initializeArray2(std::vector<int> adj[]);
bool detectCycle(std::vector<int> adj[], int vertice, int parent, int *visitedNodes);

int main() {
    int n = 3;
    std::vector<int> adj[n];

    initializeArray2(adj);
    int visitedNodes[n];
    for (int i = 0; i < n; i++)
        visitedNodes[i] = 0;
    std::cout << detectCycle(adj, 0, -1, visitedNodes);
    return 0;
}

void addEdge(std::vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void initializeArray1(std::vector<int> adj[]) {
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
}

void initializeArray2(std::vector<int> adj[]) {
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);

}

bool detectCycle(std::vector<int> adj[], int vertice, int parent, int *visitedNodes) {
    visitedNodes[vertice] = 1;

    for (int adjency: adj[vertice]) {
        if (visitedNodes[adjency] == 0) {
            if (detectCycle(adj, adjency, vertice, visitedNodes) == true)
                return true;
        } else {
            if (adjency != parent)
                return true;
        }
    }
    return false;
}