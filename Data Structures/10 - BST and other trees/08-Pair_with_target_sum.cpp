// Explanation :-
// Brute force solution is to find all the pairs of keys and check, however this has a time complexity of O(n^2)
// We can store the inorder traversal in a vector and check it using 2-pointer method, but the space complexity of this method is O(n)
// We can solve the question in O(n) time and O(log(n)) space. For this, we need 2 stacks, one for the iterative inorder, and the other for the reverse iterative inorder. And then we'll use the 2-pointer
// technique for the stack tops until we get an answer. The steps of filling the stack are similar to iterative inorder (in reverse one we first push right child). In case both cur1 and cur2 become null
// then we check the top of both stacks. If sum is less that target, it means that we no longer need the current top of the normal inorder. Hence we pop it and make cur1 = top->right (as is done in iterative
// inorder). If sum is greater than target, then we make cur2 = top->left (opposite of what we do in normal inorder). We keep doing so until we get the sum or either of the stacks becomes empty

#include <bits/stdc++.h>
using namespace std;

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

int isPairPresent(struct Node *root, int target) {
    if(!root) return 0;
    stack<Node*> in, rev;
    Node* cur1 = root;
    Node* cur2 = root;
    while(true) {
        if(cur1) {
            in.push(cur1);
            cur1 = cur1->left;
        }
        else if(cur2) {
            rev.push(cur2);
            cur2 = cur2->right;
        }
        else {
            if(in.empty() || rev.empty()) break;
            Node* node1 = in.top();
            Node* node2 = rev.top();
            if(node1 == node2) break;
            int sum = node1->data + node2->data;
            if(sum == target) return 1;
            else if(sum < target) {
                in.pop();
                cur1 = node1->right;
            }
            else {
                rev.pop();
                cur2 = node2->left;
            }
        }
    }
    return 0;
}

int main() {
    string s;
    getline(cin, s);
    Node* root = buildTree(s);
    getline(cin, s);
    int k = stoi(s);
    cout << isPairPresent(root, k);
}
