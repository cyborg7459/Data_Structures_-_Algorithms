// PS : Given a binary tree, we have to calculate the maximum path sum between any 2 leaf nodes. In case there is only a single leaf node, then we simply return the distance of that node from the root node.
// The nodes are weighted, and their value can be negative as well
// Explanation : Here again, we'll use the method of updating the answer while simultaneously calculating height. Here, instead of just heigh, we also return the maximum distance of that node from a leaf node
// and hence we return a pair. Note that the height returned is not the max height but instead the height of the path taken to achieve maximum value (Although it doesn't affect our solution but for the sake of
// properness). Now for each node, we recursively call the function for the left child and the right child. Since a pair is returned, hence we get to know the max distance of left & right child from a leaf node.
// If the node has both a left and right child both, i.e. if it is not a leaf node, then we can update the value of ans if possible. Otherwise we simply return the height and value. At the very end we check
// if the ans is still -inf then it means there was only 1 leaf node in the tree, and hence simply return the value given by the root node

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int _data) {
		data = _data;
		left = nullptr;
		right = nullptr;
	}
};

void printInorder(Node* node) {
    if(!node) return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node* createFromLevelOrder(vector<string> v) {
	if(v.size() == 0) return nullptr;
    bool b = false;
    if(v[0][0] == '-') {
        v[0].erase(v[0].begin());
        b = true;
    }
	Node* root = new Node(stoi(v[0]));
    if(b) root->data = -1 * root->data;
	queue<Node*> q;
	q.push(root);
	unsigned int idx = 1;
	while(!q.empty() && idx < v.size()) {
		Node* node = q.front();
		q.pop();
		if(v[idx] == "N")
			node->left = nullptr;
		else {
            string temp = v[idx];
            if(temp[0] == '-') {
                temp.erase(temp.begin());
                stoi(temp);
                node->left = new Node(-1 * stoi(temp));
            }
            else node->left = new Node(stoi(v[idx]));
			q.push(node->left);
		}
		idx++;
		if(idx >= v.size()) break;
		if(v[idx] == "N")
			node->right = nullptr;
		else {
            if(v[idx][0] == '-') {
                v[idx].erase(v[idx].begin());
                node->right = new Node(-1 * stoi(v[idx]));
            }
			else node->right = new Node(stoi(v[idx]));
			q.push(node->right);
		}
		idx++;
	}
	return root;
}

pair<int, int> func(Node* root, int &ans) {
   if(!root) return {0, 0};

   pair<int, int> lcp = func(root->left, ans);
   pair<int, int> rcp = func(root->right, ans);

   int lch = lcp.first, lcv = lcp.second;
   int rch = rcp.first, rcv = rcp.second;

   if(lch > 0 && rch > 0)
       ans = max(ans, root->data + lcv + rcv);

   int h, val;
   if(lch == 0 && rch > 0) {
       h = 1 + rch;
       val = root->data + rcv;
   }
   else if(lch > 0 && rch == 0) {
       h = 1 + lch;
       val = root->data + lcv;
   }
   else if(lch == 0 && rch == 0) {
       h = 1;
       val = root->data;
   }
   else {
       bool b = (lcv > rcv);
       if(b) h = 1 + lch;
       else h = 1 + rch;
       val = root->data + max(lcv, rcv);
   }

   return {h, val};

}

int maxPathSum(Node* root) {
   int ans = -1000000007;
   pair<int, int> p= func(root, ans);
   if(ans == -1000000007) ans = p.second;
   return ans;
}

int main() {
    vector<string> v = {"-15","5","6","-8","1","3","9","2","-3","N","N","N","N","N","0","N","N","N","N","4","-1","N","N","10","N"};
    Node* root = createFromLevelOrder(v);
    cout << maxPathSum(root);
}
