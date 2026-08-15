#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xorVal = 0;

        for(int val: nums){
            xorVal ^= val;
        }

        if(xorVal != 0) return n;

        for(int val: nums){
            if(val != 0) return n-1;
        }

        return 0;
    }
};