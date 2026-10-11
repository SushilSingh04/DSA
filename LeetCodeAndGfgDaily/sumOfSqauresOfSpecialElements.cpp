#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sumSq = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums.size() % (i+1) == 0){
                sumSq += nums[i]*nums[i];
            }
        }
        return sumSq;
    }
};