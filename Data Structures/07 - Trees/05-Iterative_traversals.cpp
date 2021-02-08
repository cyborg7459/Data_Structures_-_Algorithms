#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left_child;
    node* right_child;
    node(int x) {
        data = x;
        left_child = nullptr;
        right_child = nullptr;
    }
};

class Binary_Tree {
public:
    node* root;
    Binary_Tree(vector<int> v);
    vector<int> Iterative_postorder(node *root);
    vector<int> Iterative_inorder(node *root);
    vector<int> Iterative_preorder(node *root);
};

Binary_Tree::Binary_Tree(vector<int> v) {
    root = new node(v[0]);
    queue<node*> q;
    q.push(root);
    int idx = 1;
    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        if(v[idx] != -1) {
            node* lchild = new node(v[idx++]);
            temp->left_child = lchild;
            q.push(lchild);
        }
        if(v[idx] != -1) {
            node* rchild = new node(v[idx++]);
            temp->right_child = rchild;
            q.push(rchild);
        }
    }
}

vector<int> Binary_Tree::Iterative_preorder(node *root) {
    stack<node*> st;
    vector<int> v;
    st.push(root);
    while(!st.empty()) {
        node *cur = st.top();
        st.pop();
        v.push_back(cur->data);
        if(cur->right_child) st.push(cur->right_child);
        if(cur->left_child) st.push(cur->left_child);
    }
    return v;
}

vector<int> Binary_Tree::Iterative_inorder(node *root) {
    stack<node*> st1, st2;
    vector<int> v;
    st1.push(root);
    while(!st1.empty()) {
        node *cur = st1.top();
        st1.pop();
        if(cur->left_child == nullptr && cur->right_child == nullptr)
            v.push_back(cur->data);
        else if(!st2.empty() && st2.top()==cur) {
            v.push_back(cur->data);
            st2.pop();
            if(cur->right_child)
                st1.push(cur->right_child);
        }
        else {
            if(cur->left_child) {
                st1.push(cur);
                st2.push(cur);
                st1.push(cur->left_child);
            }
            else  if(cur->right_child) {
                v.push_back(cur->data);
                st1.push(cur->right_child);
            }
        }
    }
    return v;
}

int main() {
    vector<int> v = {19, 10, 8, 11, 13, -1, -1};
    Binary_Tree b(v);
    vector<int> v1 = b.Iterative_inorder(b.root);
    for(auto t : v1)
        cout << t << " ";
}
