#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int vertex, vector<int>& parent) {
    if (parent[vertex] == -1)
        return vertex;
    return findParent(parent[vertex], parent);
}

void kruskal(vector<Edge>& edges, int numVertices) {
    sort(edges.begin(), edges.end(), compareEdges);

    vector<int> parent(numVertices, -1);
    vector<Edge> mst;

    for (Edge edge : edges) {
        int u = edge.src;
        int v = edge.dest;

        int uParent = findParent(u, parent);
        int vParent = findParent(v, parent);

        if (uParent != vParent) {
            mst.push_back(edge);
            parent[uParent] = vParent;
        }
    }

    cout << "Minimum Spanning Tree:" << endl;
    int sum=0;
    for (Edge edge : mst) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
        sum+=edge.weight;
    }

    cout<<"total path:"<<sum;
}

int main() {
    int numVertices = 6;
    vector<Edge> edges = {
        {0, 1, 4},
        {0, 2, 4},
        {1, 2, 2},
        {1, 0, 4},
        {2, 0, 4},
        {2, 1, 2},
        {2, 3, 3},
        {2, 5, 2},
        {2, 4, 4},
        {3, 2, 3},
        {3, 4, 3},
        {4, 2, 4},
        {4, 3, 3},
        {5, 2, 2},
    };

    kruskal(edges, numVertices);

    return 0;
}
