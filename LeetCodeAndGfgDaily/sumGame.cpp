#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int leftQ = 0, rightQ = 0;
        int leftSum = 0, rightSum = 0;

        for(int i = 0; i < n/2; i++){
            if(num[i] == '?') leftQ++;
            else leftSum += (num[i] - '0');
        }

        for(int i = n/2; i < n; i++){
            if(num[i] == '?') rightQ++;
            else rightSum += (num[i] - '0');
        }
        cout << rightSum - leftSum << " " << (leftQ - rightQ)*9/2;
        if(leftQ + rightQ != 1 && (leftQ + rightQ) % 2 == 0 && rightSum - leftSum == (leftQ - rightQ)*9/2) return false;
        return true;


    }
};