#include<bits/stdc++.h>
#define l 10

int graph[l][l]={0};

using namespace std;

int minimumvertex(vector<int> &value,vector<bool> &setMst,int m)

{


    int minimum=INT_MAX;
    int vertex;

    for(int i=0;i<m;i++)
    {
        if(setMst[i]==false && value[i]<minimum)
        {
            vertex=i;
            minimum=value[i];
        }
    }
    return vertex;
}

void findMst(int m)

{
    int parent[m];
    vector<int> value(m,INT_MAX);
    vector<bool> setMst(m,false);

    parent[0]=-1;
    value[0]=0;

    for(int i=0;i<m-1;i++)
    {
       int u=minimumvertex(value,setMst,m) ;
       setMst[u]=true;

        for(int j=0;j<m;j++)
        {

            if(graph[u][j]!=0&&setMst[j]==false && graph[u][j]<value[j])
            {
                value[j]=graph[u][j];
                parent[j]=u;
            }
        }

    }
    int sum=0;
for(int i=1;i<m;i++)
{
    cout<<"U->V:"<<parent[i]<<"-> "<<i<<" wt"<<graph[parent[i]][i]<<endl;
    sum+=graph[parent[i]][i];
}
cout<<"total distance:"<<sum;

}




int main()

{

    int student;
    int pairs;
    // int numstu[student];
    //freopen("lab1.txt","r",stdin);
    cin>>student>>pairs;

   int numstu[student];

    for(int i=0;i<student;i++)
    {
        cin>>numstu[i];
       // graph[0][i]=numstu[i];

    }

    for(int i=1;i<=student;i++)
    {

        graph[0][i]=numstu[i-1];

    }
    int pairsele[pairs][2];
    for(int i=0;i<pairs;i++)
    {

     for(int j=0;j<2;j++)
     {
         cin>>pairsele[i][j];
         //graph[i][j]=0;
     }

    for(int j=0;j<1;j++)
     {

         graph[pairsele[i][j]][pairsele[i][j+1]]=0;
     }




    }
    findMst(student+1);

  //  edmondkarp(0,n-1);



}

