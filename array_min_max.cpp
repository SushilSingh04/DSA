#include<iostream>
#include<climits>
using namespace std;

int get_min(int arr[], int size){
    int min = INT_MAX;
    for(int i = 0; i < size ; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;

}
int main(){
    int arr[5] = {4,6,8,3,2};
    cout << get_min(arr, 5);

}

