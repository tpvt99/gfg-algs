#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>

void addEdge(std::vector<int> adj[], int u, int v);
void initializeArray1(std::vector<int> adj[]);
void topologySorting(std::vector<int> adj[], int vertice, int* visitedNode, std::stack<int> &stack);
void helper(std::vector<int> adj[], int V);

int main() {
    int V = 5;
    std::vector<int> adj[V];
    initializeArray1(adj);
    helper(adj, V);
    return 0;
}

void addEdge(std::vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

void initializeArray1(std::vector<int> adj[]) {
    addEdge(adj, 1, 0);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 2, 4);
}

void topologySorting(std::vector<int> adj[], int vertice, int* visitedNode, std::stack<int> &stack) {
    visitedNode[vertice] = 1;
    for (auto adjency: adj[vertice]) {
        if (!visitedNode[adjency])
            topologySorting(adj, adjency, visitedNode, stack);
    }
    stack.push(vertice);
}

void helper(std::vector<int> adj[], int V) {
    int *visitedNode = new int[V];
    for (int i = 0; i < V; i++)
        visitedNode[i] = 0;
    std::stack<int> stack;
    for (int i = 0; i <V; i++) {
        if (!visitedNode[i])
            topologySorting(adj, i, visitedNode, stack);
    }
    while (!stack.empty()) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
}