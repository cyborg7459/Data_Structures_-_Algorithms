// Explanation : Morris traversal is an algorithm to traverse a binary tree using O(1) extra space. It uses neither recursion nor stack. The process involves modification of the tree, however all the changes
// are reverted by the end of the traversal.

#include <bits/stdc++.h>
using namespace std;
#define inf 100000000

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

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

void MorrisTraversal(Node* node) {
    if(!node) return;
    Node* cur;
    Node* pre;
    cur = node;
    while(cur) {
        if(!cur->left) {
            cout << cur->data << " ";
            cur = cur->right;
        }
        else {
            pre = cur->left;
            while(pre->right && pre->right != cur) {
                pre = pre->right;
            }
            if(!pre->right) {
                pre->right = cur;
                cur = cur->left;
            }
            else {
                pre->right = nullptr;
                cout << cur->data << " ";
                cur = cur->right;
            }
        }
    }
}

int main() {
    cout << "Enter level order traversal of the binary tree (type N for nullptr) : ";
    string s;
    getline(cin, s);
    Node* root = buildTree(s);
    cout  << "Inorder traversal : ";
    MorrisTraversal(root);
}
