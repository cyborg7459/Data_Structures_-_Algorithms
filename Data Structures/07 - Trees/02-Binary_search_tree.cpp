#include <bits/stdc++.h>
using namespace std;

class Tree_node {
public:
    int data;
    Tree_node *left_child;
    Tree_node *right_child;
    Tree_node(int x) {
        data = x;
        left_child = nullptr;
        right_child = nullptr;
    }
};

class BST {
public:
    Tree_node *root;
    BST(std::vector<int> v);
    void inorder(Tree_node *start);
    Tree_node* search(int key, Tree_node *start);
    void insert_in_BST(int key, Tree_node *node);
};

BST::BST(std::vector<int> v) {
    root = new Tree_node(v[0]);
    queue<Tree_node*> q;
    q.push(root);
    int idx = 1;
    while(!q.empty()) {
        Tree_node *node = q.front();
        q.pop();
        int l = v[idx++];
        int r = v[idx++];
        if(l != -1) {
            node->left_child = new Tree_node(l);
            q.push(node->left_child);
        }
        if(r != -1) {
            node->right_child = new Tree_node(r);
            q.push(node->right_child);
        }
    }
}

void BST::inorder(Tree_node *start) {
    Tree_node *node = start;
    if(node == nullptr) return;
    inorder(node->left_child);
    cout << node->data << " ";
    inorder(node->right_child);
}

int steps = 0;
Tree_node* BST::search(int key, Tree_node *start) {
    steps++;
    Tree_node *node = start;
    if(node == nullptr) {
        cout << "Element not found\n";
        return nullptr;
    }
    else {
        if(key == node->data) {
            cout << "Element found\n";
            return node;
        }
        if(key > node->data)
            search(key, node->right_child);
        else
            search(key, node->left_child);
    }
}

void BST::insert_in_BST(int key, Tree_node *node) {
    if(node->data == key) return;
    if(node->data > key) {
        if(node->left_child == nullptr) {
            Tree_node *x = new Tree_node(key);
            node->left_child = x;
            return;
        }
        insert_in_BST(key, node->left_child);
    }
    else {
        if(node->right_child == nullptr) {
            Tree_node *x = new Tree_node(key);
            node->right_child = x;
            return;
        }
        insert_in_BST(key, node->right_child);
    }
}

int main() {
    std::vector<int> v = {40,30,70,-1,35,55,75,-1,-1,45,65,-1,-1,-1,-1,-1,-1};
    BST k(v);
    k.inorder(k.root);
    cout << "\n";
    // for(int i = 44; i<=77; i++) {
    //     cout << i << " : ";
    //     k.search(i, k.root);
    //     cout << "Number of steps : " << steps << "\n";
    //     steps = 0;
    // }
    for(int i=47; i<70; i+=4) {
        k.insert_in_BST(i, k.root);
        cout << "Inserted " << i << "\n";
        k.inorder(k.root);
        cout << "\n";
    }
    return 0;
}
