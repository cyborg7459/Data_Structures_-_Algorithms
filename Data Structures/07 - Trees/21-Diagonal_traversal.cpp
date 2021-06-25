// Explanation : In diagonal view, all elements who lie on the same dagonal have the same value of (h-w), where h is the height (root height = 1) and w is the column number (root in column 0)
// Hence exploit this fact to separate all elements diagonal-wise

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

vector<int> arr[1000000];

void inorder(Node* node, int h, int w, int &end) {
    if(!node) return;
    inorder(node->left, h+1, w-1, end);
    arr[h-w].push_back(node->data);
    end = max(end, h-w);
    inorder(node->right, h+1, w+1,end);
}

vector<int> diagonal(Node *root) {
    memset(arr, {}, sizeof arr);
    int end = 0;
    inorder(root, 1, 0, end);

    vector<int> ans;
    for(int i=0; i<=end; i++) {
        for(int t : arr[i]) ans.push_back(t);
    }

    return ans;
}

int main() {
    vector<string> v = {"5","6","4","9","null","3","6","9","1","null","10","7","2","7","null","10","3","7","1","null","6","7","4","3"};
    Node* root = createFromLevelOrder(v);
    vector<int> v1 = diagonal(root);
    for(int t : v1)
        cout << t << " ";
}
