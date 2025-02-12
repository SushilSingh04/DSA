#include<bits/stdc++.h>

using namespace std;

int maxProduct(vector<int> &arr) {
        int currMin=arr[0], currMax=arr[0], maxProd=arr[0];
        int size = arr.size();
        for(int i=1; i<size; i++){
            int prevMax = currMax, prevMin = currMin;
            currMax = max(arr[i], prevMin*arr[i]);
            currMax = max(currMax, prevMax*arr[i]);
            currMin = min(arr[i], prevMin*arr[i]);
            currMin = min(currMin, prevMax*arr[i]);
            maxProd = max(maxProd, currMin);
            maxProd = max(maxProd, currMax);
        }
        return maxProd;
}