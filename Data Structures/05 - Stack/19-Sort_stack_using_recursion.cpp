#include <bits/stdc++.h>
using namespace std;

void insert_into_stack(stack<int> &st, int x) {
    if(st.empty() || st.top() < x) {
        st.push(x);
        return;
    }
    else {
        int a = st.top();
        st.pop();
        insert_into_stack(st, x);
        st.push(a);
    }
}

void traverse_stack(stack<int> &st) {
    if(st.empty()) return;
    else {
        int x = st.top();
        st.pop();
        traverse_stack(st);
        insert_into_stack(st, x);
    }
}

void print_stack(stack <int> st) {
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";
}

int main() {
    stack<int> st;
    st.push(4);
    st.push(8);
    st.push(1);
    st.push(3);
    st.push(10);
    st.push(7);
    st.push(2);
    st.push(9);
    st.push(6);
    st.push(5);
    print_stack(st);
    traverse_stack(st);
    print_stack(st);
}
