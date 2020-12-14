#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

class LinkedList{
private:
    Node *first;
public:
    LinkedList() {first=NULL;}
    LinkedList(int A[], int n);
    ~LinkedList();
    void Display();
    void Insert(int index, int x);
    void Delete(int index);
    int Length();
    void ReversePrint();
};

LinkedList::LinkedList(int A[], int n) {
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(int i=1; i<n; i++) {
        t = new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

LinkedList::~LinkedList() {
    Node *p = first;
    while(first) {
        first = first->next;
        delete p;
        p = first;
    }
    cout << "Destructing the Linked List\n";
}

void LinkedList::ReversePrint() {
    Node *p = first, *q = nullptr;
    q = p;
    p = p->next;
    q->next = NULL;
    while(p!=NULL) {
        Node *temp = p;
        p = p->next;
        temp->next = q;
        q = temp;
    }
    first = q;
    for(Node *t = first; t!=NULL; t=t->next)
        cout << t->data << " ";
    cout << "\n";
}

void LinkedList::Display() {
    Node *p = first;
    while(p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}

void LinkedList::Insert(int index, int x) {
    if(index < 0 || index > Length()) {
        cout << "Please enter valid position\n";
        return;
    }
    Node *q = NULL, *p = first;
    if(index==0) {
        Node *t = new Node;
        t->data = x;
        t->next = first;
        first = t;
    }
    else {
        index--;
        while(index--)
            p = p->next;
        Node *t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

void LinkedList::Delete(int index) {
    Node *p = first;
    if(index < 1 || index > Length())
        cout << "Enter valid index\n";
    if(index==1) {
        first = p->next;
        p = NULL;
    }
    else {
        Node *q;
        index--;
        while(index--) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        delete p;
    }
}

int LinkedList::Length() {
    int counter=0;
    Node *p = first;
    while(p!=NULL) {
        counter++;
        p = p->next;
    }
    return counter;
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9};
    LinkedList A(arr, 9);
    A.ReversePrint();
    // A.Display();
    // A.Insert(3,17);
    // A.Display();
    // A.Delete(8);
    // A.Display();
    // cout << A.Length() << "\n";
}
