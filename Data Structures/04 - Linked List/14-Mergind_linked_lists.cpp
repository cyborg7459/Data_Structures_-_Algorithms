#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

Node *first1 = new Node;
Node *first2 = new Node;
Node *mergedfirst = new Node;

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

void merge(Node *n1, Node *n2) {
    Node *a = n1;
    Node *b = n2;
    if(a->data < b->data) {
        mergedfirst->data = a->data;
        a = a->next;
    }
    else {
        mergedfirst->data = b->data;
        b = b->next;
    }
    Node *t = mergedfirst;
    while(a!=NULL && b!=NULL) {
        if(a->data < b->data) {
            t->next = a;
            t = t->next;
            a = a->next;
        }
        else {
            t->next = b;
            t = t->next;
            b = b->next;
        }
    }
    if(a==NULL) {
        while(b!=NULL) {
            t->next = b;
            t = t->next;
            b = b->next;
        }
    }
    else {
        while(a!=NULL) {
            t->next = a;
            t = t->next;
            a = a->next;
        }
    }
    display(mergedfirst);
}

int main() {
    int arr1[5] = {10,30,70,80,100};
    int arr2[5] = {20,40,50,60,90};
    createLinkedList(arr1, 5, first1);
    createLinkedList(arr2, 5, first2);
    merge(first2, first1);
}
