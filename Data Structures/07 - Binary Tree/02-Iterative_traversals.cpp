// Explanation :-
// ITERATIVE PREORDER : This one is the simplest, we simply need to keep popping off elements from the stack, add it to the vector, and then push the right and left children in the stack (in this order
// only, so that left child is accessed before the right child)
// ITERATIVE POSTORDER : In this, we need 2 stacks. Here the steps are similar to iterative preorder, it's just that we move in the reverse order, i.e. we first push the left child and then the right
// child in the stack. Also, the popped off elements are added in a second stack because the postorder is actually the reverse order of popping and hence the other stack helps in reversing in O(n)
// ITERATIVE INORDER : In this, we keep track of the nodes using a current node, the procedure is to keep going left child for as long as possible. Once we can't go further, then we pop off the topmost
// element, add it to the inorder and then add it's right child to the stack

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
    while(idx < v.size()) {
        node* cur = q.front();
        q.pop();
        int num = v[idx];
        if(num != -1) {
            node* new_node = new node(num);
            cur->left_child = new_node;
            q.push(new_node);
        }
        idx++;
        if(idx >= v.size()) break;
        num = v[idx];
        if(num != -1) {
            node* new_node = new node(num);
            cur->right_child = new_node;
            q.push(new_node);
        }
        idx++;
    }
}

vector<int> Binary_Tree::Iterative_postorder(node *root) {
    stack<node*> st1, st2;
    st1.push(root);
    while(!st1.empty()) {
        node* node = st1.top();
        st1.pop();
        st2.push(node);
        if(node->left_child) st1.push(node->left_child);
        if(node->right_child) st1.push(node->right_child);
    }
    vector<int> ans;
    while(!st2.empty()) {
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return ans;
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
    stack<node*> st;
    vector<int> ans;
    node* cur = root;
    while(true) {
        if(cur) {
            st.push(cur);
            cur = cur->left_child;
        }
        else {
            if(st.empty()) break;
            cur = st.top();
            st.pop();
            ans.push_back(cur->data);
            cur = cur->right_child;
        }
    }
    return ans;
}

int main() {
    vector<int> v = {19, 10, 8, 11, 13, -1, -1};
    Binary_Tree b(v);
    cout << "Preorder : ";
    vector<int> v1 = b.Iterative_preorder(b.root);
    for(auto t : v1) cout << t << " ";
    cout << "\nInorder : ";
    v1 = b.Iterative_inorder(b.root);
    for(auto t : v1) cout << t << " ";
    cout << "\nPostorder : ";
    v1 = b.Iterative_postorder(b.root);
    for(int t : v1) cout << t << " ";
}
