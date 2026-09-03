#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int smallestOdd = INT_MAX, smallestEven = INT_MAX;

        for(int i = 0; i < n; i++){
            if(nums1[i] % 2 == 1 && smallestOdd > nums1[i]) smallestOdd = nums1[i];
            else if(nums1[i] % 2 == 0 && smallestEven > nums1[i]) smallestEven = nums1[i];
        }

        if(smallestOdd == INT_MAX) return true;
        else if(smallestEven == INT_MAX) return true;
        else if(smallestEven > smallestOdd) return true;
        else return false;

    }
};