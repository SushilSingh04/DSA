#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for(int val: digits){
            freq[val]++;
        }

        int cnt = 0;

        for(int val = 100; val <= 999; val++){
            unordered_map<int, int> mp;
            if(val % 2 == 1) continue;
            bool isPossible = true;
            int tmp = val;

            while(tmp != 0){
                mp[tmp % 10]++;
                tmp /= 10;
            }
            for(auto it: mp){

                if(freq[it.first] < it.second){
                    isPossible = false;
                    break;
                }
            }
            if(isPossible){
                cnt++;
            }
        }

        return cnt;
    }
};