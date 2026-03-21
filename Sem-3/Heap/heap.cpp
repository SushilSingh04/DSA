#include<iostream>

using namespace std;

void maxHeapify(int arr[], int size, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    // Check what is largest left or right?
    if(left < size && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < size && arr[right] > arr[largest]){
        largest = right;
    }

    // if parent is not larger than its children
    if(largest != i){
        swap(arr[largest], arr[i]); // swap left or right with parent 
        maxHeapify(arr, size, largest);
    }
}

void buildMaxHeap(int arr[], int size){
    // Required only for elements upto (n/2)-1
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
    for(int i=0; i<size-1; i++){
        buildMaxHeap(arr, prevSize); //to get the largest element at the first. NOTE: Call buildMaxHeap() only on the remaining array.
        swap(arr[0], arr[prevSize-1]);
        prevSize--;
    }

}

void printHeap(int arr[], int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int size=0;
    int* arr = new int(100);
    insert(arr,size,3);
    insert(arr,size,6);
    insert(arr,size,9);
    insert(arr,size,12);
    insert(arr,size,15);
    insert(arr,size,18);
    insert(arr,size,21);
    insert(arr,size,24);
    buildMaxHeap(arr, size);
    deletion(arr, size);
    cout << size << endl;
    // heapSort(arr, size);
    cout << endl;
    printHeap(arr, size);


}