#include<iostream>

using namespace std;

void selection_sort(int arr[], int size){
    int k;
    for(int i=0; i<size-1; i++){
        k=i;
        for(int j=i; j<size-1; j++){
            if(arr[j+1] < arr[k]){
                k=j+1;
            }
        }
        swap(arr[i], arr[k]);
    }
}

int main(){
    int arr[] = {5,8,9,4,4};
    selection_sort(arr, 5);
    for(int i=0; i<5;i++){
        cout << arr[i] <<  " ";
    }
}