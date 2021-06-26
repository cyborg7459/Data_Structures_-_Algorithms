// PS : Find the diameter of the given binary tree, where diameter is the maximum path distacne between any two leaf nodes
// Explanation : For a given node as root, the longest path containing that root would be equal to the maximum distance of that node from a leaf node on it's left and right, plus 1 (for the root itself).
// Hence our goal is to maximize this maxDistance. It is not always necessary that the ultimate root lies in the diameter path. Hence, use recursion to check for diameters of child elements as well

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

int maxDistance(TreeNode* node) {
    if(!node) return 0;
    return 1 + max(maxDistance(node->left), maxDistance(node->right));
}

int diameter(TreeNode* root) {
    if(!root) return 0;
    return max(1 + maxDistance(root->left) + maxDistance(root->right), max(diameter(root->left), diameter(root->right)));
}

int main() {
	vector<string> v = {"3","9","20","null","null","15","7"};
	TreeNode* root = createFromLevelOrder(v);
	cout << diameter(root);
}
