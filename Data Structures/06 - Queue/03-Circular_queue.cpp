#include <bits/stdc++.h>
using namespace std;

class Queue {
private:
    int front;
    int back;
    int size;
    int *arr;
public:
    Queue(int n) {
        front = 0;
        back = 0;
        size = n;
        arr = new int[n];
    };
    bool isEmpty();
    bool isFull();
    void Display();
    void enqueue(int x);
    void dequeue();
};

bool Queue::isEmpty() {
    if(front == back)
        return true;
    return false;
}

bool Queue::isFull() {
    if(back == size-1 && front==0)
        return true;
    if(back==front-1)
        return true;
    return false;
}

void Queue::Display() {
    int idx = front;
    while(idx != back) {
        if(idx == size-1)
            idx=0;
        else
            idx++;
        cout << arr[idx] << " ";
    }
    cout << "\n";
}

void Queue::enqueue(int x) {
    if(isFull()) {
        cout << "Queue is full, can't add elements\n";
        return;
    }
    back++;
    if(back==size)
        back = 0;
    arr[back] = x;
}

void Queue::dequeue() {
    if(isEmpty()) {
        cout << "Queue is empty, can't delete elements\n";
        return;
    }
    front++;
    if(front==size)
        front=0;
}

int main() {
    int n = 3;
    Queue q(n+1);
    q.enqueue(4);
    q.enqueue(4);
    q.enqueue(4);
    q.enqueue(4);
    q.enqueue(4);
    q.Display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(4);
    q.Display();
}
