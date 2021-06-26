// We can print the spiral order by using 2 stacks, similar to how we implement a stack using 2 queues, i.e. we use one stack for operation and one stack for pushing the nodes. Whether we push the
// right or left child first depends on the level we are currently on, and we can alternate that using a bool variable

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

vector<int> findSpiral(Node *root);
Node* buildTree(string str) {
    if(str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
    Node* root = newNode(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if(currVal != "N") {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
        if(currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}


int main() {
    string s;
    getline(cin,s);
    Node* root = buildTree(s);
    vector<int> vec = findSpiral(root);
    for(int x : vec)
    cout<<x<<" ";
    cout << endl;
}

stack<Node*> st1, st2;
vector<int> findSpiral(Node *root) {
    if(!root) return {};
    vector<int> res;
    st1.push(root);
    bool b = true;
    while(!st1.empty()) {
        while(!st1.empty()) {
            Node* cur = st1.top();
            st1.pop();
            res.push_back(cur->data);
            if(b) {
                if(cur->right) st2.push(cur->right);
                if(cur->left) st2.push(cur->left);
            }
            else {
                if(cur->left) st2.push(cur->left);
                if(cur->right) st2.push(cur->right);
            }
        }
        stack<Node*> temp = st1;
        st1 = st2;
        st2 = temp;
        b = !b;
    }

    return res;
}
