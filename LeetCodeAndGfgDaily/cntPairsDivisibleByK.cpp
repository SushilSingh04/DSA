#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {

        int ans = 0;
        unordered_map<int, int> rem;
        
        for(int i = 0; i < arr.size(); i++){
            int val = arr[i];
            if(val % k == 0 && rem.find(0) != rem.end()){
                ans += rem[0];
            }
            else if(rem.find(k - val % k) != rem.end()){
                ans += rem[k - val % k];
            }
            
            if(rem.find(val % k) == rem.end()) rem[val % k] = 1;
            else rem[val % k]++;
        }
        
        return ans;
    }
};
