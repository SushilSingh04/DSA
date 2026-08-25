#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;
        for(int val: nums) s.insert(val);

        int val = k;
        while(s.find(val) != s.end()){
            val += k;
        }

        return val;
    }
};