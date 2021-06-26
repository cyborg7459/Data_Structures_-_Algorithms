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

int sum(Node* root) {
    if(!root) return 0;
    int res = root->data;
    return res + sum(root->left) + sum(root->right);
}

bool func(Node* root) {
    if(!root) return true;
    if(!root->left && !root->right) return true;
    return (root->data == sum(root->left) + sum(root->right));
}

bool isSumTree(Node* root) {
    if(!root) return true;
    return func(root) && isSumTree(root->left) && isSumTree(root->right);
}

int main() {
	vector<string> v1 = {"3","9","20","null","null","15","7"};
	Node* root1 = createFromLevelOrder(v1);
    vector<string> v2 = {"70","20","30","10","10"};
    Node* root2 = createFromLevelOrder(v2);
    if(isSumTree(root1)) cout << "First tree is a sum tree\n";
    else cout << "First tree is not a sum tree\n";
    if(isSumTree(root2)) cout << "Second tree is a sum tree";
    else cout << "Second tree is not a sum tree";
}
