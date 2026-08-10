#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dp;
    bool solve(int n){
        if(n == 0) return false;
        
        if(dp[n] != -1) return dp[n] == 1 ? true: false;

        for(int i = 1; i*i <= n; i++){
            if(!solve(n- i*i)){
                dp[n] = 1;
                return true;
            }
        }
        dp[n] = 0;
        return false;
    }

    bool winnerSquareGame(int n) {
        dp.assign(n + 1, -1);
        return solve(n);
    }
};