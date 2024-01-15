#include<bits/stdc++.h>

using namespace std;

const int INF=1e9;
int n,m;
string name[101];
vector<vector<int>> graph(100, vector<int>(100, INF));
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

        graph[u][v]=w;
    }
}


int main()
{
    /*vector<vector<int>> graph= { {0,5,INF,10},
                                {INF,0,3,INF},
                                {INF,INF,0,1},
                                {INF,INF,INF,0}
                             };

    int n = graph.size();
    */
    freopen("floyd.txt","r",stdin);
    readInput();
    vector<vector<int>> dist = graph;

    vector<vector<int>> next(n, vector<int>(n, -1)); // Keep track of next vertex for path reconstruction

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = k; // Update next vertex
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j) {
                cout << "Shortest path from vertex " << name[i] << " to " << name[j ]<< ": ";
                int u = i, v = j;
                while (next[u][v] != -1) {
                    cout << name[u] << " -> ";
                    u = next[u][v];
                }
                cout << name[u] << " -> " << name[v] << " (Distance: ";
                if (dist[i][j] == INF)
                    cout << "INF";
                else
                    cout << dist[i][j];
                cout << ")" << endl;
            }
        }
    }
}

