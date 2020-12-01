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

int countNodes(Node *p) {
    int counter=0;
    while(p!=NULL) {
        counter++;
        p = p->next;
    }
    return counter;
}

int recursiveCountNodes(Node *p) {
    static int counter=0;
    if(p==NULL)
        return counter;
    counter++;
    recursiveCountNodes(p->next);
}

int main() {
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    createLinkedList(arr, 10);
    cout << "Number of nodes using simple function : " << countNodes(first) << "\n";
    cout << "Number of nodes using recursive function : " << recursiveCountNodes(first) << "\n";
}
