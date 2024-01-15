#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

vector<int> longestIncreasingSubsequence(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    vector<int> prev(n, -1);

    int maxLength = 1;
    int end = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }

        if (dp[i] > maxLength) {
            maxLength = dp[i];
            end = i;
        }
    }

    vector<int> lis;
    while (end != -1) {
        lis.push_back(nums[end]);
        end = prev[end];
    }

    reverse(lis.begin(), lis.end());

    return lis;
}

int main() {
    vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    vector<int> lis = longestIncreasingSubsequence(nums);

    cout << "Longest Increasing Subsequence: ";
    for (int num : lis) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

