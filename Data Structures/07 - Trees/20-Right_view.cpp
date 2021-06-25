// Explanation : Right view is basically when we printing the rightmost node in each level in level order traversal, hence we can easily do this by traversing level order by taking right child first.
// Then at each level, store the first node in a vector. Similarly in left view also we can do this but that would be normal level order traversal

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

vector<int> rightView(Node *root) {
    if(!root) return {};
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);
    while(true) {
        Node* node = q.front();
        q.pop();
        if(!node) break;
        ans.push_back(node->data);
        if(node->right) q.push(node->right);
        if(node->left) q.push(node->left);
        while(true) {
            Node* node = q.front();
            q.pop();
            if(!node) break;
            if(node->right) q.push(node->right);
            if(node->left) q.push(node->left);
        }
        q.push(nullptr);
    }
    return ans;
}

int main() {
    vector<string> v = {"10", "20", "30", "40", "50"};
    Node* root = createFromLevelOrder(v);
    vector<int> v1 = rightView(root);
    for(int t : v1) cout << t << " ";
}
