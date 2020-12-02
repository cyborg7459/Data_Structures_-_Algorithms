#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

Node *first = new Node;
Node *first1 = new Node;

void create(int A[], int n) {
    int i;
    Node *t, *last;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1; i<n; i++) {
        t = new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void createLoopLinkedList() {
    first1->data = 1;
    first1->next=NULL;
    Node *last = first1, *temp;
    for(int i=2; i<11; i++) {
        Node *t = new Node;
        t->data = i;
        t->next = NULL;
        last->next = t;
        if(i==5)
            temp = last;
        last = t;
    }
    last->next = temp;
}

void display(Node *p) {
    while(p!=NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

bool checkForLoop(Node *n) {
    Node *a = n, *b =n;
    while(b!=NULL) {
        a = a->next;
        b = b->next;
        b = b->next;
        if(a==b)
            return true;
    }
    return false;
}

int main() {
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    create(arr, 10);
    createLoopLinkedList();
    if(checkForLoop(first))
        cout << "First linked list has a loop\n";
    else
        cout << "First linked list doesn not have a loop\n";
    if(checkForLoop(first1))
        cout << "Second linked list has a loop\n";
    else
        cout << "Second linked list doesn not have a loop\n";
}
