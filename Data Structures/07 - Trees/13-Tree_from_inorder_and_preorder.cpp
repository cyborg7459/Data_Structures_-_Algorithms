#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

void postorder(Node* root) {
    if(root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int cur = 0;

Node* func(int in[], int pre[], int start, int end) {
    if(start > end) {
        return nullptr;
    }
    Node* root = new Node(pre[cur]);
    if(start == end) {
        cur++;
        return root;
    }
    cur++;
    int idx;
    for(int i=start; i<=end; i++) {
        if(in[i] == root->data) {
            idx = i;
            break;
        }
    }
    root->left = func(in, pre, start, idx-1);
    root->right = func(in, pre, idx+1, end);
    return root;
}

Node* buildTree(int in[],int pre[], int n) {
    return func(in, pre, 0, n-1);
}

int main() {
    int n = 6;
    int in[n] = {3,1,4,0,5,2};
    int pre[n] = {0,1,3,4,2,5};
    Node* root = buildTree(in, pre, n);
    postorder(root);
}
