#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(vector<int> &stoneBucket){
        stoneBucket[1]--;
        // there were 0 place 1 elements
        if(stoneBucket[1] < 0) return false;

        int totalMoves = 1 + min(stoneBucket[1], stoneBucket[2])*2 + stoneBucket[0];
        if(stoneBucket[1] > stoneBucket[2]){
            stoneBucket[1]--;
            totalMoves++;
        }

        // if equal rem 1 and rem 2 count (excluding the first which is subtracted)
        return totalMoves % 2 == 1 && stoneBucket[1] != stoneBucket[2];
    }

    bool stoneGameIX(vector<int>& stones) {
        vector<int> stoneBucket(3, 0);

        for(int val: stones){
            stoneBucket[val % 3]++;
        }

        vector<int> swapStoneBucket = {stoneBucket[0], stoneBucket[2], stoneBucket[1]};
        // start with either 1 or 2 and check if she wins in either of those cases.
        // sequence goes like 1, 2, 1, 2, 1....
        //               or   2, 1, 2, 1, 2....
        return solve(stoneBucket) || solve(swapStoneBucket);
    }
};