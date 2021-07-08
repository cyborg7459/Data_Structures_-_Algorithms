// PS : Given a binary tree, we need to find out the size of the largest BST that lies within the binary tree, where size is represented by the number of nodes
// Explanation : For the given problem, we need to check for each node whether the subtree rooted at the given node is a BST or not. Since we want the solution in O(N), hence we cannot run the check function
// individually for each node and update answer. We have to check for all the nodes recursively and update answer real-time during the recursion. For this, we'll make some modifications to the check BST function
// done earlier. We'll still return the minimum and maximum value of subtree, but along with it, we'll also return the size of the subtree if it is a BST. Hence, the return type is pair<pair<int, int>, int>
// Now we start the recursion from the root node and recursively check for the left and right subtree. A subtree rooted at a given node is a BST iff
// 1) Both it's left subtree and right subtree, if they exist, are BSTs
// 2) The value of root is larger than the largest value in the left subtree and smaller than the smallest value in the right subtree
// Both of these things can be checked by the return value of the child subtrees. For the first point, what we can do is if a given node is not the root of a BST, return -1 for it's size. Hence, encountering a size
// of -1 for any of the child would mean that it cannot be a BST and we don't need to check point 2. Point 2 can be checked easily since we're returning those values
// In case the given node is a BST, then we have to update the values of min and max, update the value of answer, and return 1 + size of left_child + size of right_child as the size
// If it is not BST, then simply return size as -1, max and min values don't matter as they won't be used in the parent in size is -1

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

pair<pair<int,int>, int> util(Node* node, int &ans) {
    if(!node) return {{inf, -1*inf}, 0};

    pair<pair<int, int>, int> lc = util(node->left, ans);
    pair<pair<int, int>, int> rc = util(node->right, ans);

    int mn = -1*inf, mx, cnt;
    if(lc.second == -1 || rc.second == -1) cnt = -1;
    else if((lc.first.second == inf || lc.first.second < node->data) && (rc.first.first == -1*inf || rc.first.first > node->data)) {
        mn = min(node->data, min(lc.first.first, rc.first.first));
        mx = max(node->data, max(lc.first.second, rc.first.second));
        ans = max(ans, 1 + lc.second + rc.second);
        cnt = 1 + lc.second + rc.second;
    }
    else cnt = -1;

    return {{mn, mx}, cnt};
}

int largestBst(Node *root) {
	Node* node = root;
	int ans = 0;
	util(node, ans);
	return ans;
}

int main() {
    cout << "Enter level order traversal of the binary tree (type N for nullptr) : ";
    string s;
    getline(cin, s);
    Node* root1 = buildTree(s);
    cout << largestBst(root1);
}
