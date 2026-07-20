#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int a, int b){
        if(b > a) swap(a,b);
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int findGCD(vector<int>& nums) {
        int max_ = *max_element(nums.begin(), nums.end());
        int min_ = *min_element(nums.begin(), nums.end());

        return gcd(max_, min_);
    }
};