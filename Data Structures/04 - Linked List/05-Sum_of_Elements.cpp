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

int sumOfElements(Node *p) {
    int sum=0;
    while(p!=NULL) {
        sum+=p->data;
        p=p->next;
    }
    return sum;
}

int recursiveSum(Node *p) {
    static int sum=0;
    if(p==NULL)
        return sum;
    sum+=p->data;
    recursiveSum(p->next);
}

int main() {
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    createLinkedList(arr, 10);
    cout << "Sum of elements : " << sumOfElements(first) << "\n";
    cout << "Recursive sum of elements : " << recursiveSum(first) << "\n";
}
