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

void insert(Node *p,int n, int num, int pos) {
    if(pos<0 || pos>num) {
        cout << "Please enter valid position\n";
        return;
    }
    Node *q = NULL;
    if(pos==0) {
        Node *t = new Node;
        t->data = num;
        t->next = first;
        first = t;
    }
    else {
        while(pos-->1)
            p = p->next;
        Node *t = new Node;
        t->data = num;
        t->next = p->next;
        p->next = t;
    }
    display(first);
}

int main() {
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    createLinkedList(arr, 10);
    insert(first, 10, 31, 6);
}
