#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

class DisjointSet { //to represent disjoint set
private:
    std::unordered_map<int, int> parent;
public:
    DisjointSet(std::vector<int> const &wholeset){
        //perform makeset operation
        for (int i : wholeset) // create n disjoint sets
            parent[i] = i;
    }
    int Find(int l) { // Find the root of the set in which element l belongs
        if (parent[l] == l) // if l is root
            return l;
        return Find(parent[l]); // recurs for parent till we find root
    }
    void Union(int m, int n) { // perform Union of two subsets m and n
        int x = Find(m);
        int y = Find(n);
        parent[x] = y;
    }
};

class Edge {
private:
    int m_source;
    int m_destination;
    int m_weight;
public:
    Edge(int source, int destination, int weight) {
        m_source = source;
        m_destination = destination;
        m_weight = weight;
    }
    int getWeight() {
        return m_weight;
    }
    int getSource() {
        return m_source;
    }
    int getDestination() {
        return m_destination;
    }
};

void initializeEdges1(std::vector<Edge> &edges);
void addEdge(std::vector<Edge> &edges, int source, int destination, int weight);
bool compareFunction(Edge edge1, Edge edge2);
int kruskal(std::vector<Edge> edges, int V);

int main() {
    int V = 6;
    std::vector<Edge> edges;
    initializeEdges1(edges);
    std::cout << kruskal(edges, V);
    return 0;
}

void initializeEdges1(std::vector<Edge> &edges) {
    addEdge(edges, 0, 2, 8);
    addEdge(edges, 0, 1, 10);
    addEdge(edges, 1, 2, 5);
    addEdge(edges, 1, 5, 3);
    addEdge(edges, 2, 5, 4);
    addEdge(edges, 2, 4, 12);
    addEdge(edges, 5, 4, 15);
}

bool compareFunction(Edge edge1, Edge edge2) {
    return edge1.getWeight() < edge2.getWeight();
}

void addEdge(std::vector<Edge> &edges, int source, int destination, int weight) {
    Edge edge(source, destination, weight);
    edges.push_back(edge);
}

int kruskal(std::vector<Edge> edges, int V) {
    std::sort(edges.begin(), edges.end(), compareFunction);

    std::vector<int> sets;
    for (int i = 0; i <V; i++)
        sets.push_back(i);
    DisjointSet ds(sets);

    int sum = 0;
    int verticeCount = 0;
    for (Edge e : edges) {
        // Find the first of edge in the disjoint set
        int source = e.getSource();
        int destination = e.getDestination();
        int sourceParent = ds.Find(source);
        int sourceDestination = ds.Find(destination);
        if (sourceParent != sourceDestination) {
            ds.Union(source, destination);
            sum += e.getWeight();
            verticeCount += 1;
        }
        if (verticeCount == (V-1))
            break;
    }
    return sum;

}