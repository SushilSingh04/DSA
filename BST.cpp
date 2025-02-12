#include<iostream>
#include<queue>

using namespace std;

struct Node{
    Node* left;
    Node* right;
    int data;

    Node(int val){
        left = NULL;
        right = NULL;
        data = val;
    }
};

Node* insert(Node* root, int val){
    if(root == NULL) return new Node(val);
    else if(val > root->data){
        root->right = insert(root->right, val);
    }
    else{
        root->left = insert(root->left, val);
    }

    return root;
}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int heightOfTree(Node* root){
    if(root == NULL){
        return 0;
    }
    return 1+max(heightOfTree(root->left), heightOfTree(root->right)) ;
}

Node* searchBST(Node* root, int val){
    while(root != NULL && root->data != val){
        root = root->data > val ? root->left : root->right;
    }

    return root;
}

void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        root = q.front();
        cout << q.front()->data << " ";
        q.pop();
        if(root->left != NULL) q.push(root->left);
        if(root->right != NULL) q.push(root->right);
    }
}

void deletion(Node* root){

}

int main(){
    Node* root = new Node(3);
    insert(root, 12);
    insert(root, 9);
    insert(root, 1);
    insert(root, 0);
    insert(root, 8);
    insert(root, 5);
    insert(root, 4);
    insert(root, 8);
    insert(root, 234);
    insert(root, 56);
    insert(root, 23);



    levelOrder(root);
    cout << endl;
    cout << heightOfTree(root);
}