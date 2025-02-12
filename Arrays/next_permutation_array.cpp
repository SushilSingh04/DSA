#include<bits/stdc++.h>

using namespace std;
void nextPermutation(vector<int>& arr) {
        int first=arr[0];
        int second = arr[1];
        int size=arr.size(), index = -1;
        for(int i=size-2;i>=0;i--){
            if(arr[i] < arr[i+1]){
                index=i;
                break;
            }
        }
        // cout << index << endl;
        if(index==-1){
            reverse(arr.begin(), arr.end());
            return;
        }
        int diff=INT_MAX, index2=-1;
        for(int i=index+1;i<size;i++){
            if(arr[i] - arr[index] > 0 && diff > arr[i]-arr[index]){
                diff = arr[i]-arr[index];
                index2=i;
            }
        }
        swap(arr[index], arr[index2]);
        for(int i=index+1,j=size-1; i<j; i++,j--){
            swap(arr[i], arr[j]);
        }
        
    }