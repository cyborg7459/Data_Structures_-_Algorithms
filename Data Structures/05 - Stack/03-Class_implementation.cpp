#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

class Stack{
private:
    Node *top;
public:
    Stack() {top = NULL;}
    int stackTop();
    void push(int num);
    int pop();
};

void Stack::push(int num) {
    Node *temp = new Node;
    temp->data = num;
    temp->next = top;
    top = temp;
}

int Stack::pop() {
    Node *temp = top;
    top = top->next;
    int data = temp->data;
    delete temp;
    return data;
}

int Stack::stackTop() {
    return top->data;
}

int main() {
    Stack st;
    st.push(10);
    st.push(2);
    st.push(5);
    cout << st.stackTop() << "\n";
}
