#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

void addEdge(std::vector<int> adj[], int u, int v) ;
void initializeArray1(std::vector<int> adj[]);
void initializeArray2(std::vector<int> adj[]);
void dfs(std::vector<int> adj[], int *visited, int *depth, int *low, int *parent, int vertice, int d);
void findArticulationPoint(std::vector<int> adj[], int V);

int main() {
    int V = 5;
    std::vector<int> adj[V];
    initializeArray2(adj);
    findArticulationPoint(adj, V);
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

void dfs(std::vector<int> adj[], int *visited, int *depth, int *low, int *parent, int vertice, int d) {
    visited[vertice] = 1;
    depth[vertice] = d;
    low[vertice] = d;
    int childCount = 0;
    bool isArticulation = false;

    for (int adjency: adj[vertice]) {
        if (!visited[adjency]) {
            parent[adjency] = vertice;
            childCount += 1;
            dfs(adj, visited, depth, low, parent, adjency, d+1);
            if (low[adjency] >= depth[vertice]) {
                isArticulation = true;
            }
            low[vertice] = std::min(low[adjency], low[vertice]);
        } else if (adjency != parent[vertice]) {
            low[vertice] = std::min(low[vertice], depth[adjency]);
        }
    }
    if (parent[vertice] == -1 && childCount > 1)
        std::cout << vertice << " ";
    if (isArticulation && parent[vertice] != -1)
        std::cout << vertice << " ";
}

void findArticulationPoint(std::vector<int> adj[], int V) {
    int *visited = new int [V];
    int *depth = new int [V];
    int *low = new int [V];
    int *parent = new int [V];
    for (int i =0 ; i <V; i++) {
        visited[i] = 0;
        depth[i] = 0;
        parent[i] = -1;
    }
    dfs(adj, visited, depth, low, parent, 0, 1);
    std::cout << std::endl;
    for (int i = 0; i < V; i++) {
        std::cout << "Vertice: " << i << " Depth: " << depth[i] << " Low: " << low[i] << " " << std::endl;
    }
}
