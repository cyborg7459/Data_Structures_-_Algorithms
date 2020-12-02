#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

Node *first1 = new Node;
Node *first2 = new Node;

void createLinkedList(int A[], int n, Node *p) {
    int i;
    Node *t, *last;
    p->data=A[0];
    p->next=NULL;
    last=p;
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

void concatenate(Node *n1, Node *n2) {
    Node *t = n1;
    while(t->next!=NULL)
        t=t->next;
    t->next=n2;
    display(n1);
}

int main() {
    int arr1[10] = {0,1,2,3,4,5,6,7,8,9};
    int arr2[5] = {10,20,30,40,50};
    createLinkedList(arr1, 10, first1);
    createLinkedList(arr2, 5, first2);
    concatenate(first2, first1);
}
