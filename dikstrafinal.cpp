#include <bits/stdc++.h>
using namespace std;
const int inf = 1e7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);
    vector<int> dist(n + 1, inf);
    vector<int> parent(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int source;
    cin >> source;
    dist[source] = 0;
    set<pair<int, int>> s;
    s.insert({0, source});

    while (!s.empty()) {
        auto x = *(s.begin());
        s.erase(x);

        for (auto it : graph[x.second]) {
            if (dist[it.first] > dist[x.second] + it.second) {
                s.erase({dist[it.first], it.first});
                dist[it.first] = dist[x.second] + it.second;
                s.insert({dist[it.first], it.first});
                parent[it.first] = x.second;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        if (dist[i] < inf) {
            cout << "Shortest path to vertex " << i << ": " << dist[i] << " (";
            vector<int> path;
            int cur = i;
            while (cur != -1) {
                path.push_back(cur);
                cur = parent[cur];
            }
            reverse(path.begin(), path.end());
            for (int j = 0; j < path.size(); j++) {
                cout << path[j];
                if (j != path.size() - 1)
                    cout << " -> ";
            }
            cout << ")" << endl;
        } else {
            cout << "No path to vertex " << i << endl;
        }
    }
}

