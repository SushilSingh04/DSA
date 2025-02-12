#include<bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices) {
        int maxProfit=0;
        int size = prices.size();
        if(size == 1) return 0;
        int currPrice=-1,nextPrice=-1;
        for(int i=0; i<size-1; i++){
            currPrice=prices[i];
            nextPrice=prices[i+1];
            if(currPrice < nextPrice){
                maxProfit += nextPrice-currPrice;
            }
            
        }
        return maxProfit;
    }