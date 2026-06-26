#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    void solve(int n, int length, int lastDigit, int num, vector<int> &res){
        if(length == n){
            res.push_back(num);
            return;
        }
        
        for(int i = lastDigit + 1; i <= 9; i++){
            solve(n, length + 1, i, num*10 + i, res);
        }
    }
    
    vector<int> increasingNumbers(int n) {
        // code here
        if(n >= 10){
            return vector<int>();
        }
        
        if(n == 1){
            return {0,1,2,3,4,5,6,7,8,9};
        }
        
        vector<int> res;
        
        for(int start = 1; start <= 9; start++){
            solve(n, 1, start, start, res);
        }
        
        return res;
    }
};