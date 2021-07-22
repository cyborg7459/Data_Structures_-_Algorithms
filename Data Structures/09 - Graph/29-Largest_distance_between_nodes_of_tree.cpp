// Given an arbitrary unweighted rooted tree which consists of N nodes. The goal of the problem is to find largest distance between two nodes in a tree. Distance between two nodes is a number of
// edges on a path between the nodes (there will be a unique path between any pair of nodes since it is a tree). The nodes will be numbered 0 through N - 1. The tree is given as an array A, there
// is an edge between nodes A[i] and i (0 <= i < N). Exactly one of the i's will have A[i] equal to -1, it will be root node.

// Solution : We will calculate the answer in real-time while returning the height of subtree. For each node, we'll create a vector of heights of all subtrees originating from that node. Now the longest
// path containing that node would be the path from that node to the 2 most distant leaf nodes + 2 (this requires visualization). Also, at the same time height of the node would be 1 + max_height. In case
// there is only one child then the answer would simply be the height of that node 

#include <bits/stdc++.h>
using namespace std;

int dfs(int node, int &ans, vector<int> adj[]) {
    if(adj[node].size() == 0) return 0;
    vector<int> temp;
    for(int next : adj[node]) {
        int h = dfs(next, ans, adj);
        temp.push_back(h);
    }
    sort(temp.begin(), temp.end());
    if(temp.size() == 1) {
        ans = max(ans, 1 + temp[0]);
        return 1 + temp[0];
    }
    int a = temp[temp.size() - 1];
    int b = temp[temp.size() - 2];
    ans = max(ans, a + b + 2);
    return (1 + a);
}

int solve(vector<int> &A) {
    int n = A.size();
    vector<int> adj[n];
    int root;
    for(int i=0; i<n; i++) {
        int t = A[i];
        if(t >= 0) {
            adj[t].push_back(i);
        }
        else root = i;
    }
    int ans = 0;
    dfs(root, ans, adj);
    return ans;
}

int main() {
    vector<int> A = {-1, 0, 0, 0, 3};
    cout << solve(A);
}
