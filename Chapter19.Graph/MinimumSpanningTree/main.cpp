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
std::vector<AdjencyWeight> * spanningTree(std::vector<AdjencyWeight> adj[], int V);

int main() {
    int V = 4;
    std::vector<AdjencyWeight> adj[V];
    initializeArray1(adj);
    std::vector<AdjencyWeight> *output = spanningTree(adj, V);
    int *visited = new int[V];
    visited[0] = 1;
    for (int i = 0 ; i <V; i++) {
        std::vector<AdjencyWeight> adjency = output[i];
        for (auto adj: adjency) {
            if (!visited[adj.getVertice()]) {
                std::cout << "From " << i << " to " << adj.getVertice() << " weight: " << adj.getWeight() << std::endl;
                visited[adj.getVertice()] = 1;
            }
        }
    }
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

std::vector<AdjencyWeight> * spanningTree(std::vector<AdjencyWeight> adj[], int V) {
    std::vector<int> inMST;
    std::vector<int> notInMST;
    std::vector<AdjencyWeight> *spanningTree = new std::vector<AdjencyWeight>[V];
    inMST.push_back(0);
    int count = 1;
    int weight = 0;
    while (count < V) {
        Edge *edge = nullptr;
        for (auto inVertice: inMST) {
            // for each vertice, connect to its adjency that is not in the inMST. The min weights of vertice-adjency is the new one
            for (auto adjency: adj[inVertice]) {
                if (std::find(inMST.begin(), inMST.end(), adjency.getVertice()) == inMST.end()) {
                    if (edge == nullptr) {
                        edge = new Edge(inVertice, adjency.getVertice(), adjency.getWeight());
                    } else {
                        if (adjency.getWeight() < edge->getWeight())
                            edge = new Edge(inVertice, adjency.getVertice(), adjency.getWeight());
                    }
                }
            }
        }
        count++;
        inMST.push_back(edge->getTo());
        addEdge(spanningTree, edge->getFrom(), edge->getTo(), edge->getWeight());
        weight += edge->getWeight();
    }
    std::cout << weight << std::endl;
    return spanningTree;

}
