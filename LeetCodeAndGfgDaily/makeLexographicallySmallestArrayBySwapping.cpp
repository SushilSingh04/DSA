#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end(), greater<int>());

        unordered_map<int, int> valToGroup;
        unordered_map<int, vector<int>> groupList;
        int numGroup = 0;

        groupList[numGroup].push_back(sortedNums[0]);
        valToGroup[numGroup] = sortedNums[0];

        // Grouping of values
        for(int i = 1; i < n; i++){
            if(abs(sortedNums[i] - sortedNums[i-1]) > limit) numGroup++;
            groupList[numGroup].push_back(sortedNums[i]);
            valToGroup[sortedNums[i]] = numGroup;
        }

        // Merging the groups
        // replace each value in nums with the minimum (unused val) of the group nums[i] is in.
        for(int i = 0; i < n; i++){
            int group = valToGroup[nums[i]];
            int minValOfGroup = groupList[group].back();
            groupList[group].pop_back();

            nums[i] = minValOfGroup;
        }

        return nums;
    }
};