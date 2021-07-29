#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

void addEdge(std::vector<int> adj[], int u, int v);
void dfsForTopological(std::vector<int> adj[], int vertice, int* visitedNode, std::stack<int> &stack);
std::vector<int> topologySorting(std::vector<int> adj[], int V);
void stronglyConnectedComponents(std::vector<int> adj[], int V);
std::vector<int> * reverseEdge(std::vector<int> adj[], int V);
void dfs(std::vector<int> adj[], int vertice, int*visitedNode);
void initialize1(std::vector<int> adj[]);
void initialize2(std::vector<int> adj[]);

int main() {
    int V = 6;
    std::vector<int> adj[V];
    initialize2(adj);
    stronglyConnectedComponents(adj, V);
    return 0;
}

void initialize1(std::vector<int> adj[]) {
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 1);
    addEdge(adj, 1, 0);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 3);
}

void initialize2(std::vector<int> adj[]) {
    addEdge(adj, 0, 1);
    addEdge(adj, 2, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 4);

}

void addEdge(std::vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

void dfsForTopological(std::vector<int> adj[], int vertice, int* visitedNode, std::stack<int> &stack) {
    visitedNode[vertice] = 1;
    for (auto adjency: adj[vertice]) {
        if (!visitedNode[adjency])
            dfsForTopological(adj, adjency, visitedNode, stack);
    }
    stack.push(vertice);
}

void dfs(std::vector<int> adj[], int vertice, int*visitedNode) {
    visitedNode[vertice] = 1;
    std::cout << vertice << " ";
    for (auto adjency: adj[vertice]) {
        if (!visitedNode[adjency])
            dfs(adj, adjency, visitedNode);
    }
}

std::vector<int> topologySorting(std::vector<int> adj[], int V) {
    int *visitedNode = new int[V];
    for (int i = 0; i < V; i++)
        visitedNode[i] = 0;
    std::stack<int> stack;
    for (int i = 0; i <V; i++) {
        if (!visitedNode[i])
            dfsForTopological(adj, i, visitedNode, stack);
    }
    std::vector<int> v;
    while (!stack.empty()) {
        v.push_back(stack.top());
        stack.pop();
    }
    return v;
}

std::vector<int> * reverseEdge(std::vector<int> adj[], int V) {
    std::vector<int> *newAdj = new std::vector<int>[V];
    for (int i = 0; i < V; i++) {
        std::vector<int> adjecies = adj[i];
        for (int vertice: adjecies) {
            newAdj[vertice].push_back(i);
        }
    }
    return newAdj;
}

void stronglyConnectedComponents(std::vector<int> adj[], int V) {
    // First step, find the topological sorting
    std::vector<int> orders = topologySorting(adj, V);
    // Reverse the edge
    std::vector<int> *newAjd = reverseEdge(adj, V);
    // Step 3, do DFS
    int *visitedNodes = new int[V];
    for (int i = 0; i < V; i++)
        visitedNodes[i] = 0;
    for (auto vertice: orders) {
        if (!visitedNodes[vertice]) {
            dfs(newAjd, vertice, visitedNodes);
            std::cout << std::endl;
        }
    }
}