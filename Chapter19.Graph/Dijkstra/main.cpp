#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

void initialize(std::vector<std::vector<int>> adj[]);
void initialize2(std::vector<std::vector<int>> adj[]);
void addEdge(std::vector<std::vector<int>> adj[], int source, int to, int weight);
void dijkstraHeap(std::vector<std::vector<int>> adj[], int V, int S);
void dijkstraUsingArray(std::vector<std::vector<int>> adj[], int V, int S);

int main() {
    int V = 9;
    std::vector<std::vector<int>> adj[V];
    initialize(adj);
    dijkstraHeap(adj, V, 0);
    std::cout << std::endl;
    dijkstraUsingArray(adj, V, 0);
    return 0;
}

void initialize(std::vector<std::vector<int>> adj[]) {
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 2, 8);
    addEdge(adj, 1, 2, 11);
    addEdge(adj, 1, 3, 8);
    addEdge(adj, 2, 4, 7);
    addEdge(adj, 3, 4, 2);
    addEdge(adj, 2, 5, 1);
    addEdge(adj, 4, 5, 6);
    addEdge(adj, 3, 6, 7);
    addEdge(adj, 3, 7, 4);
    addEdge(adj, 5, 7, 2);
    addEdge(adj, 6, 7, 14);
    addEdge(adj, 6, 8, 9);
    addEdge(adj, 7, 8, 10);
}

void initialize2(std::vector<std::vector<int>> adj[]) {
    addEdge(adj, 0, 3, 8);
    addEdge(adj, 1, 3, 10);
    addEdge(adj, 1, 2, 7);

}

void addEdge(std::vector<std::vector<int>> adj[], int source, int to, int weight) {
    std::vector<int> v;
    v.push_back(to);
    v.push_back(weight);
    adj[source].push_back(v);
    std::vector<int> u;
    u.push_back(source);
    u.push_back(weight);
    adj[to].push_back(u);
}

void dijkstraHeap(std::vector<std::vector<int>> adj[], int V, int S) {
    int *dist = new int[V];
    for (int i = 0; i <V; i++)
        dist[i] = INT16_MAX;
    dist[S] = 0;
    int *fin = new int [V];
    for (int i =0; i<V; i++)
        fin[i] = 0;

    auto compare {
            [](std::vector<int> l, std::vector<int> r) {
                return l.at(1)>r.at(1);
            }};
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(compare)> q(compare);

    for (int i = 0; i <V; i++) {
        std::vector<int> v;
        v.push_back(i);
        v.push_back(dist[i]);
        q.push(v);
    }
    while(!q.empty()) {
        std::vector<int> min = q.top();
        q.pop();
        fin[min.at(0)] = 1;
        for (std::vector<int> adjencies: adj[min.at(0)]) {
            int toVertice = adjencies.at(0);
            int weight = adjencies.at(1);
            if (fin[toVertice] == 0) {
                if (dist[toVertice] > dist[min.at(0)] + weight) {
                    dist[toVertice] = dist[min.at(0)] + weight;
                }
            }
        }
        // There should be a decrease key here but i don't know how to code so I have to update all the priority queue
        // By poping it out and pushing it back again
        std::vector<std::vector<int>> newQ;
        while(!q.empty()) {
            min = q.top();
            q.pop();
            min.at(1) = dist[min.at(0)];
            newQ.push_back(min);
        }
        // Push it back
        for (std::vector<int> v : newQ)
            q.push(v);
    }
    for (int i = 0; i < V; i++)
        std::cout << dist[i] << " ";
}

void dijkstraUsingArray(std::vector<std::vector<int>> adj[], int V, int S) {
    int *dist = new int[V];
    for (int i = 0; i <V; i++)
        dist[i] = INT16_MAX;
    dist[S] = 0;

    int *fin = new int [V];
    for (int i =0; i<V; i++)
        fin[i] = 0;

    for (int count = 0; count < V; count++) {
        // Find the min that is not in finalized
        int u = -1;
        for (int i = 0; i < V; i++) {
            if (!fin[i] && (u==-1 || dist[i] < dist[u]))
                u = i;
        }
        fin[u] = 1;
        for (std::vector<int> adjency: adj[u]) {
            int v = adjency.at(0);
            int w = adjency.at(1);
            if ((!fin[v]) && (dist[v] > dist[u] + w))
                dist[v] = dist[u] + w;
        }
    }
    for (int i = 0; i < V; i++)
        std::cout << dist[i] << " ";

}
