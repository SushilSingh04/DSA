#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        long long ans = 0;
        int n = nums.size();

        for(int i = 0; i < nums.size(); i++){
            int ele = abs(nums[i]);
            // cout << pq.size() << " size ";
            if(pq.size() < (n+1)/2){
                pq.push(ele);
                // cout << ele << " add ";
            }
            else if(pq.size() == (n+1)/2){
                if(pq.top() < ele){
                    int t = pq.top(); pq.pop();
                    // cout << t << " minus ";
                    ans -= 1LL*t*t;
                    pq.push(ele);
                    // cout << ele << " add " ;
                }
                else{
                    ans -= 1LL*ele*ele;
                }
            }
        }
        // cout << ans << " ans ";
        while(!pq.empty()){
            int t = pq.top();
            ans += t*t; 
            // cout << t << " plus ";
            pq.pop();
        }

        return ans;
    }
    
};