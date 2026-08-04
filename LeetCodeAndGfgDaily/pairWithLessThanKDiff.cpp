#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        // code here
        // 1 2 4 10
        //     i  j
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int ans = 0;
        int i = n-2;
        
        for(int j = n-1; j > 0; j--){
            while(i >= 0 && arr[j] - arr[i] < k) i--;
            ans += (j - i - 1);
        }
        
        return ans;
    }
};