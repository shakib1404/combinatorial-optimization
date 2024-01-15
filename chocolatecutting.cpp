// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

const int sz = 1001;

// Store valid dimensions
bool ok[sz][sz] = {};

// Stores memoization
int dp[sz][sz];

// Utility function to calculate minimum invalid area for
// Chocolate piece having dimension (l, r)
int minInvalidAreaUtil(int l, int b)
{
	if (dp[l][b] == -1) {

		// Check whether current piece is valid or not
		// If it is, then return zero
		// for current dimension
		if (ok[l][b]) {
			return dp[l][b] = 0;
		}

		int ans = l * b;

		// Making all possible horizontal cuts, one by
		// one and calculating the sum of minimum invalid
		// area for both the resulting pieces
		for (int i = 1; i < b; i++) {
			ans = min(ans,
					minInvalidAreaUtil(l, i)
						+ minInvalidAreaUtil(l, b - i));
		}

		// Making all possible vertical cuts, one by one
		// and calculating the sum of minimum invalid area
		// for both the resulting pieces
		for (int i = 1; i < l; i++) {
			ans = min(ans,
					minInvalidAreaUtil(i, b)
						+ minInvalidAreaUtil(l - i, b));
		}

		// Store the computed result
		dp[l][b] = ans;
	}

	return dp[l][b];
}

// Function to calculate minimum invalid area for
// Chocolate piece having dimension (l, r)
void minInvalidArea(int N, int M,
					vector<pair<int, int> >& dimensions)
{
	// Total number of valid dimensions
	int K = dimensions.size();

	// Storing valid dimensions as for every (x, y)
	// both (x, y) and (y, x) are valid
	for (int i = 0; i < K; i++) {
		ok[dimensions[i].first][dimensions[i].second] = 1;
		ok[dimensions[i].second][dimensions[i].first] = 1;
	}

	// Fill dp[][] table with -1, indicating that
	// results are not computed yet
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			dp[i][j] = -1;
		}
	}

	// Stores minimum area
	int minArea = minInvalidAreaUtil(N, M);

	// Print minArea as the output
	cout << minArea << endl;
}

// Driver Code
int main()
{
	// Given N & M
	int N = 10, M = 10;

	// Given valid dimensions
	vector<pair<int, int> > dimensions = { { 3, 5 } };

	// Function Call
	minInvalidArea(N, M, dimensions);

	return 0;
}

