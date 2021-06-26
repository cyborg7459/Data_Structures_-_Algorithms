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

vector<int> reverseLevelOrder(Node *root) {
    if(!root) return {};
    stack<int> st;
    queue<Node*> q;
    vector<int> ans;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()) {
        while(true) {
            Node* node = q.front();
            q.pop();
            if(!node) {
                q.push(nullptr);
                break;
            }
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            st.push(node->data);
        }
        if(st.empty()) break;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<string> v = {"10", "20", "30", "40", "50"};
    Node* root = createFromLevelOrder(v);
    vector<int> v1 = reverseLevelOrder(root);
    for(int t : v1) cout << t << " ";
}
