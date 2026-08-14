#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i = 0, maxLength = 0;
        unordered_map<char, int> mp;

        for(int j = 0; j < s.length(); j++){
            mp[s[j]]++;
            while(mp[s[j]] > 2){
                mp[s[i]]--;
                i++;
            }
            maxLength = max(maxLength, j -i+1);
        }

        return maxLength;
    }
};