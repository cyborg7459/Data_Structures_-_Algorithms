#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int _data) {
        data = _data;
        left = nullptr;
        right = nullptr;
    }
};

void inorder(node* root) {
    if(!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node* root) {
    if(!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void levelorder(node* root) {
    queue<node*> q;
    q.push(root);
    while(!q.empty()) {
        node* node = q.front();
        q.pop();
        cout << node->data << " ";
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
}

node* createFromBracketRepresentation(string s) {
    stack<node*> st;
    string temp;
    int idx = 0, n = s.length();
    while(idx < n && s[idx] != '(') {
        temp.push_back(s[idx]);
        idx++;
    }
    idx++;

    node* root = new node(stoi(temp));
    node* cur = root;
    st.push(root);
    temp = "";

    while(idx < n) {
        char c = s[idx];
        if(c == '(') {
            if(temp != "") {
                node* new_node = new node(stoi(temp));
                temp = "";
                if(st.top()->left == nullptr) st.top()->left = new_node;
                else st.top()->right = new_node;
                st.push(new_node);
            }
        }
        else if(c == ')') {
            if(temp != "") {
                node* new_node = new node(stoi(temp));
                temp = "";
                if(st.top()->left == nullptr) st.top()->left = new_node;
                else st.top()->right = new_node;
            }
            else st.pop();
        }
        else temp.push_back(s[idx]);
        idx++;
    }

    return root;
}

int main() {
    string s = "4(2(3)(1))(6(5))";
    node* root = createFromBracketRepresentation(s);
    inorder(root);
}
