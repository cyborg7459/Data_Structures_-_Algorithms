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

bool findPath(Node* node, int num, vector<int>&v) {
    if(!node) return false;
    if(node->data == num) {
        v.push_back(num);
        return true;
    }
    if(findPath(node->left, num, v) || findPath(node->right, num, v)) {
        v.push_back(node->data);
        return true;
    }
    return false;
}

int findDist(Node* root, int a, int b) {
    if(a == b) return 0;
    vector<int> v1, v2;
    findPath(root, a, v1);
    findPath(root, b, v2);
    reverse(v1.begin(), v1.end());
    reverse(v2.begin(), v2.end());
    int idx = 0;
    while(idx < v1.size() && idx < v2.size() && v1[idx] == v2[idx]) {
        idx++;
    }

    if(v1[idx] != v2[idx])
    idx--;

    int ans = (v1.size()-idx-1) + (v2.size()-idx-1);
    return ans;
}

int main() {
    vector<string> v = {"1","2","3","4","5","null","8","null","null","6","7","9","10"};
    int num1 = 4, num2 = 10;
    Node* root = createFromLevelOrder(v);
    cout << findDist(root, num1, num2);
}
