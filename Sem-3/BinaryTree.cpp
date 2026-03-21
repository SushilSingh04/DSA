#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* left;

    Node(int val){
        data = val;
    }
};

Node* insertLevelOrder(int arr[], int start, int size){
    Node* temp = NULL;
    if(start < size){
        temp = new Node(arr[start]);
        temp->left = insertLevelOrder(arr, 2*start+1,size);
        temp->right = insertLevelOrder(arr, 2*start+2,size);
    }
    return temp;
}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// Checking for complete binary tree: similar to level order traversal.
// Maintain a queue and a flag. flag determines if a node has been encountered that was null,
// if yes we return false else return true

int main(){
    int arr[] = {5,3,7,2,4};
    Node* root = NULL;
    root = insertLevelOrder(arr,0,5);
    inOrder(root);

}
