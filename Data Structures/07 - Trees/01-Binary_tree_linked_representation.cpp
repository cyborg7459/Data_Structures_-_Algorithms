#include <bits/stdc++.h>
using namespace std;

class Binary_Tree_Node {
public:
    Binary_Tree_Node *left_child;
    Binary_Tree_Node *right_child;
    int data;
    Binary_Tree_Node(int x) {
        left_child = nullptr;
        right_child = nullptr;
        data = x;
    }
};

class Binary_Tree {
public:
    Binary_Tree_Node *root;
    Binary_Tree(int arr[]);
    void preorder(Binary_Tree_Node *start);
    void inorder(Binary_Tree_Node *start);
    void postorder(Binary_Tree_Node *start);
    void levelorder(Binary_Tree_Node *start);
    int height();
    int countNodes(Binary_Tree_Node *start);
};

Binary_Tree::Binary_Tree(int arr[]) {
    queue <Binary_Tree_Node*> q;
    root = new Binary_Tree_Node(arr[0]);
    q.push(root);
    int idx = 1;
    while(!q.empty()) {
        Binary_Tree_Node *cur = q.front();
        q.pop();
        int l = arr[idx++];
        int r = arr[idx++];
        if(l!=-1) {
            Binary_Tree_Node *lchild = new Binary_Tree_Node(l);
            cur->left_child = lchild;
            q.push(lchild);
        }
        if(r!=-1) {
            Binary_Tree_Node *rchild = new Binary_Tree_Node(r);
            cur->right_child = rchild;
            q.push(rchild);
        }
    }
}

void Binary_Tree::preorder(Binary_Tree_Node *start) {
    Binary_Tree_Node *node = start;
    if(node == nullptr) return;
    cout << node->data << " ";
    preorder(node->left_child);
    preorder(node->right_child);
}

void Binary_Tree::postorder(Binary_Tree_Node *start) {
    Binary_Tree_Node *node = start;
    if(node == nullptr) return;
    postorder(node->left_child);
    postorder(node->right_child);
    cout << node->data << " ";
}

void Binary_Tree::inorder(Binary_Tree_Node *start) {
    Binary_Tree_Node *node = start;
    if(node == nullptr) return;
    inorder(node->left_child);
    cout << node->data << " ";
    inorder(node->right_child);
}

void Binary_Tree::levelorder(Binary_Tree_Node *start) {
    Binary_Tree_Node *node = start;
    queue <Binary_Tree_Node*> q;
    q.push(node);
    while(!q.empty()) {
        Binary_Tree_Node *cur = q.front();
        q.pop();
        cout << cur->data << " ";
        if(cur->left_child)
            q.push(cur->left_child);
        if(cur->right_child)
            q.push(cur->right_child);
    }
}

int Binary_Tree::countNodes(Binary_Tree_Node *start) {
    Binary_Tree_Node *node = start;
    if(node == nullptr) return 0;
    int x = countNodes(node->left_child);
    int y = countNodes(node->right_child);
    return x + y + 1;
}

int main() {
    int arr[15] = {1,2,3,-1,-1,4,5,-1,6,-1,-1,7,-1, -1, -1};
    Binary_Tree B(arr);
    cout << "Pre-order traversal : ";
    B.preorder(B.root);
    cout << "\nPost-order traversal : ";
    B.postorder(B.root);
    cout << "\nIn-order traversal : ";
    B.inorder(B.root);
    cout << "\nLevel-order traversal : ";
    B.levelorder(B.root);
    cout << "\nNumber of nodes in the given tree are : ";
    cout << B.countNodes(B.root);
    cout << "\n" << B.countNodes(B.root);
    cout << "\n" << B.countNodes(B.root);
    cout << "\n" << B.countNodes(B.root);
}
