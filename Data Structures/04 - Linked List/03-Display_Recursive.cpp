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

void DisplayRecursive(Node *p) {
    if(p!=NULL) {
        cout << p->data << " ";
        DisplayRecursive(p->next);
    }
    else
        return;
}

int main() {
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    createLinkedList(arr, 10);
    DisplayRecursive(first);
}
