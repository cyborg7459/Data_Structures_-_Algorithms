#include <bits/stdc++.h>
using namespace std;

class Tree_Node {
public:
    int data;
    int height;
    Tree_Node* left_child;
    Tree_Node* right_child;
    Tree_Node(int x) {
        data = x;
        height = 1;
        left_child = nullptr;
        right_child = nullptr;
    }
};

class AVLTree {
public:
    Tree_Node* root;
    AVLTree() {
        root = nullptr;
    }
    Tree_Node* insert_Node(int key, Tree_Node* node);
    Tree_Node* insert_node_without_rotations(int key, Tree_Node* node);
    void inorder(Tree_Node* node);
    void preorder(Tree_Node* node);
    void postorder(Tree_Node* node);
    void levelorder(Tree_Node* node);
    void print_node_details(Tree_Node *node);
    Tree_Node* LLRotation(Tree_Node* node);
    Tree_Node* LRRotationn(Tree_Node* node);
    Tree_Node* RRRotation(Tree_Node* node);
    Tree_Node* RLRotation(Tree_Node* node);
};

int Node_Height(Tree_Node *node) {
    if(node == nullptr) return 0;
    int left_subtree_height=0, right_subtree_height=0;
    if(node && node->left_child)
        left_subtree_height = node->left_child->height;
    if(node && node->right_child)
        right_subtree_height = node->right_child->height;
    return max(left_subtree_height, right_subtree_height) + 1;
}

int balance_factor(Tree_Node* node) {
    int left_subtree_height=0, right_subtree_height=0;
    if(node && node->left_child)
        left_subtree_height = node->left_child->height;
    if(node && node->right_child)
        right_subtree_height = node->right_child->height;
    return left_subtree_height - right_subtree_height;
}

Tree_Node* AVLTree::LLRotation(Tree_Node* node) {
    Tree_Node* lchild = node->left_child;
    Tree_Node* lrchild = lchild->right_child;
    lchild->right_child = node;
    node->left_child = lrchild;
    node->height = Node_Height(node);
    lchild->height = Node_Height(lchild);
    if(root==node)
        root = lchild;
    return lchild;
}

Tree_Node* AVLTree::LRRotationn(Tree_Node* node) {
    Tree_Node* lchild = node->left_child;
    Tree_Node* lrchild = lchild->right_child;
    lchild->right_child = lrchild->left_child;
    node->left_child = lrchild->right_child;
    lrchild->left_child = lchild;
    lrchild->right_child = node;
    lrchild->height = Node_Height(lrchild);
    lchild->height = Node_Height(lchild);
    node->height = Node_Height(node);
    if(root==node)
        root = lrchild;
    return lrchild;
}

Tree_Node* AVLTree::RRRotation(Tree_Node* node) {
    Tree_Node* rchild = node->right_child;
    Tree_Node* rlchild = rchild->left_child;
    rchild->left_child = node;
    node->right_child = rlchild;
    node->height = Node_Height(node);
    rchild->height = Node_Height(node);
    if(root==node)
        root = rchild;
    return rchild;
}

Tree_Node* AVLTree::RLRotation(Tree_Node* node) {
    Tree_Node* rchild = node->right_child;
    Tree_Node* rlchild = rchild->left_child;
    rchild->left_child = rlchild->right_child;
    node->right_child = rlchild->left_child;
    rlchild->left_child = node;
    rlchild->right_child = rchild;
    rlchild->height = Node_Height(rlchild);
    rchild->height = Node_Height(rchild);
    node->height = Node_Height(node);
    if(root == node)
        root = rlchild;
    return rlchild;
}

Tree_Node* AVLTree::insert_Node(int key, Tree_Node* node) {
    if(node == nullptr) {
        Tree_Node* temp = new Tree_Node(key);
        return temp;
    }
    else if(node->data > key)
        node->left_child = insert_Node(key, node->left_child);
    else if(node->data < key)
        node->right_child = insert_Node(key, node->right_child);
    node->height = Node_Height(node);
    if(balance_factor(node) == 2 && balance_factor(node->left_child) == 1) {
        cout << "Doing LL Rotation for node " << node->data << " while inserting " << key << "\n";
        return LLRotation(node);
    }
    else if(balance_factor(node) == 2 && balance_factor(node->left_child) == -1){
        cout << "Doing LR Rotation for node " << node->data << " while inserting " << key << "\n";
        return LRRotationn(node);
    }
    else if(balance_factor(node) == -2 && balance_factor(node->right_child) == -1) {
        cout << "Doing RR rotation for node " << node->data << " while inserting " << key << "\n";
        return RRRotation(node);
    }
    else if(balance_factor(node) == -2 && balance_factor(node->right_child) == 1){
        cout << "Doing RL rotation for node " << node->data << " while inserting " << key << "\n";
        return RLRotation(node);
    }
    return node;
}

Tree_Node* AVLTree::insert_node_without_rotations(int key, Tree_Node* node) {
    if(node == nullptr) {
        Tree_Node* temp = new Tree_Node(key);
        return temp;
    }
    else if(node->data > key)
        node->left_child = insert_node_without_rotations(key, node->left_child);
    else if(node->data < key)
        node->right_child = insert_node_without_rotations(key, node->right_child);
    node->height = Node_Height(node);
}

void AVLTree::inorder(Tree_Node* node) {
    if(node == nullptr) return;
    inorder(node->left_child);
    cout << node->data << " ";
    inorder(node->right_child);
}

void AVLTree::preorder(Tree_Node* node) {
    if(node == nullptr) return;
    cout << node->data << " ";
    preorder(node->left_child);
    preorder(node->right_child);
}

void AVLTree::postorder(Tree_Node* node) {
    if(node == nullptr) return;
    postorder(node->left_child);
    postorder(node->right_child);
    cout << node->data << " ";
}

void AVLTree::levelorder(Tree_Node* node) {
    queue<Tree_Node*> q;
    q.push(node);
    while(!q.empty()) {
        Tree_Node* current_node = q.front();
        cout << current_node->data << " ";
        q.pop();
        if(current_node->left_child != nullptr)
            q.push(current_node->left_child);
        if(current_node->right_child != nullptr)
            q.push(current_node->right_child);
    }
}

void AVLTree::print_node_details(Tree_Node* node) {
    queue<Tree_Node*> q;
    q.push(node);
    while(!q.empty()) {
        Tree_Node* current_node = q.front();
        cout << "Node : " << current_node->data << "\nHeight : " << Node_Height(current_node) << "\nHeight of left subtree : " << Node_Height(current_node->left_child) << "\nHeight of right subtree : " << Node_Height(current_node->right_child) << "\nBalance Factor : " << balance_factor(current_node) << "\n\n";
        q.pop();
        if(current_node->left_child)
            q.push(current_node->left_child);
        if(current_node->right_child)
            q.push(current_node->right_child);
    }
}

int main() {

    cout << "NORMAL BINARY SEARCH TREE (WITHOUT ROTATIONS)\n=================================================================\n";
    AVLTree normal_tree;
    normal_tree.root = new Tree_Node(10);
    normal_tree.insert_node_without_rotations(12, normal_tree.root);
    normal_tree.insert_node_without_rotations(2, normal_tree.root);
    normal_tree.insert_node_without_rotations(21, normal_tree.root);
    normal_tree.insert_node_without_rotations(11, normal_tree.root);
    normal_tree.insert_node_without_rotations(13, normal_tree.root);
    normal_tree.insert_node_without_rotations(14, normal_tree.root);
    normal_tree.insert_node_without_rotations(132, normal_tree.root);
    normal_tree.insert_node_without_rotations(7, normal_tree.root);
    normal_tree.insert_node_without_rotations(44, normal_tree.root);
    normal_tree.insert_node_without_rotations(23, normal_tree.root);
    normal_tree.insert_node_without_rotations(23, normal_tree.root);
    normal_tree.insert_node_without_rotations(2, normal_tree.root);
    cout << "Inorder Traversal : ";
    normal_tree.inorder(normal_tree.root);
    cout << "\nPreorder Traversal : ";
    normal_tree.preorder(normal_tree.root);
    cout << "\nPostorder Traversal : ";
    normal_tree.postorder(normal_tree.root);
    cout << "\nLevel-order Traversal : ";
    normal_tree.levelorder(normal_tree.root);
    cout << "\n\nNODE DETAILS : \n-------------------\n";
    normal_tree.print_node_details(normal_tree.root);

    cout << "\n\n\nBALANCED AVL TREE (WITH ROTATIONS)\n=================================================================\n";
    AVLTree balaced_tree;
    balaced_tree.root = new Tree_Node(10);
    balaced_tree.insert_Node(12, balaced_tree.root);
    balaced_tree.insert_Node(2, balaced_tree.root);
    balaced_tree.insert_Node(21, balaced_tree.root);
    balaced_tree.insert_Node(11, balaced_tree.root);
    balaced_tree.insert_Node(13, balaced_tree.root);
    balaced_tree.insert_Node(14, balaced_tree.root);
    balaced_tree.insert_Node(132, balaced_tree.root);
    balaced_tree.insert_Node(7, balaced_tree.root);
    balaced_tree.insert_Node(44, balaced_tree.root);
    balaced_tree.insert_Node(23, balaced_tree.root);
    balaced_tree.insert_Node(23, balaced_tree.root);
    balaced_tree.insert_Node(2, balaced_tree.root);
    cout << "Inorder Traversal : ";
    balaced_tree.inorder(balaced_tree.root);
    cout << "\nPreorder Traversal : ";
    balaced_tree.preorder(balaced_tree.root);
    cout << "\nPostorder Traversal : ";
    balaced_tree.postorder(balaced_tree.root);
    cout << "\nLevel-order Traversal : ";
    balaced_tree.levelorder(balaced_tree.root);
    cout << "\n\nNODE DETAILS : \n-------------------\n";
    balaced_tree.print_node_details(balaced_tree.root);

    return 0;

}
