#include<bits/stdc++.h>

using namespace std;
char x[]={'a','b','c','b','d','a','b'};
char y[]={'b','d','c','a','b','a'};
void print_lcs(int b[][7],int i,int j)
{
    if(i==0||j==0)
        return;

    if(b[i][j]==-1)
    {
        print_lcs(b,i-1,j-1);
        cout<<x[i-1]<<" ";
    }
    else if(b[i][j]==-2)
    {
        print_lcs(b,i-1,j);
    }
    else{
        print_lcs(b,i,j-1);
    }
}

void lcs_length(int m,int n,int c[][7],int b[][7])
{
    for(int i=0;i<=m;i++)
    {
        c[i][0]=0;
    }
    for(int j=0;j<=n;j++)
    {
        c[0][j]=0;
    }
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
    {
        if(x[i-1]==y[j-1])
        {
            c[i][j]=c[i-1][j-1]+1;
            b[i][j]=-1;
        }
        else if(c[i-1][j]>=c[i][j-1])
        {
            c[i][j]=c[i-1][j];
            b[i][j]=-2;
        }

        else
        {
            c[i][j]=c[i][j-1];
            b[i][j]=-3;
        }
    }
    print_lcs(b,m,n);
}

int main()
{
   int m= sizeof(x)/sizeof(x[0]);
   int n=sizeof(y)/sizeof(y[0]);
   int b[8][7];
   int c[8][7];
   lcs_length(m,n,c,b);

    return 0;
}
