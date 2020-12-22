#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;
};

class DEQueue {
private:
    Node *front;
    Node *rear;
public:
    DEQueue() {
        front = new Node;
        front->prev = nullptr;
        rear = front;
        rear->next = nullptr;
    };
    bool isEmpty();
    void Display();
    void Insert_Back(int num);
    void Insert_Front(int num);
    void Delete_Front();
    void Delete_Back();
};

bool DEQueue::isEmpty() {
    if(front == rear)
        return true;
    return false;
}

void DEQueue::Display() {
    Node *temp = front->next;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void DEQueue::Insert_Back(int num) {
    Node *temp = new Node;
    temp->data = num;
    temp->prev = rear;
    temp->next = nullptr;
    rear->next = temp;
    rear = temp;
}

void DEQueue::Insert_Front(int num) {
    Node *temp = new Node;
    temp->prev = nullptr;
    temp->next = front;
    front->prev = temp;
    front->data = num;
    front = temp;
}

void DEQueue::Delete_Back() {
    Node *temp = rear;
    rear = rear->prev;
    rear->next = nullptr;
    delete temp;
}

void DEQueue::Delete_Front() {
    Node *temp = front;
    front = front->next;
    front->prev = nullptr;
    delete temp;
}

int main() {
    DEQueue dq;
    dq.Insert_Back(10);
    dq.Insert_Back(12);
    dq.Display();
    dq.Insert_Front(5);
    dq.Insert_Front(37);
    dq.Display();
    dq.Delete_Back();
    dq.Display();
    dq.Delete_Front();
    dq.Display();
}
