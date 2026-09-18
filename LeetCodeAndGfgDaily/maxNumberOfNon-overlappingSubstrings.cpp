#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s){
        int n = s.length();
        vector<pair<int, int>> startFinish(26,{-1,-1});

        for(int i = 0; i < n; i++){
            int idx = s[i]-'a';
            int start = startFinish[idx].first;
            int end = startFinish[idx].second;

            if(start == -1) startFinish[idx].first = i;
            startFinish[idx].second = i;
        }

        vector<string> arr;
        vector<bool> validStart(26, true);

        for(int i = 0; i < 26; i++){
            int startIdx = startFinish[i].first, endIdx = startFinish[i].second;
            if(startIdx == -1) continue;

            for(int idx = startIdx; idx <= startFinish[i].second; idx++){
                int j = s[idx]-'a';
                if(startFinish[j].first < startIdx){
                    validStart[i] = false;
                    break;
                }
                startFinish[i].second = max(startFinish[i].second, startFinish[j].second);
            }
        }

        int lastStartIdx = INT_MAX;
        for(int i = n-1; i >= 0; i--){
            if(!validStart[s[i]-'a']) continue;

            int startIdx = startFinish[s[i]-'a'].first, endIdx = startFinish[s[i]-'a'].second;
            if(i == startIdx && lastStartIdx > endIdx){
                arr.push_back(s.substr(i, endIdx - i + 1));
                lastStartIdx = i;
            }
        }

        return arr;
    }
};