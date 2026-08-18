#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int val1 = nums[0], val2 = nums[nums.size()-1];
        int cntVal1 = 0, cntVal2 = 0;
        int max_ele = INT_MIN;

        if(k == 1){
            map<int, int, greater<int>> mp;
            for(int val: nums) mp[val]++;
            for(auto it: mp){
                if(it.second == 1) return it.first;
            }
            return -1;
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == val1) cntVal1++;
            else if(nums[i] == val2) cntVal2++;
            if(max_ele < nums[i]) max_ele = nums[i];
        }
        
        if(nums.size() == k) return max_ele;
        else if(cntVal1 == 1 && cntVal2 == 1) return val1 > val2 ? val1 : val2;

        return cntVal1 == 1 ? val1 : (cntVal2 == 1 ? val2 : -1);
    }
};