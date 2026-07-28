#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        // code here
        vector<vector<int>> ans;
        int i = 0;
        int level = 0;
        while(i < arr.size()){
            int k = 1 << level;
            vector<int> temp;
            while(i < arr.size() && k != 0){
                temp.push_back(arr[i]);
                i++; k--;
            }
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
            level++;
        }
        
        return ans;
    }
};
