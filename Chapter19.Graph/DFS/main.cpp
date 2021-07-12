#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

void addEdge(std::vector<int> adj[], int u, int v);
void initializeArray1(std::vector<int> adj[]);
void initializeArray2(std::vector<int> adj[]);
void initializeArray3(std::vector<int> adj[]);

void dfsRecurrsive(std::vector<int> adj[], int vertice, std::vector<int> &visitedNode);
void dfsDisconnectRecurrsive(std::vector<int> adj[], int noOfVertices);

void dfsDisconnectStack(std::vector<int> adj[], int noOfVertices);
void dfsStack(std::vector<int> adj[], int vertice, std::vector<int> &visitedNode);

int main() {
    int n = 5;
    std::vector<int> adj[n];
    initializeArray3(adj);
    dfsDisconnectRecurrsive(adj, n);
    std::cout << std::endl;
    dfsDisconnectStack(adj, n);
    return 0;
}

void addEdge(std::vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void initializeArray1(std::vector<int> adj[]) {
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 5, 6);
}

void initializeArray2(std::vector<int> adj[]) {
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 4, 5);
}

void initializeArray3(std::vector<int> adj[]) {
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);

    addEdge(adj, 3, 4);
}
void dfsRecurrsive(std::vector<int> adj[], int vertice, std::vector<int> &visitedNode) {
    std::cout << vertice << " ";
    visitedNode.push_back(vertice);
    for (auto v : adj[vertice]) {
        if (std::find(visitedNode.begin(), visitedNode.end(), v) == visitedNode.end()) { // node is not visited
            dfsRecurrsive(adj, v, visitedNode);
        }
    }
}

void dfsStack(std::vector<int> adj[], int vertice, std::vector<int> &visitedNode) {
    if (std::find(visitedNode.begin(), visitedNode.end(), vertice) != visitedNode.end())
        return;
    std::stack<int> s;
    s.push(vertice);
    visitedNode.push_back(vertice);
    while(!s.empty()) {
        int top = s.top();
        s.pop();
        std::cout << top << " ";
        for (auto adjency: adj[top]) {
            if (std::find(visitedNode.begin(), visitedNode.end(), adjency) == visitedNode.end()) { // node is not visited
                s.push(adjency);
                visitedNode.push_back(adjency);
            }
        }
    }
}

void dfsDisconnectRecurrsive(std::vector<int> adj[], int noOfVertices) {
    std::vector<int> visitedNode;
    for (int i = 0; i < noOfVertices; i++) {
        if (std::find(visitedNode.begin(), visitedNode.end(), i) == visitedNode.end())
            dfsRecurrsive(adj, i, visitedNode);
    }
}

void dfsDisconnectStack(std::vector<int> adj[], int noOfVertices) {
    std::vector<int> visitedNode;
    for (int i = 0; i < noOfVertices; i++) {
        dfsStack(adj, i, visitedNode);
    }
}