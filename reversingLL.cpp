#include <iostream>
#include <vector>
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

int count(Node *head)
{
    if (head == NULL)
        return 0;
    int count = 1;
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void insert(Node *&head, int val, int pos)
{
    if (pos < 0 || pos > count(head))
        return;
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

void reverse(Node *&head)
{
    Node *r = NULL;
    Node *q = NULL;
    Node *p = head;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;

        q->next = r;
    }

    head = q;
}

Node* recursiveRev(Node* &p){
    Node* head = NULL;
    if(p->next == NULL){
        head = p;
        return head;
    }
    head = recursiveRev(p->next);
    Node* q = p->next;
    q->next = p;
    p->next = NULL;
    return head; 

}

void recursiveReverse(Node* &head){
    Node* p = head;

    head = recursiveRev(p);

}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;
    insert(head, 6, 0);
    insert(head, 3, 1);
    insert(head, 7, 2);
    insert(head, 1, 3);
    insert(head, 0, 4);
    display(head);
    cout << endl;
    recursiveReverse(head);
    display(head);
}
