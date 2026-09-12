#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Node{
        vector<int> idxs;
        long long score = -1;
    };
    vector<vector<Node>> dp;
    vector<int> nextIdx;

    Node solve(int i, int k, vector<vector<int>> &intervals){
        int n = intervals.size();
        if(i == n || k >= 4)  return Node();
        if(dp[i][k].score != -1){
            return dp[i][k];
        }

        Node notTake = solve(i+1, k, intervals);

        int j = nextIdx[i];
        Node tmp = solve(j, k+1, intervals);
        Node take = Node();

        take.score = tmp.score + intervals[i][2];
        take.idxs = tmp.idxs;
        take.idxs.push_back(intervals[i][3]);
        sort(take.idxs.begin(), take.idxs.end());

        Node res;
        if(notTake.score > take.score){
            res = notTake;
        }
        else if(notTake.score < take.score){
            res = take;
        }
        else{
            res = (notTake.idxs > take.idxs)? take: notTake;
        }
        
        return dp[i][k] = res;
    }
    
    int findNextIndex(vector<vector<int>> &intervals, int r){
        int low = 0, high = intervals.size()-1, res = intervals.size();
        while(low <= high){
            int mid = low + (high - low)/2;
            if(intervals[mid][0] > r){
                res = mid;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }

        return res;
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for(int i = 0; i < n; i++){
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end());

        nextIdx.resize(n);
        dp.assign(n+1, vector<Node>(5));

        for(int i = 0; i < n; i++){
            nextIdx[i] = findNextIndex(intervals, intervals[i][1]);
        }

        Node res = solve(0, 0, intervals);
        return res.idxs;
    }
};