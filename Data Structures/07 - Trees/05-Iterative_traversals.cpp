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

bool vis[1000000] = {};
vector<int> Binary_Tree::Iterative_inorder(node *root) {
    memset(vis, false, sizeof vis);
    vector<int> ans = {};
    if(!root) return ans;
    stack<pair<node*, int>> st;
    st.push({root, 0});
    int cnt = 1;
    while(!st.empty()) {
        pair<node*, int> p = st.top();
        st.pop();
        node* cur = p.first;
        int idx = p.second;
        if(vis[idx]) ans.push_back(cur->data);
        else {
            vis[idx] = true;
            if(cur->right_child) st.push({cur->right_child, cnt});
            cnt++;
            st.push(p);
            if(cur->left_child) st.push({cur->left_child, cnt});
            cnt++;
        }
    }
    return ans;
}

int main() {
    vector<int> v = {19, 10, 8, 11, 13, -1, -1};
    Binary_Tree b(v);
    vector<int> v1 = b.Iterative_inorder(b.root);
    for(auto t : v1)
        cout << t << " ";
}
