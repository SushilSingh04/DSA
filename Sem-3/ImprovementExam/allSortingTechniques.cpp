#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size){
    // buuble sort is both adaptive and stable
    int flag = 0;
    for (int i=0; i<size; i++){
        for(int j=0; j<size-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                flag = 1;
            }
        }
        if(flag == 0) return;
    }
}

void selectionSort(int arr[], int size){
    for(int i=0 ;i<size-1; i++){
        int k=i; // pointer for maintaining the minimum element
        for(int j=i+1; j<size; j++){
            if(arr[k] > arr[j]) k = j;
        }
        swap(arr[k],arr[i]);
    }
}

void insertionSort(int arr[], int size){
    // insertion sort is adaptive
    //minimum time complexity of O(n)
    // maximum time complexity of O(n2)
    int k = 0;
    for(int i=1; i<size; i++){
        k=i;
        while(k > 0){
            if(arr[k] < arr[k-1]){
                swap(arr[k], arr[k-1]);
            }
            k--;
        }
    }
}

void merge(int left[], int right[], int array[], int length){
    int lsize = length/2;
    int rsize = length - lsize;
    int i=0, l=0, r=0;

    while(l < lsize && r < rsize){
        if(left[l] < right[r]){
            array[i++] = left[l++];
        }
        else{
            array[i++] = right[r++];
        }
    }

    while(l < lsize){
        array[i++] = left[l++]; 
    }
    while(r < rsize){
        array[i++] = right[r++];
    }
}

void mergeSort(int array[], int length){
    if(length <= 1) return;
    int mid = length/2;
    int* left = new int(mid);
    int* right = new int(length-mid);
    int i=0, j=0;
    for(; i<length; i++){
        if(i < mid)
        left[i] = array[i];   
        else right[j++] = array[i];
    }
    mergeSort(left, mid);
    mergeSort(right, length-mid);
    merge(left, right, array, length);

}


int main(){
    int arr[] = {5,6,3,8,4,2,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    // bubbleSort(arr, size);
    // selectionSort(arr, size);
    // insertionSort(arr, size);
    mergeSort(arr, size);
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
}
