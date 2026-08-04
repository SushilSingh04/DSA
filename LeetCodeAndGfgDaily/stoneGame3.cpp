#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, vector<int>& stoneValue, vector<int>& dp){
        if(i >= stoneValue.size()) return 0;

        if(dp[i] != -1e9) return dp[i];

        int op1 = stoneValue[i] - solve(i+1, stoneValue, dp);
        int op2 = -1e9, op3 = -1e9;

        if(i+1 < stoneValue.size()){
            op2 = stoneValue[i] + stoneValue[i+1] - solve(i+2, stoneValue, dp);
        }
        if(i+2 < stoneValue.size()){
            op3 = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - solve(i+3, stoneValue, dp);
        }

        int tmp = max(op1, op2);
        return dp[i] = max(tmp, op3);
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, -1e9);
        int score = solve(0, stoneValue, dp);    
        cout << score;
        if(score > 0) return "Alice";
        else if(score < 0) return "Bob";
        return "Tie";
    }
};