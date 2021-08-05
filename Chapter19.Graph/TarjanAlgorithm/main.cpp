#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

void addEdge(std::vector<int> adj[], int u, int v) ;
void initializeArray1(std::vector<int> adj[]);
void initializeArray2(std::vector<int> adj[]);
void dfs(std::vector<int> adj[], int *visited, int *depth, int *low, int *parent, int vertice, int d, std::vector<int> &stk);
void findConnectedComponents(std::vector<int> adj[], int V);

int main() {
    int V = 5;
    std::vector<int> adj[V];
    initializeArray2(adj);
    findConnectedComponents(adj, V);
    return 0;
}

void addEdge(std::vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

void initializeArray1(std::vector<int> adj[]) {
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);
}

void initializeArray2(std::vector<int> adj[]) {
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 1);
    addEdge(adj, 2, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 2);

}

void dfs(std::vector<int> adj[], int *visited, int *depth, int *low, int *parent, int vertice, int d, std::stack<int> &stk) {
    visited[vertice] = 1;
    depth[vertice] = d;
    low[vertice] = d;
    stk.push(vertice);

    for (int adjency: adj[vertice]) {
        if (!visited[adjency]) {
            parent[adjency] = vertice;
            dfs(adj, visited, depth, low, parent, adjency, d+1, stk);
            low[vertice] = std::min(low[adjency], low[vertice]);
        } else if (adjency != parent[vertice]) {
            low[vertice] = std::min(low[vertice], depth[adjency]);
        }
    }

    if (low[vertice] == depth[vertice]) {
        while (!stk.empty()) {
            int top = stk.top();
            stk.pop();
            std::cout << top << " ";
            if (top == vertice)
                break;
        }
        std::cout << std::endl;
    }

}

void findConnectedComponents(std::vector<int> adj[], int V) {
    int *visited = new int [V];
    int *depth = new int [V];
    int *low = new int [V];
    int *parent = new int [V];
    for (int i =0 ; i <V; i++) {
        visited[i] = 0;
        depth[i] = 0;
        parent[i] = -1;
    }
    std::stack<int> stk;
    dfs(adj, visited, depth, low, parent, 0, 1, stk);
    for (int i = 0 ; i<V; i++) {

    }
}