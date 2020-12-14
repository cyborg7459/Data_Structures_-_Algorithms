#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

struct Stack {
    struct Node *top;
};

bool isEmpty(struct Stack st) {
    return st.top==nullptr;
}

int top(struct Stack &st) {
    return st.top->data;
}

int push(struct Stack &st, int num) {
    Node *temp = new Node;
    if(temp == nullptr) {
        cout << "Stack overflow\n";
        return -1;
    }
    temp->data = num;
    temp->next = st.top;
    st.top = temp;
    return st.top->data;
}

int pop(struct Stack &st) {
    if(isEmpty(st)) {
        cout << "Stack is empty, nothing to pop\n";
        return -1;
    }
    Node *temp = st.top;
    st.top = st.top->next;
    int data = temp->data;
    delete temp;
    return data;
}

int peek(struct Stack &st, int idx) {
    Node *temp = st.top;
    idx--;
    while(idx--) {
        temp = temp->next;
        if(temp==nullptr) {
            cout << "Out of range\n";
            return -1;
        }
    }
    return temp->data;
}

int main() {
    struct Stack st;
    st.top = nullptr;
    cout << "Pushed " << push(st, 4) << " onto the stack\n";
    cout << "Pushed " << push(st, 7) << " onto the stack\n";
    cout << peek(st, 1) << "\n";
    cout << peek(st, 2) << "\n";
    cout << "Popped " << pop(st) << " from the stack\n";
    cout << "Popped " << pop(st) << " from the stack\n";
    cout << "Popped " << pop(st) << " from the stack\n";
}
