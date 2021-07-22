#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class AdjencyWeight {
private:
    int m_vertice{};
    int m_weight{};
public:
    AdjencyWeight(int vertice, int weight) {
        m_vertice = vertice;
        m_weight = weight;
    }
    int getVertice() {
        return m_vertice;
    }
    int getWeight() {
        return m_weight;
    }
};

void addEdge(std::vector<AdjencyWeight> adj[], int u, int v, int weight);
void initializeArray1(std::vector<AdjencyWeight> adj[]);
void initializeArray2(std::vector<AdjencyWeight> adj[]);
void shortestPath(std::vector<AdjencyWeight> adj[], int source, int V);
int *findIndegree(std::vector<AdjencyWeight> adj[], int V);
void shortestPathUsingTopolicalSorting(std::vector<AdjencyWeight> adj[], int source, int V);

int main() {
    int V = 6;
    std::vector<AdjencyWeight> adj[V];
    initializeArray1(adj);
    shortestPath(adj, 1, V);
    std::cout << std::endl;
    shortestPathUsingTopolicalSorting(adj, 1, V);
    return 0;
}

void addEdge(std::vector<AdjencyWeight> adj[], int u, int v, int weight) {
    AdjencyWeight node(v, weight);
    adj[u].push_back(node);
}

void initializeArray1(std::vector<AdjencyWeight> adj[]) {
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 4, 1);
    addEdge(adj, 4, 2, 2);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 2, 3, 6);
    addEdge(adj, 4, 5, 4);
    addEdge(adj, 5, 3, 1);
}

void initializeArray2(std::vector<AdjencyWeight> adj[]) {
    addEdge(adj, 0, 1, 1);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 2, 3, 4);
    addEdge(adj, 1, 3, 2);
}

int *findIndegree(std::vector<AdjencyWeight> adj[], int V) {
    int *indegrees = new int[V];
    for (int i = 0; i <V;i++)
        indegrees[i] = 0;
    for (int i = 0; i <V; i++) {
        for (auto toVertice: adj[i])
            indegrees[toVertice.getVertice()] = indegrees[toVertice.getVertice()] + 1;
    }
    return indegrees;
}

void shortestPath(std::vector<AdjencyWeight> adj[], int source, int V) {
    std::queue<std::pair<int, int>> q;
    int *shortestPath =new int[V];
    for (int i = 0; i<V; i++)
        shortestPath[i] = INT32_MAX;

    q.push({source,0});

    while (!q.empty()) {
        std::pair<int, int> top = q.front();
        q.pop();
        int vertice = top.first;
        shortestPath[vertice] = std::min(top.second, shortestPath[vertice]);
        for (AdjencyWeight adjencyWeight : adj[vertice]) {
            int adjency = adjencyWeight.getVertice();
            int weight = adjencyWeight.getWeight();
            q.push({adjency, shortestPath[vertice] + weight});
        }
    }
    for (int i =0; i<V;i++){
        if (shortestPath[i] == INT32_MAX)
            std::cout << "INF" << " ";
        else
            std::cout << shortestPath[i] << " ";
    }
}

void shortestPathUsingTopolicalSorting(std::vector<AdjencyWeight> adj[], int source, int V) {
    // Step 1. Find indegrees
    int *indegrees = findIndegree(adj, V);
    std::queue<int> q;
    // Step 2. Push indegree = 0
    for (int i = 0 ; i <V; i++) {
        if (indegrees[i] == 0)
            q.push(i);
    }
    // Pop and loop through adjencies: minus 1, if indegress = 0, push to queue
    std::vector<int> toplogy;
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        toplogy.push_back(top);
        for (auto adjency: adj[top]) {
            indegrees[adjency.getVertice()] -= 1;
            if (indegrees[adjency.getVertice()] == 0)
                q.push(adjency.getVertice());
        }
    }
    // Step 3. Initialize distance = 0 for all vertices
    int *dist = new int[V];
    for (int i=0; i<V; i++) {
        dist[i] = INT16_MAX; // have to use int16 because int32 + weight will make a negative number which results a wrong number
    }
    dist[source] = 0;
    for (auto vertice: toplogy) {
        for (AdjencyWeight adjency: adj[vertice]) {
            if (dist[adjency.getVertice()] > dist[vertice] + adjency.getWeight()) {
                dist[adjency.getVertice()] = dist[vertice] + adjency.getWeight();
            }
        }
    }
    for (int i =0; i<V;i++){
        if (dist[i] == INT16_MAX)
            std::cout << "INF" << " ";
        else
            std::cout << dist[i] << " ";
    }
}