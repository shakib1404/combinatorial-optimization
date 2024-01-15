#include<iostream>
#include<limits.h>
#include<string.h>
#include<queue>

using namespace std;

#define V 100

int graph[V][V];

string name[100];
int n = 0, m;

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

        graph[u][v] = w;
    }
}

int edmondkarp(int s, int t)
{
    int rGraph[V][V];

    for (int u = 0; u < n; u++)
        for (int v = 0; v < n; v++)
            rGraph[u][v] = graph[u][v];

    int parent[V];
    int max_flow = 0;

    while (true)
    {
        bool visited[V];
        memset(visited, 0, sizeof(visited));

        queue<int> q;
        q.push(s);
        visited[s] = true;
        parent[s] = -1;
        bool foundSink = false;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v = 0; v < n; v++)
            {
                if (!visited[v] && rGraph[u][v] > 0)
                {
                    if (v == t)
                    {
                        parent[v] = u;
                        foundSink = true;
                        break;
                    }

                    q.push(v);
                    parent[v] = u;
                    visited[v] = true;
                }
            }
            if (foundSink)
                break;
        }
        if (!foundSink)
            break;

        int path_flow = INT_MAX;
        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main()
{
    freopen("edmondkarp.txt", "r", stdin);
    readInput();

    // Assuming source is vertex 0 and sink is vertex n - 1
    int source = 0;
    int sink = n - 1;

    cout << "Maximum possible flow is: " << edmondkarp(source, sink) << endl;

    return 0;
}
