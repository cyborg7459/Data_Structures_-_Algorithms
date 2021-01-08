#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class Queue {
private:
    Node *front;
    Node *rear;
public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    };
    bool isEmpty();
    void Display();
    void Enqueue(int x);
    void Dequeue();
};

bool Queue::isEmpty() {
    if(rear == nullptr)
        return true;
    else
        return false;
}

void Queue::Display() {
    Node *temp = front;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void Queue::Enqueue(int x) {
    Node *temp = new Node;
    temp->data = x;
    temp->next = nullptr;
    if(!isEmpty())
        rear->next = temp;
    else if(isEmpty())
        front = temp;
    rear = temp;
    Display();
}

void Queue::Dequeue() {
    if(isEmpty()) {
        cout << "Queue is empty, can't delete element\n";
        return;
    }
    Node *temp = front;
    front = front->next;
    delete temp;
    Display();
}

int main() {
    Queue q;
    for(int i=1; i<=10; i++)
        q.Enqueue(i*i);
    for(int i=1; i<=10; i++)
        q.Dequeue();
}
