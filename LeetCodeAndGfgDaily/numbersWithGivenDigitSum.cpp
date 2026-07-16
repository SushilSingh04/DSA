#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // 'dp' contains count of numbers with 'digitCnt' digits and 'sumVal' sum
    vector<vector<int>> dp;
    int solve(int digitCnt, int sumVal, int n){
        if(digitCnt == n){
            return sumVal == 0 ? 1: 0;
        }
        
        if(dp[digitCnt][sumVal] != -1){
            return dp[digitCnt][sumVal];
        }
        
        int cnt = 0;
        for(int digit= 0; digit <= 9; digit++){
            if(digit == 0 && digitCnt > 0 || digit != 0){
                if(digit <= sumVal){
                    cnt += solve(digitCnt + 1, sumVal - digit, n);
                }
            }
        }
        
        return dp[digitCnt][sumVal] = cnt;
        
    }
    
    int countWays(int n, int sum) {
        // code here
        // [count_digits][sum_digits]
        dp.assign(n+1, vector<int>(sum + 1, -1));
        int cnt = solve(0, sum, n);
        return cnt == 0 ? -1: cnt;   
    }   
};