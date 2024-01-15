#include<bits/stdc++.h>
using namespace std;

int w[]={2,1,3,2};
int v[]={12,10,20,15};
int n=4;
int wei=5;
int p[5][6];

void knapsack()
{
    for(int i=0;i<=n;i++)
    {
        p[i][0]=0;
    }
     for(int i=0;i<=wei;i++)
    {
        p[0][i]=0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=wei;j++)
        {
            if(w[i-1]>j){
                p[i][j]=p[i-1][j];
            }
            else
                p[i][j]=max((v[i-1]+p[i-1][j-w[i-1]]),p[i-1][j]);
        }
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=wei;j++)
            cout<<p[i][j]<<" ";
        cout<<endl;
    }

    int i=n, j=wei;
    vector<int> chosenItems;

    while(i>0 && j>0)
    {
        if(p[i][j] != p[i-1][j])
        {
            chosenItems.push_back(i);
            j = j - w[i-1];
            i--;
        }
        else
        {
            i--;
        }
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=wei;j++)
            cout<<p[i][j]<<" ";
        cout<<endl;
    }

    cout<<"Max value: "<<p[4][5]<<endl;
    cout<<"Items taken: ";
    for(int i=0; i<chosenItems.size(); i++)
    {
        cout<<chosenItems[i]<<" ";
    }

}

int main()
{
    knapsack();
}
