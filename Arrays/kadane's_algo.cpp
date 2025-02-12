#include<bits/stdc++.h>

using namespace std;

int maxSubarraySum(vector<int> &arr){
        int size=arr.size();
        int currSum=arr[0], prevMax = arr[0];
        for(int i=1; i<size; i++){
            currSum += arr[i];
            if(currSum < arr[i]) currSum = arr[i];
            if(prevMax < currSum) prevMax = currSum;
        }
        return prevMax;
}