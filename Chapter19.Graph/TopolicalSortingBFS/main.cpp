#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

void addEdge(std::vector<int> adj[], int u, int v);
void initializeArray1(std::vector<int> adj[]);
void topolicalSorting(std::vector<int> adj[], int V);
int *findIndegree(std::vector<int> adj[], int V);

int main() {
    int n = 5;
    std::vector<int> adj[n];
    initializeArray1(adj);
    topolicalSorting(adj, n);
    return 0;
}

void addEdge(std::vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

void initializeArray1(std::vector<int> adj[]) {
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
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

void topolicalSorting(std::vector<int> adj[], int V) {
    // Step 1. Find indegrees
    int *indegrees = findIndegree(adj, V);
    std::queue<int> q;
    // Step 2. Push indegree = 0
    for (int i = 0 ; i <V; i++) {
        if (indegrees[i] == 0)
            q.push(i);
    }
    // Pop and loop through adjencies: minus 1, if indegress = 0, push to queue
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        std::cout << top << " ";
        for (auto adjency: adj[top]) {
            indegrees[adjency] -= 1;
            if (indegrees[adjency] == 0)
                q.push(adjency);
        }
    }
}
