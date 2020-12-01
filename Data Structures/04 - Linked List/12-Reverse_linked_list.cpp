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

void reverseLinkedList(Node *p) {
    Node *q = p;
    p=p->next;
    q->next=NULL;
    while(p!=NULL) {
        Node *temp = p->next;
        p->next=q;
        q=p;
        p=temp;
    }
    first=q;
    display(first);
}

void recursiveReverse(Node *p, Node *q) {
    if(p==NULL) {
        first = q;
        return;
    }
    else {
        recursiveReverse(p->next, p);
        p->next = q;
    }
}

int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    createLinkedList(arr, 10);
    cout << "Original linked list : ";
    display(first);
    cout << "\nAfter reversing : ";
    reverseLinkedList(first);
    cout << "\nAfter reversing again (using recursion) : ";
    recursiveReverse(first, NULL);
    display(first);

}
