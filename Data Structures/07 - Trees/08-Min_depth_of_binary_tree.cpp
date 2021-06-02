// PS : Print the minimum depth of a binary tree
// Explanation : One tricky edge case is that if there is no LST or RST then it returns zero. In such a case the min becomes 1 for that root, but this answer
// is incorrect as we have to consider the height of subtree only if it exists. Hence some additional conditional statements in the solution

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int _val) {
		val = _val;
		left = nullptr;
		right = nullptr;
	}
};

TreeNode* createFromLevelOrder(vector<string> v) {
	if(v.size() == 0) return nullptr;
	TreeNode* root = new TreeNode(stoi(v[0]));
	queue<TreeNode*> q;
	q.push(root);
	unsigned int idx = 1;
	while(!q.empty() && idx < v.size()) {
		TreeNode* node = q.front();
		q.pop();
		if(v[idx] == "null")
			node->left = nullptr;
		else {
			node->left = new TreeNode(stoi(v[idx]));
			q.push(node->left);
		}
		idx++;
		if(idx >= v.size()) break;
		if(v[idx] == "null")
			node->right = nullptr;
		else {
			node->right = new TreeNode(stoi(v[idx]));
			q.push(node->right);
		}
		idx++;
	}
	return root;
}

void printLevelOrder(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()) {
		TreeNode* node = q.front();
		q.pop();
		if(!node) {
			cout << "null ";
			continue;
		}
		else {
			cout << node->val << " ";
			q.push(node->left);
			q.push(node->right);
		}
	}
}

int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int a = minDepth(root->left);
        int b = minDepth(root->right);
        if(a == 0 && b == 0) return 1;
        else if(a == 0) return 1 + b;
        else if(b == 0) return 1 + a;
        else return 1 + min(a, b);
    }

int main() {
	vector<string> v = {"3","9","20","null","null","15","7"};
	TreeNode* root = createFromLevelOrder(v);
	cout << minDepth(root);
}
