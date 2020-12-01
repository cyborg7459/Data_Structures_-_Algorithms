#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

void create(int A[], int n) {
    int i;
    Node *first, *t, *last;
    first = new Node;
    first->data=NULL;
    last=first;
    for(int i=1; i<n; i++) {
        t = new Node;
        t->data=A[i];
        t->next=NULL;
        last=t;
    }
}

int main() {
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    create(arr, 10);
}
