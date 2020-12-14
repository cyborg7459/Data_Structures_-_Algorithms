#include <bits/stdc++.h>
using namespace std;

struct Stack {
    int size;
    int top;
    int *arr;
};

bool isEmpty(struct Stack st) {
    return st.top == -1;
}

bool isFull(struct Stack st) {
    return st.top == st.size-1;
}

int top(struct Stack st) {
    return st.arr[st.top];
}

int push(struct Stack &st, int num) {
    if(isFull(st)) {
        cout << "The stack is full, can't push\n";
        return -1;
    }
    st.top++;
    st.arr[st.top] = num;
    return num;
}

int pop(struct Stack &st) {
    if(isEmpty(st)) {
        cout << "Stack is empty. Nothing to pop\n";
        return -1;
    }
    int num = top(st);
    st.top--;
    return num;
}

int main() {
    struct Stack st;
    int sz;
    cout << "Enter maximum size of stack : ";
    cin >> sz;
    st.size = sz, st.top = -1, st.arr = new int[sz];
    cout << "Pushed " << push(st, 3) << " onto stack\n";
    cout << "Pushed " << push(st, 4) << " onto stack\n";
    cout << "Pulled " <<  pop(st) << " from stack\n";
    cout << "Pulled " <<  pop(st) << " from stack\n";
    cout << "Pulled " <<  pop(st) << " from stack\n";
    cout << "Pushed " << push(st, 4) << " onto stack\n";
}
