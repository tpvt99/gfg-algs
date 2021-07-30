#include <iostream>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

void addEdge(std::vector<std::vector<int>> adj[], int u, int v, int w);
void initialize1(std::vector<std::vector<int>>adj[]);
void initialize2(std::vector<std::vector<int>>adj[]);
void bellmanFord(std::vector<std::vector<int>> adj[], int source, int V);

int main() {
    int V = 4;
    std::vector<std::vector<int>> adj[V];
    initialize2(adj);
    bellmanFord(adj, 0, V);
    return 0;
}

void initialize1(std::vector<std::vector<int>> adj[]) {
    addEdge(adj, 0, 1, 1);
    addEdge(adj, 0, 2, 4);
    addEdge(adj, 1, 2, -3);
    addEdge(adj, 1, 3, 2);
    addEdge(adj, 2, 3, 3);
}

void initialize2(std::vector<std::vector<int>> adj[]) {
    addEdge(adj, 0, 1, 1);
    addEdge(adj, 2, 0, -4);
    addEdge(adj, 1, 2, -3);
    addEdge(adj, 1, 3, 2);
    addEdge(adj, 2, 3, 3);
}

void addEdge(std::vector<std::vector<int>> adj[], int u, int v, int w) {
    std::vector<int> edge;
    edge.push_back(v);
    edge.push_back(w);
    adj[u].push_back(edge);
}

void bellmanFord(std::vector<std::vector<int>> adj[], int source, int V) {
    int *distance = new int [V];
    for (int i = 0; i <V; i++)
        distance[i] = INT16_MAX;
    distance[source] = 0;
    // Get all the edges
    std::vector<std::vector<int>> edges;
    for (int vertice = 0; vertice < V; vertice++) {
        std::vector<std::vector<int>> adjencyList = adj[vertice];
        for (auto adjency: adjencyList) {
            std::vector<int> u;
            u.push_back(vertice);
            u.push_back(adjency.at(0));
            u.push_back(adjency.at(1));
            edges.push_back(u);
        }
    }
    // Relax
    for (int i = 0; i < V; i++) {
        for (auto edge: edges) {
            int u = edge.at(0);
            int v = edge.at(1);
            int weight = edge.at(2);
            if (distance[v] > distance[u] + weight)
                distance[v] = distance[u] + weight;
        }
    }
    // Check negative cycles
    for (int i = 0; i < V; i++) {
        for (auto edge: edges) {
            int u = edge.at(0);
            int v = edge.at(1);
            int weight = edge.at(2);
            if (distance[v] > distance[u] + weight) {
                std::cout << "Negative cycles detected";
                return;
            }
        }
    }

    for (int i = 0; i < V; i++)
        std::cout << distance[i] << " ";
}