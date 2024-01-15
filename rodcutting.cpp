#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProfit(vector<int>& prices, int n) {
    vector<int> dp(n+1, 0);
    vector<int> cuts(n+1, 0);

    for (int i = 1; i <= n; i++) {
        int max_price = INT_MIN;
        for (int j = 1; j <= i; j++) {
            if (prices[j-1] + dp[i-j] > max_price) {
                max_price = prices[j-1] + dp[i-j];
                cuts[i] = j;
            }
        }
        dp[i] = max_price;
    }

    int remaining_length = n;
    while (remaining_length > 0) {
        cout << "Cut at point " << cuts[remaining_length] << endl;
        remaining_length -= cuts[remaining_length];
    }
    return dp[n];
}

int main() {
    vector<int> prices = {1, 5, 8, 9, 10, 12, 17};
    int n = 7; // Length of the rod

    cout << "details: " << endl;
   cout<< maxProfit(prices, n);

    return 0;
}
