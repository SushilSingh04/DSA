#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        int case1 = nums[i] + min(solve(i+2, j, nums, dp), solve(i+1, j-1, nums, dp));
        int case2 = nums[j] + min(solve(i, j-2, nums, dp), solve(i+1, j-1, nums, dp));

        return dp[i][j] = max(case1, case2);
    }
    
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int totalScore = accumulate(nums.begin(), nums.end(),0);

        int player1Score = solve(0, n-1, nums, dp);
        if(player1Score >= totalScore - player1Score) return true;
        return false;
    }
};