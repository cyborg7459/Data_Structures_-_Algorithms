// Explanation : The check balanced and the diameter programs done before were O(n^2). However, we can optimise those if we keep updating the answer while calculating the height of each node. Hence,
// we just need to calculate the height once for each node and the time complexity is improved to O(n). Since we do not return the actual required value from the function, and rather just pass by
// reference the result and update while calculating height, hence we're ensured that when we call the function by passing in root, we don't get the answer for root only, i.e. in both diameter and
// check balanced we just don't have to run the function w.r.t root, but all nodes. This is automatically done in this method

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
	Node* root = new Node(stoi(v[0]));
	queue<Node*> q;
	q.push(root);
	unsigned int idx = 1;
	while(!q.empty() && idx < v.size()) {
		Node* node = q.front();
		q.pop();
		if(v[idx] == "null")
			node->left = nullptr;
		else {
			node->left = new Node(stoi(v[idx]));
			q.push(node->left);
		}
		idx++;
		if(idx >= v.size()) break;
		if(v[idx] == "null")
			node->right = nullptr;
		else {
			node->right = new Node(stoi(v[idx]));
			q.push(node->right);
		}
		idx++;
	}
	return root;
}

int func1(Node* node, bool &b) {
    if(!node) return 0;

    int lh = func1(node->left, b);
    int rh = func1(node->right, b);

    if(abs(lh - rh) > 1) b = false;
    return 1 + max(lh, rh);
}

bool isBalanced(Node *root) {
    if(!root) return true;
    bool ans = true;
    func1(root, ans);
    return ans;
}

int func2(Node* node, int &ans) {
    if(!node) return 0;

    int lh = func2(node->left, ans);
    int rh = func2(node->right, ans);

    ans = max(ans, 1 + lh + rh);
    return 1 + max(lh, rh);
}

int diameter(Node* root) {
    if(!root) return 0;
    int ans = -1;
    func2(root, ans);
    return ans;
}

int main() {
    vector<string> v = {"10", "20", "30", "40", "50"};
    Node* root = createFromLevelOrder(v);
    cout << boolalpha << isBalanced(root) << endl;
    cout << diameter(root);
}
