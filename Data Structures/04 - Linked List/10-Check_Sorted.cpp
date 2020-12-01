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

bool isSorted(Node *p) {
    int max = p->data;
    while(p!=NULL) {
        if(p->data < max)
            return false;
        else
            max = p->data;
        p = p->next;
    }
    return true;
}

bool recursiveIsSorted(Node *p) {
    static int max = p->data;
    if(p==NULL)
        return true;
    if(p->data < max)
        return false;
    max = p->data;
    recursiveIsSorted(p->next);
}

int main() {
    // int arr[10] = {10,20,30,40,50,60,70,80,90,100};
    // int arr[10] = {10,10,10,10,10,10,10,10,10,10};
    int arr[10] = {10,20,40,40,63,5,708,20,90,2};
    createLinkedList(arr, 10);
    if(isSorted(first))
        cout << "Given linked list is sorted\n";
    else
        cout << "Unsorted\n";
    if(recursiveIsSorted(first))
        cout << "Given linked list is sorted (recursion check)\n";
    else
        cout << "Unsorted (recursion check)\n";
}
