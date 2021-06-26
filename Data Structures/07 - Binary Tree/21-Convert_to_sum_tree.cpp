
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

void inorder(Node* node) {
    if(!node) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
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

int func(Node *node) {
    if(!node) return 0;
    int returnVal = node->data;
    int l = func(node->left);
    int r = func(node->right);
    node->data = l + r;
    return returnVal + l + r;
}

void toSumTree(Node *node)  {
    func(node);
}

int main() {
    vector<string> v = {"1","2","3","4","5","null","8","null","null","6","7","9","10"};
    int num1 = 4, num2 = 10;
    Node* root = createFromLevelOrder(v);
    inorder(root);
    cout << endl;
    toSumTree(root);
    inorder(root);
}
