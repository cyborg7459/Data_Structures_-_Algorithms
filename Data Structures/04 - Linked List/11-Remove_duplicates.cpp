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

void removeDuplicates(Node *p) {
    Node *q = first;
    p=p->next;
    while(p!=NULL) {
        if(p->data==q->data)
            q->next=p->next;
        else
            q = p;
        p=p->next;
    }
    display(first);
}

int main() {
    int arr[10] = {10,10,10,10,20,30,30,40,40,70};
    createLinkedList(arr, 10);
    cout << "Original linked list : ";
    display(first);
    cout << "\nAfter removing duplicates : ";
    removeDuplicates(first);
}
