#include <bits\stdc++.h>
using namespace std;

class Solution {
  public:
        int MOD = 1e9 + 7;
        int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
            // if j and i reach boundary together then must return j first
            if(j == s2.length()){
                return 1;
            }
            
            if(i == s1.length()) return 0;
            
            // dp[i][j] should contain number of ways to form s2[j:] from s1[i:]
            if(dp[i][j] != -1) return dp[i][j];
            
            
            long long ans = 0;
            ans += solve(s1, s2, i + 1, j, dp);
            
            if(s1[i] == s2[j]){
                ans += solve(s1, s2, i + 1, j + 1, dp);
            }
            
            return dp[i][j] = ans % MOD;
    }
    
    int countWays(string &s1, string &s2) {
        // code here
        vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1,-1));
        return solve(s1, s2, 0,0, dp);
    }
};
