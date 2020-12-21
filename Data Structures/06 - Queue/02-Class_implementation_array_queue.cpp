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
        front = -1;
        back = -1;
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
    if(back == size-1)
        return true;
    return false;
}

void Queue::Display() {
    int idx = front;
    while(idx != back) {
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
    arr[back] = x;
}

void Queue::dequeue() {
    if(isEmpty()) {
        cout << "Queue is empty, can't delete elements\n";
        return;
    }
    front++;
}

int main() {
    cout << "Enter size of queue : ";
    int n;
    cin >> n;
    Queue q(n);
    for(int i=1; i<=10; i++)
        q.enqueue(i*i);
    q.Display();
    for(int i=0; i<5; i++)
        q.dequeue();
    q.Display();
}
