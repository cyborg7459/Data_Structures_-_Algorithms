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

void sortedInsert(Node *p, int n, int num) {
    if(num<first->data) {
        Node *t = new Node;
        t->data = num;
        t->next = first;
        first = t;
    }
    else {
        Node *q, *p = first;
        while(true) {
            q = p;
            p = p->next;
            if(p==NULL || p->data>num)
                break;
        }
        Node *t = new Node;
        t->data = num;
        t->next = p;
        q->next = t;
    }
    display(first);
}

int main() {
    int arr[10] = {10,20,30,40,50,60,70,80,90,100};
    createLinkedList(arr, 10);
    sortedInsert(first, 10, 120);
}
