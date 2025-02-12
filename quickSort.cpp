#include<iostream>
#include<climits>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low, j = high;

    do{
        do{i++;} while(arr[i] < pivot);
        do{j--;} while(arr[j] > pivot);

        if(i<j) swap(arr[i], arr[j]);
    }while(i < j);

    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high){
    int j;
    if(low < high){
        j = partition(arr, low, high);
        quickSort(arr, low, j);
        quickSort(arr, j+1, high);
    }
}
int main(){
    int arr[] = {4,5,3,3,7,8,0,9};
    quickSort(arr,0,8);

    for(int val: arr){
        cout << val << " ";
    }
}