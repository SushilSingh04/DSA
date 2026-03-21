#include<bits/stdc++.h>
using namespace std;


int maximumProfit(vector<int> &prices) {
        int size = prices.size();
        if(size == 1) return 0;
        int buyAt=0;
        int currPrice=-1,maxDiff=0;
        for(int i=1; i<size; i++){
            currPrice = prices[i];
            if(maxDiff < currPrice-prices[buyAt])
                maxDiff = currPrice-prices[buyAt];
            if(prices[buyAt]-currPrice>0){
                buyAt = i;
            }
        }

        if(maxDiff<0) return 0;
        return maxDiff;
    }