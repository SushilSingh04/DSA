#include <bits/stdc++.h>
using namespace std;

int getMinDiff(vector<int> &arr, int k) {
        vector<int> arr1 = arr;
        int size = arr1.size(), maxH=-1, minH=-1;
        if(size==1) return 0;
        sort(arr1.begin(), arr1.end());
        int res = arr1[size-1]-arr1[0];
        for(int i=1; i<size; i++){
            if(arr1[i]-k < 0) continue;
            
            minH = min(arr1[0]+k, arr1[i]-k);
            maxH = max(arr1[size-1]-k,arr1[i-1]+k);
            
            res = min(res, maxH-minH);
        }
        return res;
    }