// Explanation : The logic behind this solution is that in DFS, if we're exploring one partiuclar node and in the process of exploring we reach back that node again, it means that there is a cycle
// in the given graph. Hence, we keep a boolean vector isOnStack to keep track of the nodes which are currently present in the recursion stack. If any such stack is visted again, it means that there
// must be a cycle. This method also detects self loops as a cycle. Once we've explored all the connected nodes of a given node, then it is popped off the stack and hence we can set the value to
// false again
// NOTE : The given method cannot be used to determine which elements belong in a cycle. This is because if a connected node of a node is in a cycle, then also the function returns true. Hence this can
// be used to determine wheteher a node lies in a path which contains a cycle somewhere (not necessarily including that node)
// This concept has been used in Leetcode problem 802 (https://leetcode.com/problems/find-eventual-safe-states/)

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];

bool isInCycle(int node, vector<bool> &vis, vector<bool> &isOnStack) {
    vis[node] = true;
    isOnStack[node] = true;

    for(int next : adj[node]) {
        if(!vis[next]) {
            if(isInCycle(next, vis, isOnStack)) return true;
        }
        else if(isOnStack[next]) return true;
    }

    isOnStack[node] = false;
    return false;
}

int main() {
    int n, e;
    cout << "Enter number of nodes : ";
    cin >> n;
    cout << "Enter number of edges : ";
    cin >> e;
    for(int i=0; i<e; i++) {
        cout << "Enter edge " << i+1 << " : ";
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<bool> vis(n, false);
    vector<bool> isOnStack(n, false);
    for(int i=0; i<n; i++) {
        if(isInCycle(i, vis, isOnStack)) {
            cout << "Cycle detected\n";
            return 0;
        }
    }
    cout << "No cycle detected\n";
    return 0;
}
