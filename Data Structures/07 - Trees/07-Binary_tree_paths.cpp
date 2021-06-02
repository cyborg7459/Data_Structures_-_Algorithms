// PS : Print all the root to leaf paths possible in a binary tree
// Explanation : This is a very important problem and through this, see how the handling of vectors can be done in a recursive function

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

vector<string> binaryTreePaths(TreeNode* root) {
    if(root == nullptr) return {};
    vector<string> v1 = binaryTreePaths(root->left);
    vector<string> v2 = binaryTreePaths(root->right);
    vector<string> ans;
    for(string s : v1)
        ans.push_back(to_string(root->val) + "->" + s);
    for(string s : v2)
        ans.push_back(to_string(root->val) + "->" + s);
    if(ans.size() == 0)
        ans.push_back(to_string(root->val));
    return ans;
}

int main() {
	vector<string> v = {"3","9","20","null","null","15","7"};
	TreeNode* root = createFromLevelOrder(v);
	vector<string> v1 = binaryTreePaths(root);
    cout << v1.size() << " paths from root to leaves :-\n";
    for(string s : v1)
        cout << s << "\n";
}
