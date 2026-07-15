#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int bitonic(vector<int> &arr) {
        // code here
        int n = arr.size();
        int length = 1;
        int maxLength = 1;
        int i = 1;
        int inc = 1;
        
        while(i < n){
            if(arr[i-1] < arr[i]){
                inc++;
                length = inc;
            }
            else if(arr[i-1] > arr[i]){
                inc = 1;
                length++;
            }
            else{
                inc++;
                length++;
            }
            maxLength = max(maxLength, length);
            i++;
        }
        return maxLength;
    }
};