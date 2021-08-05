#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

void addEdge(std::vector<int> adj[], int u, int v) ;
void initializeArray1(std::vector<int> adj[]);
void initializeArray2(std::vector<int> adj[]);
void dfs(std::vector<int> adj[], int *visited, int *depth, int *low, int *parent, int vertice, int d, std::vector<std::pair<int, int>> &br);
void findBridge(std::vector<int> adj[], int V);

int main() {
    int V = 5;
    std::vector<int> adj[V];
    initializeArray1(adj);
    findBridge(adj, V);
    return 0;
}

void addEdge(std::vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void initializeArray1(std::vector<int> adj[]) {
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 4, 3);
}

void initializeArray2(std::vector<int> adj[]) {
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 4, 3);
    addEdge(adj, 4, 2);

}

void dfs(std::vector<int> adj[], int *visited, int *depth, int *low, int *parent, int vertice, int d, std::vector<std::pair<int, int>> &br) {
    visited[vertice] = 1;
    depth[vertice] = d;
    low[vertice] = d;

    for (int adjency: adj[vertice]) {
        if (!visited[adjency]) {
            parent[adjency] = vertice;
            dfs(adj, visited, depth, low, parent, adjency, d+1, br);
            if (low[adjency] > depth[vertice]) {
                br.push_back({vertice, adjency});
            }
            low[vertice] = std::min(low[adjency], low[vertice]);
        } else if (adjency != parent[vertice]) {
            low[vertice] = std::min(low[vertice], depth[adjency]);
        }
    }

}

void findBridge(std::vector<int> adj[], int V) {
    int *visited = new int [V];
    int *depth = new int [V];
    int *low = new int [V];
    int *parent = new int [V];
    for (int i =0 ; i <V; i++) {
        visited[i] = 0;
        depth[i] = 0;
        parent[i] = -1;
    }
    std::vector<std::pair<int, int>> br;
    dfs(adj, visited, depth, low, parent, 0, 1, br);
    for (auto p: br) {
        std::cout << p.first << " " << p.second << std::endl;
    }
}