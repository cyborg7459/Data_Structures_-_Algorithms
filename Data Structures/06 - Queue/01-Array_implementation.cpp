#include <bits/stdc++.h>
using namespace std;

struct Queue {
    int size;
    int *arr;
    int front;
    int rear;
};

bool isEmpty(struct Queue q) {
    if(q.rear == q.front)
        return true;
    return false;
}

bool isFull(struct Queue q) {
    if(q.rear == q.size-1)
        return true;
    return false;
}

void display(struct Queue q) {
    int idx = q.front;
    while(idx!=q.rear) {
        idx++;
        cout << q.arr[idx] << " ";
    }
    cout << "\n";
}

void enqueue(struct Queue &q, int num) {
    if(isFull(q)) {
        cout << "Can't add element as queue is full\n";
        return;
    }
    q.rear++;
    q.arr[q.rear] = num;
    cout << "Added " << num << " to queue\n";
    display(q);
}

void dequeue(struct Queue &q) {
    if(isEmpty(q)) {
        cout << "Queue is empty, can't delete element\n";
        return;
    }
    q.front++;
    cout << "Deleted element from queue\n";
    display(q);
}

int main() {
    struct Queue q;
    int sz;
    cout << "Enter the maximum size of queue : ";
    cin >> sz;
    q.size = sz, q.front = -1, q.rear = -1, q.arr = new int[sz];
    for(int i=1; i<=10; i++) {
        enqueue(q, i*i);
    }
    for(int i=0; i<10; i++) {
        dequeue(q);
    }
}
