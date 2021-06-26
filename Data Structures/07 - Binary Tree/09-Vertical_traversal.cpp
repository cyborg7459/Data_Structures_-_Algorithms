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
    bool vis[1000000] = {};
    node* root;
    Binary_Tree(vector<int> v);
    vector<int> Vertical_Traversal(node* root);
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

vector<int> arr[20000];
vector<int> Binary_Tree::Vertical_Traversal(node* root) {
    for(int i=0; i<20000; i++) arr[i].clear();
    vector<int> ans = {};
    if(!root) return ans;
    int cur = 10000;
    queue<pair<node*, int>> q;
    q.push({root, cur});
    while(!q.empty()) {
        pair<node*, int> p = q.front();
        q.pop();
        node* cur = p.first;
        int idx = p.second;
        arr[idx].push_back(cur->data);
        if(cur->left_child) q.push({cur->left_child, idx-1});
        if(cur->right_child) q.push({cur->right_child, idx+1});
    }

    while(arr[cur].size() != 0) cur--;
    cur++;

    while(true) {
        for(int t : arr[cur]) ans.push_back(t);
        cur++;
        if(arr[cur].size() == 0) break;
    }
    return ans;
}

int main() {
    vector<int> v = {19, 10, 8, 11, 13, -1, -1};
    Binary_Tree b(v);
    vector<int> v1 = b.Vertical_Traversal(b.root);
    for(auto t : v1)
        cout << t << " ";
}
