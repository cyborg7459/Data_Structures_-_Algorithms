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
    Tree_node(int x) {
        data = x;
        left_child = nullptr;
        right_child = nullptr;
    }
};

class BST {
public:
    Tree_node *root;
    BST() {
        root = nullptr;
    }
    BST(std::vector<int> v);
    BST(std::vector<int> v, int n);
    void inorder(Tree_node *start);
    Tree_node* search(int key, Tree_node *start);
    int height(Tree_node *node);
    Tree_node* insert_in_BST(int key, Tree_node *node);
    Tree_node* InPre(Tree_node *node);
    Tree_node* InSuc(Tree_node *node);
    Tree_node* delete_node(int key, Tree_node *node);
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

BST::BST(std::vector<int> v, int n) {
    root = new Tree_node(v[0]);
    for(int i=1; i<n; i++) {
        Tree_node *node = root;
        while(true) {
            if(node->data > v[i]) {
                if(node->left_child == nullptr) {
                    node->left_child = new Tree_node(v[i]);
                    break;
                }
                else
                    node = node->left_child;
            }
            else if(node->data < v[i]) {
                if(node->right_child == nullptr) {
                    node->right_child = new Tree_node(v[i]);
                    break;
                }
                else
                    node = node->right_child;
            }
            else
                break;
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

int BST::height(Tree_node *node) {
    if(node==nullptr) return 0;
    int x = height(node->left_child);
    int y = height(node->right_child);
    if(x>y) return x+1;
    else return y+1;
}

Tree_node* BST::insert_in_BST(int key, Tree_node *node) {
    Tree_node *t;
    if(node == nullptr) {
        t = new Tree_node(key);
        return t;
    }
    if(node->data > key)
        node->left_child = insert_in_BST(key, node->left_child);
    else if(node->data < key)
        node->right_child = insert_in_BST(key, node->right_child);
    return node;
}

Tree_node* BST::InPre(Tree_node *node) {
    if(node->left_child == nullptr) return nullptr;
    else {
        node = node->left_child;
        while(node->right_child != nullptr)
            node = node->right_child;
        return node;
    }
}

Tree_node* BST::InSuc(Tree_node *node) {
    if(node->right_child == nullptr) return nullptr;
    else {
        node = node->right_child;
        while(node->left_child != nullptr)
            node = node->left_child;
        return node;
    }
}

Tree_node* BST::delete_node(int key, Tree_node *node) {
    if(node == nullptr) return nullptr;
    if(node->left_child==nullptr && node->right_child==nullptr && node->data==key) {
        if(node == root)
            root = nullptr;
        delete node;
        return nullptr;
    }
    if(key < node->data)
        node->left_child = delete_node(key, node->left_child);
    else if(key > node->data)
        node->right_child = delete_node(key, node->right_child);
    else {
        if(height(node->left_child) > height(node->right_child)) {
            Tree_node *temp = InPre(node);
            node->data = temp->data;
            node->left_child = delete_node(temp->data, node->left_child);
        }
        else {
            Tree_node *temp = InSuc(node);
            node->data = temp->data;
            node->right_child = delete_node(temp->data, node->right_child);
        }
    }
}

int main() {
    // CREATING A BST USING VECTOR WITH LEVEL ORDER GIVEN
    // std::vector<int> v = {40,30,70,-1,35,55,75,-1,-1,45,65,-1,-1,-1,-1,-1,-1};
    // BST k(v);
    // k.inorder(k.root);

    // SEARCHING FOR ELEMENTS IN A BST
    // for(int i = 44; i<=77; i++) {
    //     cout << i << " : ";
    //     k.search(i, k.root);
    //     cout << "Number of steps : " << steps << "\n";
    //     steps = 0;
    // }

    // INSERTING ELEMENTS TO A BST
    // for(int i=47; i<70; i+=4) {
    //     Tree_node *x = k.insert_in_BST(i, k.root);
    //     cout << "Inserted " << i << "\n";
    //     k.inorder(k.root);
    //     cout << "\n";
    // }

    // CREATING A BST FROM A RANDOM VECTOR
    // std::vector<int> v1 = {9,15,5,5,5,20,16,8,12,3,6};
    // BST k1(v1, v1.size());
    // k1.inorder(k1.root);

    // CREATING A BST USING INSERT FUNCTION AND DELETING NODES USING RECURSIVE DELETING
    // BST k2;
    k2.root = k2.insert_in_BST(5, k2.root);
    k2.insert_in_BST(4, k2.root);
    k2.insert_in_BST(10, k2.root);
    k2.insert_in_BST(9, k2.root);
    k2.insert_in_BST(16, k2.root);
    k2.insert_in_BST(18, k2.root);
    k2.insert_in_BST(13, k2.root);
    k2.insert_in_BST(16, k2.root);
    k2.insert_in_BST(14, k2.root);
    k2.delete_node(1, k2.root);
    k2.inorder(k2.root);
    cout << "\n" << k2.root->data;
    // Tree_node* C_node = (Tree_node*)malloc(sizeof(Tree_node(100)));
    // C_node->data = 4;
    // printf("%d", C_node->data);
    return 0;
}
