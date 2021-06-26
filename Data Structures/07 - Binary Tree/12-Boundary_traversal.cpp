#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node(int _val) {
		val = _val;
		left = nullptr;
		right = nullptr;
	}
};

Node* createFromLevelOrder(vector<string> v) {
	if(v.size() == 0) return nullptr;
	Node* root = new Node(stoi(v[0]));
	queue<Node*> q;
	q.push(root);
	unsigned int idx = 1;
	while(!q.empty() && idx < v.size()) {
		Node* node = q.front();
		q.pop();
		if(v[idx] == "N")
			node->left = nullptr;
		else {
			node->left = new Node(stoi(v[idx]));
			q.push(node->left);
		}
		idx++;
		if(idx >= v.size()) break;
		if(v[idx] == "N")
			node->right = nullptr;
		else {
			node->right = new Node(stoi(v[idx]));
			q.push(node->right);
		}
		idx++;
	}
	return root;
}

void inorder(Node* node, vector<int> &v) {
    if(!node) return;
    inorder(node->left, v);
    if(node->left == nullptr && node->right == nullptr) {
        v.push_back(node->val);
        return;
    }
    inorder(node->right, v);
}

vector <int> printBoundary(Node *root) {
    if(!root) return {};
    vector<int> left_edge, right_edge, leaf_nodes;
    Node* cur = root->left;
    while(cur != nullptr) {
        left_edge.push_back(cur->val);
        if(!cur->left) cur = cur->right;
        else cur = cur->left;
    }
    cur = root->right;
    while(cur != nullptr) {
        right_edge.push_back(cur->val);
        if(!cur->right) cur = cur->left;
        else cur = cur->right;
    }
    reverse(right_edge.begin(), right_edge.end());
    inorder(root, leaf_nodes);

    vector<int> ans;
    ans.push_back(root->val);
    for(int t : left_edge) ans.push_back(t);
    int start = 0, end = leaf_nodes.size()-1;
    if(left_edge.size() > 0) start = 1;
    if(right_edge.size() > 0) end--;
    for(int i=start; i<=end; i++) ans.push_back(leaf_nodes[i]);
    for(int t : right_edge) ans.push_back(t);

    return ans;
}

int main() {
    vector<string> level_order = {"17","N","1","N","9","N","2","N","11","N","16","N","8","N","5","N","3","N","10","N","13","N","5","N","13","N","7","N","10","N","4","N","7","N","2","N","12","N","16"};
    Node* root = createFromLevelOrder(level_order);
    vector<int> v = printBoundary(root);
    for(int t : v) cout << t << " ";
}
