#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i = 0, cntOne = 0, ansLen = INT_MAX;
        string ans;

        for(int j = 0; j < s.length(); j++){
            if(s[j] == '1') cntOne++;
            while(cntOne == k){
                if(ansLen > j-i+1){
                    ansLen = j-i+1;
                    ans = s.substr(i, j-i+1);
                }
                else if(ansLen == j-i+1 && ans > s.substr(i, j-i+1)){
                    ans = s.substr(i,j-i+1);
                }
                
                if(s[i] == '1') cntOne--;
                i++;
            }
        }

        return ans;
    }
};