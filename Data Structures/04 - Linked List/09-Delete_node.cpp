#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

Node *first = new Node;

void createLinkedList(int A[], int n) {
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

void display(Node *p) {
    while(p!=NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

void deleteNode(Node *p, int n, int pos) {
    if(pos<1 || pos>n)
        cout << "Enter valid position\n";
    if(pos==1) {
        first = p->next;
        p = NULL;
    }
    else {
        Node *q;
        pos--;
        while(pos--) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        delete p;
    }
    display(first);
    cout << "\n";
}

int main() {
    int arr[10] = {10,20,30,40,50,60,70,80,90,100};
    createLinkedList(arr, 10);
    deleteNode(first, 10, 7);
}
