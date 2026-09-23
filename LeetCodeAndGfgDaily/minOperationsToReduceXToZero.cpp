#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(),0);
        long long target = sum - x;
        int l = 0, minOps = INT_MAX;
        long long currSum = 0;

        for(int r = 0; r < n; r++){
            currSum += nums[r];
            while(l <= r && currSum > target){
                currSum -= nums[l];
                l++;
            }
            if(currSum == target){
                minOps = min(minOps, n-(r-l+1));
            }
        }

        return minOps == INT_MAX ? -1 : minOps;

        return 0;
    }
};