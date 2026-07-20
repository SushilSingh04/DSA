#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIndex(26, -1);
        vector<bool> visited(26, false);
        for(int i = 0; i < s.length(); i++){
            lastIndex[s[i] - 'a'] = i;
        }

        string res = "";

        for(int i = 0; i < s.length(); i++){
            if(visited[s[i] - 'a'] == true) continue;

            while(!res.empty() && res.back() > s[i] && lastIndex[res.back() - 'a'] > i){
                visited[res.back() - 'a'] = false;
                res.pop_back();
            }

            res.push_back(s[i]);    
            visited[s[i] - 'a'] = true;
        }

        return res;
    }
};