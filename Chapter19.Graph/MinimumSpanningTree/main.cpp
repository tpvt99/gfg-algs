#include <iostream>
#include <vector>
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

class Edge {
private:
    int m_from{};
    int m_to{};
    int m_weight{};
public:
    Edge(int from, int to, int weight) {
        m_from = from;
        m_to = to;
        m_weight = weight;
    }
    int getWeight() {
        return m_weight;
    }
    int getFrom() {
        return m_from;
    }
    int getTo() {
        return m_to;
    }
};

void addEdge(std::vector<AdjencyWeight> adj[], int u, int v, int weight);
void initializeArray1(std::vector<AdjencyWeight> adj[]);
int spanningTree(std::vector<AdjencyWeight> adj[], int V);

int main() {
    int V = 4;
    std::vector<AdjencyWeight> adj[V];
    initializeArray1(adj);
    int output = spanningTree(adj, V);
    std::cout << output;
    return 0;
}

void addEdge(std::vector<AdjencyWeight> adj[], int u, int v, int weight) {
    AdjencyWeight node1(v, weight);
    adj[u].push_back(node1);
    AdjencyWeight node2(u, weight);
    adj[v].push_back(node2);
}

void initializeArray1(std::vector<AdjencyWeight> adj[]) {
    addEdge(adj, 0, 1, 5);
    addEdge(adj, 0, 2, 8);
    addEdge(adj, 1, 2, 10);
    addEdge(adj, 1, 3, 5);
    addEdge(adj, 2, 3, 20);
}

int spanningTree(std::vector<AdjencyWeight> adj[], int V) {
    int *key = new int[V];
    for (int i = 0; i <V; i++)
        key[i] = INT16_MAX;
    key[0] = 0;

    int *fin = new int [V];
    for (int i =0; i<V; i++)
        fin[i] = 0;
    int res = 0;
    for (int count = 0; count < V; count++) {
        // Find the min that is not in finalized
        int u = -1;
        for (int i = 0; i < V; i++) {
            if (!fin[i] && (u==-1 || key[i] < key[u]))
                u = i;
        }
        fin[u] = 1;
        res += key[u];
        for (AdjencyWeight adjency: adj[u]) {
            int v = adjency.getVertice();
            int w = adjency.getWeight();
            if ((!fin[v]) && (key[v] > w))
                key[v] = w;
        }
    }
    return res;

}
