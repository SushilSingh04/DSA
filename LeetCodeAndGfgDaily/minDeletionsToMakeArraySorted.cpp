#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minDeletions(vector<int>& arr) {
        // code here
        // this is only to denote the longest increasing subsequence
        vector<int> lis;
        
        for(int i = 0; i < arr.size(); i++){
            if(lis.empty() || arr[i] > lis.back()){
                lis.push_back(arr[i]);
            }
            else{
                auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
                // replace lower bound with current element
                *it = arr[i];
            }
        }
        
        return arr.size() - lis.size();
    }
};