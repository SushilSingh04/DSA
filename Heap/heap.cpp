#include<iostream>

using namespace std;

void maxHeapify(int arr[], int size, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < size && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < size && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        maxHeapify(arr, size, largest);
    }
}

void buildMaxHeap(int arr[], int size){
    for(int i=size/2-1; i>=0; i--){
        maxHeapify(arr, size, i);
    }
}

void insert(int arr[], int &size, int val){
    arr[size]=val;
    size++;
}

void deletion(int arr[], int &size){
    buildMaxHeap(arr, size);
    size--;
}

void heapSort(int arr[], int size){
    int prevSize = size;
    buildMaxHeap(arr, size);
    for(int i=0; i<prevSize-1; i++){
        swap(arr[0], arr[size-1]);
        size--;
        buildMaxHeap(arr, size);
    }

    for(int i=prevSize-1; i>=0; i--){
        cout << arr[i] << " ";
    }

}

void printHeap(int arr[], int size){
    buildMaxHeap(arr, size);
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    // cin >> n;
    int size=0;
    int arr[] = {100, 1,2,6,78,54};
    // insert(arr,size,3);
    // insert(arr,size,6);
    // insert(arr,size,9);
    // insert(arr,size,12);
    // insert(arr,size,15);
    // insert(arr,size,18);
    // insert(arr,size,21);
    // insert(arr,size,24);
    // deletion(arr, size);
    heapSort(arr, 6);


    // int* arr = new int[n];

    // for(int i=0; i<n; i++){
    //     cin >> arr[i]; 
    // }

    printHeap(arr, size);


}