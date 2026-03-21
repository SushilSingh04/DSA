// Key use cyclic sort to put elements at their desired position (nums[i]-1)
// After rearranging the first element to be out of place is the answer

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n; i++){
            while(nums[i] >= 1 && nums[i] <= n && nums[nums[i]-1] != nums[i]){
                int correct_idx = nums[i]-1;
                swap(nums[i], nums[correct_idx]);
            }
        }
        for(int i = 0; i<n; i++){
            if(nums[i] != i+1) return i+1;
        }
        return n+1;
    }
};