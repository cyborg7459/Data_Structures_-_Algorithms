#include <bits/stdc++.h>
using namespace std;

class Tree_node {
public:
    int data;
    Tree_node *left_child;
    Tree_node *right_child;
    Tree_node() {
        left_child = nullptr;
        right_child = nullptr;
    }
    Tree_node(int t) {
        data = t;
        left_child = nullptr;
        right_child = nullptr;
    }
};

class BST {
public:
    Tree_node *root;
    BST(std::vector<int> v, int n);
    void preorder(Tree_node *node);
    void inorder(Tree_node *node);
    void postorder(Tree_node *node);
};

BST::BST(std::vector<int> v, int n) {
    root = new Tree_node(v[0]);
    Tree_node *node = root;
    stack<Tree_node*> st;
    int i = 1;
    while(i < n) {
        int t = v[i];
        if(t < node->data) {
            Tree_node *temp = new Tree_node(t);
            i++;
            node->left_child = temp;
            st.push(node);
            node = temp;
        }
        else {
            if(t>node->data && !st.empty() && t < st.top()->data) {
                Tree_node *temp = new Tree_node(t);
                i++;
                node->right_child = temp;
                node = temp;
            }
            else {
                node = st.top();
                st.pop();
            }
        }
    }
}

void BST::inorder(Tree_node *node) {
    if(node == nullptr)
        return;
    else {
        inorder(node->left_child);
        cout << node->data << " ";
        inorder(node->right_child);
    }
}

void BST::preorder(Tree_node *node) {
    if(node == nullptr) return;
    else {
        cout << node->data << " ";
        preorder(node->left_child);
        preorder(node->right_child);
    }
}

void BST::postorder(Tree_node *node) {
    if(node == nullptr)
        return;
    else {
        postorder(node->left_child);
        postorder(node->right_child);
        cout << node->data << " ";
    }
}


int main() {
    std::vector<int> v = {30,20,10,15,25,40,50,45};
    BST k(v, v.size());
    k.preorder(k.root);
}
