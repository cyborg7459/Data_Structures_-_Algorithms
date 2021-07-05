// PS : Given the pre-order traversal of a tree, find out whether it can be a BST or not
// Explanation : The logic behind this question is that once a node has been added to the right subtree of a given node, then we cannot have a value smaller than that node's value in the tree. This is because
// 1) If we put the node in left subtree to maintain the rule for BST, then it is no longer pre-order (since LST can't come after RST in pre-order)
// 2) If we put the node in right subtree then the tree no longer remains a BST

#include <bits/stdc++.h>
using namespace std;

int canRepresentBST(int arr[], int N) {
    int last_removed = -1;
    stack<int> st;
    for(int i=0; i<N; i++) {
        int num = arr[i];
        if(num < last_removed) return 0;
        while(!st.empty() && st.top() < num) {
            last_removed = st.top();
            st.pop();
        }
        st.push(num);
    }
    return 1;
}

int main() {
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++) cin >> arr[i];
    cout << canRepresentBST(arr, N);
}
