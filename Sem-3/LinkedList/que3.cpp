// You are using GCC
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int val){
            data = val;
            next = NULL;
        }
};

Node *createFromArray(vector<int> arr, Node* &head){
    Node *last;
    head = new Node(arr[0]);
    last = head;
    
    for(int i=1; i<arr.size(); i++){
        Node *add = new Node(arr[i]);
        last->next = add;
        last = add;
    }
    return head;
}

Node* insert(Node* &head, int val){
    Node* temp = head;
    Node* n = new Node(val);
    while(temp->next != NULL){
        if(temp->next->data > val){
            Node* q = temp->next;
            temp->next = n;
            n->next = q;
            break;
        }
        temp=temp->next;
    }

    return n;
}

void display(Node* head){
    Node* temp = head;
    //cout << "Linked List: ";
    while(temp!= NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}


int main()
{
    Node* head = NULL;
    int n, data;

    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        cin >> data;
        arr.push_back(data);
    }
    createFromArray(arr, head);
    cin >> data;
    insert(head, data);
    display(head);

    return 0;

}