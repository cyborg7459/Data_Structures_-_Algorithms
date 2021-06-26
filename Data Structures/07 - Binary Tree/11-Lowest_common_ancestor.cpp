#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
    void inorder(TreeNode* node) {
        if(!node) return;
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    }
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

bool findPath(int val, TreeNode* node, vector<TreeNode*> &v) {
    if(!node) return false;
    if(node->val == val) {
        v.push_back(node);
        return true;
    }
    if(findPath(val, node->left, v)) {
        v.push_back(node);
        return true;
    }
    if(findPath(val, node->right, v)) {
        v.push_back(node);
        return true;
    }
    return false;
}

TreeNode* lca(TreeNode* root ,int n1 ,int n2 ) {
    vector<TreeNode*> v1, v2;
    findPath(n1, root, v1);
    findPath(n2, root, v2);
    reverse(v1.begin(), v1.end());
    reverse(v2.begin(), v2.end());
    int i1 = 1, i2 = 1, a = v1.size(), b = v2.size();
    TreeNode* cur = v1[0];
    while(i1 < a && i2 < b) {
        if(v1[i1] != v2[i2]) return cur;
        cur = v1[i1];
        i1++;
        i2++;
    }
    return cur;
}

int main() {
    vector<string> v = {"5", "2", "null", "3", "4"};
    TreeNode* root = createFromLevelOrder(v);
    int n1 = 3, n2 = 4;
    TreeNode *node = lca(root, n1, n2);
    cout << "Lowest common ancestor of nodes " << n1 << " and " << n2 << " is : "  << node->val;
}
