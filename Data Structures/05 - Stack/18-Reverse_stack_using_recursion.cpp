#include<bits/stdc++.h>
using namespace std;

void insert_at_bottom(stack<int> &st, int x) {
    if(st.empty()) st.push(x);
    else {
        int a = st.top();
        st.pop();
        insert_at_bottom(st, x);
        st.push(a);
    }
}

void reverse_stack(stack<int> &st) {
    if(st.empty()) return;
    else {
        int a = st.top();
        st.pop();
        reverse_stack(st);
        insert_at_bottom(st, a);
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
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(9);
    st.push(10);
    print_stack(st);
    reverse_stack(st);
    print_stack(st);
}
