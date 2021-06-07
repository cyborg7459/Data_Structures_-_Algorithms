// Explanation : Topological sort means sorting the nodes of a Directed Acyclic Graph (Topological sort is not possible in a cyclic graph) in such a manner that before visiting any node of the
// graph, we compulsarily visit all the nodes that which are pointing towards that node. A real-world example of this situation is that before running any file, we first need to run all the
// dependancies. The dependancies may have dependancies of their own, and those dependancies may yet still have more, and so on. We know that the file would not run if all the dependancies are
// not yet installed. Hence, Topological sort gives the order in which the files must be run so that we never face error. Topological sort in NOT unique
// We can arrange nodes in Topological sort by applying dfs on the nodes, but adding them on the way back, unlike normal DFS. At the end, we also need to reverse the vector as the stated DFS returns
// the Topological sort in a reverse order
// Time complexity of Topological sort is O(N + E) because we visit each node just once and move through each edge only once
// Space complexity is simply O(N) as of normal DFS

#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
bool vis[10005] = {};

void dfs(int cur, vector<int> adj[]) {
    vis[cur] = 1;
    for(int node : adj[cur]) {
        if(!vis[node]) dfs(node, adj);
    }
    ans.push_back(cur);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    for(int i=0; i<V; i++) {
        if(!vis[i]) dfs(i, adj);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int N, E;
    cin >> E >> N;
    int u, v;

    vector<int> adj[N];

    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector <int> res = topoSort(N, adj);
    for(int t : res)
        cout << t << " ";
    return 0;
}
