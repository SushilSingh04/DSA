#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dp;
    int MOD = 1e9 + 7;

    int distinctSubseqII(string s) {
        unordered_map<char, int> mp;
        vector<int> lastRepeated(s.length(), -1);
        dp.assign(s.length()+1, 0);
        dp[0] = 1;

        for(int i = 0; i < s.length(); i++){
            if(mp.find(s[i]) != mp.end()){
                lastRepeated[i] = mp[s[i]];
            }
            mp[s[i]] = i;
        }
        // a a a
        // 1 2 3
        
        for(int i = 1; i < s.length(); i++){
            if(lastRepeated[i] == -1){
                dp[i] = (1LL*2*dp[i-1] + 1) % MOD;
            }
            else{
                int j = lastRepeated[i];
                if(j == 0){
                    dp[i] = (2*11L*dp[i-1]) % MOD;
                }
                else{
                    // Remove the repetitions
                    // dp[j-1] might be greater than dp[i-1] so to keep dp[i] positive add MOD
                    dp[i] = (1LL*2*dp[i-1] - 1LL*dp[j-1] + MOD) % MOD;
                }
            }
        }

        return dp[s.length()-1];
    }
};