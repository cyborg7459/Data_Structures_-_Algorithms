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

int maximumElement(Node *p) {
    int max=p->data;
    while(p!=NULL) {
        if(p->data>max)
            max = p->data;
        p = p->next;
    }
    return max;
}

int recursiveMax(Node *p) {
    static int max=p->data;
    if(p==NULL)
        return max;
    if(p->data>max)
        max = p->data;
    recursiveMax(p->next);
}

int main() {
    int arr[10] = {0,1,2,3,42,5,61,7,8,9};
    createLinkedList(arr, 10);
    cout << "Maximum Element : " << maximumElement(first) << "\n";
    cout << "Maximum Element using recursion : " << maximumElement(first) << "\n";
}
