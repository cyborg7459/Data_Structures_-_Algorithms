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

// This method is more efficient than the previous one because here a new linked list is not created. Instead the same nodes' links are changed to create the merged linked list, hence increasing the space efficiency
void merge(Node *first, Node *second) {
    Node *last = new Node;
    if(first->data < second->data) {
        mergedfirst = last = first;
        first = first->next;
        last->next = NULL;
    }
    else {
        mergedfirst = last = second;
        second = second->next;
        last->next = NULL;
    }
    while(first!=NULL && second!=NULL) {
        if(first->data < second->data) {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }
    if(first==NULL) last = second;
    else last = first;
    display(mergedfirst);
}

int main() {
    int arr1[5] = {10,30,70,80,100};
    int arr2[5] = {20,40,50,60,90};
    createLinkedList(arr1, 5, first1);
    createLinkedList(arr2, 5, first2);
    merge(first2, first1);
}
