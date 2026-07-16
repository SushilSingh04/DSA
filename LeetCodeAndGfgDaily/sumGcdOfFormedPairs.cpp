#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gcd(long long a, long long b){
        if(b > a) swap(a, b);

        while(b > 0){
            int temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }
    
    long long gcdSum(vector<int>& nums) {
        vector<int> res;
        long long max_i = 0;

        for(int i = 0; i < nums.size(); i++){
            max_i = max((long long)nums[i], max_i);
            long long val = gcd(max_i, nums[i]);
            res.push_back(val);
        }

        sort(res.begin(), res.end());
        int l = 0, r = res.size()-1;
        long long gcdSum = 0;

        while(l < r){
            gcdSum += gcd(res[l], res[r]);
            l++; r--;
        }
        return gcdSum;
    }
};