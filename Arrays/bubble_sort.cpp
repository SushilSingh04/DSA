#include<iostream>
#include<vector>

using namespace std;
//BUBBLE SORT CAN BE MADE ADAPTIVE (USING FLAG)
void bubble_sort(vector<int> &arr){
    int flag;
    int size = arr.size();
    for(int i=0; i<size-1; i++){
        flag = 0;
        for(int j=0; j<size-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                flag=1;
            }
        }
        if(flag==0) break;
    }
}

int main(){
    vector<int> arr = {8,4,7,2,0,6,8};
    bubble_sort(arr);
    for(int val: arr){
        cout << val << " ";
    }
}
