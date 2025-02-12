#include<iostream>
#include<vector>
using namespace std;

//INSERTION SORT IS ADAPTIVE BY NATURE
// Minimum time - O(n)
// Maximum time - O(n2)
void insertion_sort(vector<int> &arr){
    int size = arr.size(), k;
    for(int i=1; i<size; i++){
        k=i;
        for(int j=i-1; j>=0; j--){
            if(arr[k] < arr[j]){
                swap(arr[k], arr[j]);
                k--;
            }
            else{
                break;
            }
        }
    }
}

int main(){
    vector<int> arr = {4,6,7,2,0,1,8,2};
    insertion_sort(arr);
    for(int val: arr){
        cout << val << " ";
    }
}