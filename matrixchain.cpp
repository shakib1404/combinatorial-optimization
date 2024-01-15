#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void printParenthesis(int i, int j, vector<vector<int>>& bracket, char& name) {
    if (i == j) {
        cout << name++;
        return;
    }

    cout << "(";
    printParenthesis(i, bracket[i][j], bracket, name);
    printParenthesis(bracket[i][j] + 1, j, bracket, name);
    cout << ")";
}

void matrixChainOrder(vector<int>& p) {
    int n = p.size() - 1;
    vector<vector<int>> m(n, vector<int>(n, 0));
    vector<vector<int>> bracket(n, vector<int>(n, 0));

    for (int d = 1; d < n; d++) {
        for (int i = 0; i < n - d; i++) {
            int j = i + d;
            m[i][j] = INT_MAX;
            for (int k = i; k <j; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i] * p[k +1] * p[j+1];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    bracket[i][j] = k;
                }
            }
        }
    }


   /* for(int l=2;l<=n;l++)
    {
        for(int i=1;i<=n-l+1;i++)
        {
            int j=i-l+1;
            m[i][j]=INT_MAX;
            for(int k=i;k<=j-1;k++)
            {
                int q=m[i][k]+m[k+1][j]+p[i-1]*p[j]*p[k];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    bracket[i][j]=k;
                }
            }

        }
    }*/

    char name = 'A';
    cout << "Optimal Parenthesization: ";
    printParenthesis(0, n - 1, bracket, name);
    cout << endl;

    cout << "Total Multiplications: " << m[0][n - 1] << endl;
}

int main() {
    vector<int> dimensions = {10, 5, 1,  10, 2, 10}; // Example matrix dimensions

    matrixChainOrder(dimensions);

    return 0;
}
