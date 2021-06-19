// Kosraraju Algorithm is used to detect strongly connected components in a graph. The principle behind this algorithm is that if there is an edge between 2 Strongly connected components, then we can
// traverse all nodes of the 2nd SCC starting from any node in the first SCC. However, if all edges in the graph were to be reversed, then now if we start from any node in the first SCC, we'll still
// be able to reach all nodes of that SCC, but won't be able to reach any node of the 2nd SCC. Hence, the property is that reversal of all edges does not affect traversal within an SCC, but does affect
// traversal between non-SCC.
// We need 2 DFS and a reversal step for Kosaraju. First, we visit all nodes of the graph using DFS, pushing nodes in the stack during return time. Now we find the transpose graph by reversing the edges
// and start DFS again for nodes from the stack one by one. Starting from any node, all the nodes that we can reach now belong to the same SCC. If the DFS stops and we have to start another DFS for the
// next element in stack, it means that we are now in a different SCC
// Since both the dfs as well as the reversal step all are separate, hence the time complexity of Kosraraju algorithm is O(V+E)

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
vector<int> rev[100005];

stack<int> st;
bool vis[100005];

void generateTranspose(int n) {
    for(int node=0; node<n; node++) {
        for(int next : adj[node]) {
            rev[next].push_back(node);
        }
    }
}

void dfs1(int node) {
    vis[node] = true;
    for(int next : adj[node]) {
        if(!vis[next]) dfs1(next);
    }
    st.push(node);
}

void dfs2(int node) {
    vis[node] = true;
    cout << node << " ";
    for(int next : rev[node]) {
        if(!vis[next]) dfs2(next);
    }
}

void Kosaraju(int n) {
    for(int i=0; i<n; i++)
        if(!vis[i]) dfs1(i);

    generateTranspose(n);
    memset(vis, false, sizeof vis);

    cout << "Strongly connected components are :-\n";
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if(!vis[node]) {
            dfs2(node);
            cout << "\n";
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    for(int i=0; i<e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    memset(vis, false, sizeof vis);
    Kosaraju(n);
}
