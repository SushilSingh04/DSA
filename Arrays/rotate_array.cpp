#include<bits/stdc++.h>

using namespace std;

void rotateArr(vector<int>& arr, int d) {
        int size=arr.size();
        d = d%size;
        vector<int> arr1(size);
        for(int i=0; i<size; i++){
            int eff = (size-d +i)%size;
            arr1[eff] = arr[i];
        }
        for(int i=0; i<size; i++){
            arr[i]=arr1[i];
        }
}