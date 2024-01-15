#include<iostream>
#include<limits.h>
#include<string.h>
#include<queue>

using namespace std;

#define V 6


int edmondkarp(int graph[V][V],int s,int t)
{

    int u,v;

    int rGraph[V][V];

    for(int u=0;u<V;u++)
        for(int v=0;v<V;v++)
        rGraph[u][v]=graph[u][v];

    int parent[V];
    int max_flow=0;

    while(true)
    {



        bool visited[V];
        memset(visited,0,sizeof(visited));

        queue<int> q;
        q.push(s);
        visited[s]=true;
        parent[s]=-1;
        bool foundSink=false;

        while(!q.empty())
        {

            u=q.front();
            q.pop();


            for(v=0;v<V;v++)
            {

                if(visited[v]==false && rGraph[u][v]>0)
                {

                    if(v==t)
                    {
                        parent[v]=u;
                        foundSink=true;
                        break;
                    }

                    q.push(v);
                    parent[v]=u;
                    visited[v]=true;
                }
            }
            if(foundSink)
                break;

        }
        if(!foundSink)
            break;

        int path_flow=INT_MAX;
        for(v=t; v!=s; v=parent[v])
        {

            u=parent[v];
            path_flow=min(path_flow,rGraph[u][v]);
        }

         for(v=t; v!=s; v=parent[v])
        {

            u=parent[v];
            rGraph[u][v]-=path_flow;
            rGraph[v][u]+=path_flow;
        }

        max_flow+=path_flow;
    }

    return max_flow;
}



int main()
{


    int graph[V][V]={
    {0,16,13,0,0,0},
    {0,0,10,12,0,0},
    {0,4,0,0,14,0},
    {0,0,9,0,0,20},
    {0,0,0,7,0,4},
    {0,0,0,0,0,0}

};

cout<< "maximum possible flow is:"<<edmondkarp(graph,0,5);
return 0;
}
