// Explanation : For checking a BST, all we have to do is to recursively check that the maximum value node in the left subtree is smaller than the current node, and the minimum value node in the right subtree is
// greater than the current node. We can do this using the updation while calculation method (done in Binary Trees)

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

pair<int, int> minMaxNode(Node* root, bool &b) {
    if(!root) return {1000000000, -1000000000};
    pair<int, int> lc = minMaxNode(root->left, b);
    pair<int, int> rc = minMaxNode(root->right, b);
    if(!(lc.second == 0))
        if(lc.second >= root->data) b = false;
    if(!(rc.first == 0))
        if(rc.first <= root->data) b = false;
    return {min(root->data, min(lc.first, rc.first)), max(root->data, max(lc.second, rc.second))};
}

bool isBST(Node* root) {
    bool b = true;
    minMaxNode(root, b);
    return b;
}

Node* buildTree(string str) {
   if(str.length() == 0 || str[0] == 'N')
       return NULL;
   vector<string> ip;
   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);
   Node* root = new Node(stoi(ip[0]));
   queue<Node*> queue;
   queue.push(root);
   int i = 1;
   while(!queue.empty() && i < ip.size()) {
       Node* currNode = queue.front();
       queue.pop();
       string currVal = ip[i];
       if(currVal != "N") {
           currNode->left = new Node(stoi(currVal));
           queue.push(currNode->left);
       }
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];
       if(currVal != "N") {
           currNode->right = new Node(stoi(currVal));
           queue.push(currNode->right);
       }
       i++;
   }
   return root;
}

void inorder(Node *root, vector<int> &v) {
    if(root==NULL)
        return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {
    string s;
    getline(cin, s);
    Node* root = buildTree(s);
    if(isBST(root))
        cout<<"YES";
    else
        cout<<"NO";
}
