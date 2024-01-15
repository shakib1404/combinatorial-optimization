#include<bits/stdc++.h>
using namespace std;

const int inf = 1e7;

int n = 0, m;
vector<vector<pair<int, int>>> graph(100 + 1);
string name[100];

void readInput()
{
    int u, v, w;
    string s;

    cin >> m;
    while (cin >> s)
    {
        if (s == "END")
            break;

        for (u = 0; u < n; u++)
        {
            if (name[u] == s)
                break;
        }
        if (u == n)
        {
            name[n] = s;
            n++;
        }

        cin >> s;
        for (v = 0; v < n; v++)
        {
            if (name[v] == s)
                break;
        }
        if (v == n)
        {
            name[n] = s;
            n++;
        }
        cin >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
}

int indexdao(string src)

{
    for(int i=0; i<n; i++)
        if(name[i]==src)
            return i;

    return -1;
}


int main()
{
     string source ; cout<<"give source:";cin>>source;
    freopen("dijkstra.txt", "r", stdin);
    readInput();

    vector<int> dist(n + 1, inf);
    vector<int> parent(n + 1, -1);
    // Assuming the source is the first city
    int srcInd=indexdao(source);
    dist[srcInd] = 0;

    set<pair<int, int>> s;
    s.insert({0, srcInd});

    while (!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        for (auto it : graph[x.second])
        {
            if (dist[it.first] > dist[x.second] + it.second)
            {
                s.erase({dist[it.first], it.first});
                dist[it.first] = dist[x.second] + it.second;
                s.insert({dist[it.first], it.first});
                parent[it.first] = x.second; // Update parent vertex
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (dist[i] < inf)
        {
            cout << "Shortest path to city " << name[i] << ": " << dist[i] << " (";
            vector<int> path;
            int cur = i;
            while (cur != -1)
            {
                path.push_back(cur);
                cur = parent[cur];
            }
            reverse(path.begin(), path.end());
            for (int j = 0; j < path.size(); j++)
            {
                cout << name[path[j]];
                if (j != path.size() - 1)
                    cout << " -> ";
            }
            cout << ")" << endl;
        }
        else
            cout << "No path to city " << name[i] << endl;
    }

    return 0;
}
