#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

void addEdge(std::vector<int> adj[], int u, int v);
void initializeArray1(std::vector<int> adj[]);
bool helper(std::vector<int> adj[], int V);

int main() {
    int n = 6;
    std::vector<int> adj[n];
    initializeArray1(adj);
    std::cout << helper(adj, n);

    return 0;
}

void addEdge(std::vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

void initializeArray1(std::vector<int> adj[]) {
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 2);

}

bool detectCyclesDirectedGraph(std::vector<int> adj[], int *visitedNodes, int *recursiveCheck, int vertice) {
    if (visitedNodes[vertice] && recursiveCheck[vertice])
        return true;
    if (!visitedNodes[vertice] && recursiveCheck[vertice])
        throw std::invalid_argument("no such case");
    if (visitedNodes[vertice] && !recursiveCheck[vertice])
        return false;
    if (!visitedNodes[vertice] && !recursiveCheck[vertice]) {
        visitedNodes[vertice] = 1;
        recursiveCheck[vertice] = 1;
    }
    for (auto adjency: adj[vertice]) {
        if (detectCyclesDirectedGraph(adj, visitedNodes, recursiveCheck, adjency))
            return true;
    }
    recursiveCheck[vertice] = 0;
    return false;
}

bool helper(std::vector<int> adj[], int V) {
    int *visitedNodes = new int[V];
    int *recursiveCheck = new int[V];
    for (int i = 0; i < V; i++) {
        visitedNodes[i] = 0;
        recursiveCheck[i] = 0;
    }
    for (int i = 0; i <V; i++) {
        if (!visitedNodes[i]) {
            if (detectCyclesDirectedGraph(adj, visitedNodes, recursiveCheck, i))
                return true;
        }
    }
    return false;
}