#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

void addEdge(std::vector<int> adj[], int u, int v);
void initializeArray1(std::vector<int> adj[]);
void initializeArray2(std::vector<int> adj[]);
void initializeArray3(std::vector<int> adj[]);
void bfs(std::vector<int> adj[], int vertice);

int main() {
    std::vector<int> adj[6];
    initializeArray3(adj);
    bfs(adj, 0);
    return 0;
}

void initializeArray1(std::vector<int> adj[]) {
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
}

void initializeArray2(std::vector<int> adj[]) {
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
}

void initializeArray3(std::vector<int> adj[]) {
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 5);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);
}

void addEdge(std::vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(std::vector<int> adj[], int vertice) {
    std::vector<int> visitedNode;

    // Create a min heap that top element has least elements
    auto compare {
            [](std::vector<int> l, std::vector<int> r) {
                return l.size() > r.size();
            }};

    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(compare)> q(compare);

    std::vector<int> a;
    a.push_back(vertice);
    q.push(a);
    while (!q.empty()) {
        // Pop the top, print the last element of the top, push this element into visitedNode
        std::vector<int> top = q.top();
        q.pop();
        int lastNode = top.at(top.size() - 1);
        if (std::find(visitedNode.begin(), visitedNode.end(), lastNode) == visitedNode.end())
            visitedNode.push_back(lastNode);
        // Traverse the adjency list, push the new node into top if node is not in visitedNode.
        // For each successfully-pushed node into top, push this newly change queue to the q
        for (auto adjency : adj[lastNode]) {
            if (std::find(visitedNode.begin(), visitedNode.end(), adjency) == visitedNode.end()) {
                std::vector<int> newVector(top);
                newVector.push_back(adjency);
                q.push(newVector);
            }
        }
    }

    for (auto x : visitedNode)
        std::cout << x << " ";
}