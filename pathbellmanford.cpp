#include<bits/stdc++.h>
#include<string.h>
using namespace std;

const int inf=1e7;
string name[100];
int n=0,m;
vector<vector<int>> edges;
void readInput()
{
    int u, v,w;
    string s;

    cin>>m;
    while (cin>>s)
    {
        if(s == "END")
            break;

        for(u = 0; u < n; u++)
        {
            if(name[u] == s)
                break;
        }
        if (u == n)
        {
            name[n] = s;
            n++;
        }

        cin >> s;
        for(v = 0; v < n; v++)
        {
            if(name[v] == s)
                break;
        }
        if (v == n)
        {
            name[n] = s;
            n++;
        }
        cin>>w;

        edges.push_back({u,v,w});

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
    string src;
    cin>>src;
    //int n,m;
    freopen("bellmanford.txt","r",stdin);
    // cin>>n>>m;

    //  vector<vector<int>> edges;

    /*  for(int i=0;i<m;i++)
      {
         int u,v,w;

          cin>>u>>v>>w;
          edges.push_back({u,v,w});
     }*/




    readInput();
    // Add these lines after reading input:
    cout << "n: " << n << ", m: " << m << endl;
    cout << "Edges:" << endl;
    for(auto e : edges)
    {
        cout << e[0] << " " << e[1] << " " << e[2] << endl;
    }


    int srcInd=indexdao(src);

    vector<int> dist(n+1,inf);

    dist[srcInd]=0;
    bool change=true;
    vector<int> parent(n+1, -1);

    for(int iter=0; iter<n; iter++)
    {
        change = false;
        // Reset change flag at the beginning of each iteration
        for(auto e:edges)
        {

            int u=e[0];
            int v=e[1];
            int w=e[2];

            if(dist[v]>w+dist[u])
            {
                change=true;
                parent[v] = u;
                dist[v]=w+dist[u];
            }
        }
    }

    // Check for negative cycles
    if(change)
    {
        cout << "Negative cycle detected!" << endl;
        return 0;
    }

    for(int i=0; i<n; i++)
    {
        if(dist[i]<inf)
        {
            cout << "Shortest path to vertex " << name [i] << ": " <<dist[i] << " (";
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
            cout<< "No path to vertex " << i << endl;
    }

    return 0;
}
