#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> s;
        for(int val: nums) s.insert(val);
        
        int currSum = 0;
        int i = 1;
        while(i < nums.size()){
            if(nums[i] == nums[i-1] + 1){
                currSum += nums[i-1];
            }
            else{
                currSum += nums[i-1];
                break;
            }
            i++;
        }
        if(i == nums.size()) currSum += nums[i-1];
        
        while(s.find(currSum) != s.end()){
            currSum++;
        }
        return currSum;
    }
};