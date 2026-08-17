#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, vector<int> &prefixSum){
        if(i >= j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int maxAns = 0;
        for(int k = i; k < j; k++){
            int left = prefixSum[k+1] - prefixSum[i];
            int right = prefixSum[j+1] - prefixSum[k];

            if(left < right){
                maxAns = max(maxAns, left + solve(i, k, prefixSum));
            }
            else if(left > right){
                maxAns = max(maxAns, right + solve(k+1, j, prefixSum));
            }
            else{
                maxAns = max({maxAns, left + solve(i, k, prefixSum), right + solve(k+1, j, prefixSum)});
            }
        }
        return dp[i][j] = maxAns;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefixSum;
        dp.assign(n+1, vector<int>(n+1,-1));

        prefixSum.push_back(0);
        for(int i = 1; i < n; i++){
            prefixSum.push_back(prefixSum[i-1] + stoneValue[i-1]);
        }
        return solve(0, n-1, prefixSum);
    }
};