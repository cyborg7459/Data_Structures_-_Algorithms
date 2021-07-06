// Explanation : We can solve this problem bu recursively making sure that each of the nodes lies in the given range, for which we convert the node into the nearest node lying in the range, and modify
// it's left and right children as well. We need to start bottom up becuase only after we've done the procedure for the children we can be sure that setting the node in the range would give the correct
// BST

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N') return NULL;
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);
    Node* root = newNode(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if (currVal != "N") {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];
        if (currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

Node* func(Node* root, int l, int r) {
    if(!root) return root;
    root->left = func(root->left, l, r);
    root->right = func(root->right, l, r);
    while(root && root->data < l) root = root->right;
    while(root && root->data > r) root = root->left;
    return root;
}

Node* removekeys(Node* root, int l, int r) {
    return func(root, l, r);
}

int main() {
    int l, r;
    cin >> l >> r;
    string ln;
    getline(cin, ln);
    string inp, ch;
    getline(cin, inp);
    struct Node* root = buildTree(inp);
    Node* head = removekeys(root, l, r);
    inorderTraversal(head);
}
