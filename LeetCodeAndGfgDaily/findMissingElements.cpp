#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int last = nums[0];
        int i = 1;
        for(int val = nums[0]+1; val < nums[nums.size()-1]; val++){
            if(val != nums[i]){
                ans.push_back(val);
            }
            else{
                i++;
            }
        }

        return ans; 
    }
};