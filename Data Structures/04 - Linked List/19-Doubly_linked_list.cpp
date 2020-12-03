#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

Node *first = new Node;

void createDoublyLinkedList(int A[], int n) {
    int i;
    Node *t, *p;
    first->data = A[0];
    first->prev = NULL;
    first->next = NULL;
    p = first;
    for(int i=1; i<n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        t->prev = p;
        p->next = t;
        p=t;
    }
}

void display(Node *p) {
    while(p!=NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}

void insertInDoublyLinkedList(int pos, int x) {
    if(pos==0) {
        Node *t = new Node;
        t->data = x;
        first->prev = t;
        t->next = first;
        t->prev = NULL;
        first = t;
        display(first);
        return;
    }
    Node *p = first;
    for(int i=0; i<pos-1; i++)
        p = p->next;
    Node *t = new Node;
    Node *q = p->next;
    t->data = x;
    t->next = p->next;
    t->prev = p;
    q->prev = t;
    p->next = t;
    display(first);
}

void deleteFromDoublyLinkedList(int pos) {
    if(pos==1) {
        Node *t = first;
        first = first->next;
        first->prev = NULL;
        delete t;
        display(first);
        return;
    }
    Node *p = first;
    for(int i=0; i<pos-1; i++) {
        p = p->next;
    }
    Node *a = p->prev;
    Node *b = p->next;
    a->next = b;
    if(b!=NULL)
        b->prev = a;
    delete p;
    display(first);
}

void reverseDoublyLinkedList() {
    Node *p = first, *t = first;
    t = t->next;
    p->prev = p->next;
    p->next = NULL;
    while(t->next != NULL) {
        p = t;
        Node * temp1 = t->next, *temp2 = t->prev;
        t = t->next;
        p->prev = temp1;
        p->next = temp2;
    }
    t->next = p;
    t->prev = NULL;
    first = t;
    display(first);
}

int main() {
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    createDoublyLinkedList(arr, 10);
    display(first);
    insertInDoublyLinkedList(0, 13);
    insertInDoublyLinkedList(7,32);
    deleteFromDoublyLinkedList(1);
    deleteFromDoublyLinkedList(5);
    deleteFromDoublyLinkedList(10);
    reverseDoublyLinkedList();
}
