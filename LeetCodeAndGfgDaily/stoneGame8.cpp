#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dp;
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        dp.assign(n + 1, -1);
        vector<int> prefixSum(n, 0);
        prefixSum[0] = stones[0];

        for(int i = 1; i < stones.size(); i++){
            prefixSum[i] = prefixSum[i-1] + stones[i];
        }

        dp[n-1] = prefixSum[n-1];

        for(int i = n-2; i >= 1; i--){
            dp[i] = max(dp[i+1], prefixSum[i] - dp[i+1]);
        }


        return dp[1];
    }
};