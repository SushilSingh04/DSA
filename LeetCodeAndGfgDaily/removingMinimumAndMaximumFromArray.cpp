#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIdx = 0, maxIdx = 0, n = nums.size();
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[maxIdx]){
                maxIdx = i;
            }
            if(nums[i] < nums[minIdx]){
                minIdx = i;
            }
        }
        // 4 cases
        // remove both from the left end (max of both ensures both are removed), 
        // both from the right end (min of both ensures both are removed), 
        // from both ends with maxIdx closer to right and minIdx closer to left end, 
        // from both ends with minIdx closer to right and maxidx closer to right end.
        return min({max(minIdx, maxIdx) + 1, n - min(minIdx, maxIdx), n - maxIdx + minIdx + 1, n - minIdx + maxIdx + 1});
    }
};