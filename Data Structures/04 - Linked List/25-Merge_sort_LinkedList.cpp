// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

void merge(Node* &start, Node* &end, Node* &mid) {
    vector<int> v = {};
    Node* n1 = start;
    Node* n2 = mid->next;
    while(n1 && n1!=mid->next && n2 && n2!=end->next) {
        if(n1->data < n2->data) {
            v.push_back(n1->data);
            n1 = n1->next;
        }
        else {
            v.push_back(n2->data);
            n2 = n2->next;
        }
    }
    while(n1 && n1!=mid->next) {
        v.push_back(n1->data);
        n1 = n1->next;
    }
    while(n2 && n2!=end->next) {
        v.push_back(n2->data);
        n2 = n2->next;
    }

    Node* node = start;
    for(int i=0; i<v.size(); i++) {
        node->data = v[i];
        node = node->next;
    }
}

void mergeSortFunc(Node* &start, Node* &end) {
    if(start == end) return;
    Node* mid = start;
    Node* fast = start;

    while(fast && fast != end) {
        if(!fast->next) break;
        fast = fast->next;
        if(fast == end) break;
        mid = mid->next;
        if(fast && fast->next) fast = fast->next;
        else break;
    }

    mergeSortFunc(start, mid);
    mergeSortFunc(mid->next, end);
    merge(start, end, mid);
}

Node* mergeSort(Node* head) {
    Node* start = head;
    Node* end = head;
    while(end->next) end = end->next;
    mergeSortFunc(head, end);
    return head;
}

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
  struct Node* a = NULL;
  long n, tmp;
  cin >> n;
  for (int i = 0; i < n; i++) {
      cin >> tmp;
      push(&a, tmp);
  }
  a = mergeSort(a);
  printList(a);
}
