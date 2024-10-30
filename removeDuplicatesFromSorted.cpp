#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

int count(Node* head){
    if(head == NULL) return 0;
    int count = 1;
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next; 
        count++;
    }
    return count;
}

void insert(Node *&head, int val, int pos)
{
    if(pos<0 || pos > count(head)) return;
    Node *t = new Node(val);
    if (pos == 0)
    {
        t->next = head;
        head = t;
    }
    else
    {
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        if (temp != NULL)
        {
            t->next = temp->next;
            temp->next = t;
        }
    }
}

void display(Node *head)
{
    Node *temp = head;
    // cout << "Linked List: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void removeDuplicate(Node* head){
    Node* p = head;
    Node* q = p->next;
    while(q != NULL){
        if(p->data != q->data){
            p = q;
            q = q->next;
        }
        else{
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

int main()
{
    Node *head = NULL;
    insert(head, 1, 0);
    insert(head, 2, 1);
    insert(head, 2, 2);
    insert(head, 2, 3);
    insert(head, 2, 4);
    insert(head, 2, 5);
    display(head);
    removeDuplicate(head);
    display(head);

}