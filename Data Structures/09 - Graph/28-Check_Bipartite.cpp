// PS : Check whether a graph is bipartite or not. A bipartite graph is one in which the nodes can be divided into 2 disjoint sets u and v in such a way that every edge connects a node from u to v
// Explanation : This is basically the m-coloring problem with m = 2, as we can place all the nodes with one color in one set and vice-versa. Since 2 connected nodes can never be of the same color, hence all
// edges would connect a node from set 1 to set 2

#include <bits/stdc++.h>
using namespace std;

bool canColor(int node, int c, vector<int>&color, vector<int> adj[]) {
    for(int next : adj[node]) {
        if(color[next] == c) return false;
    }
    return true;
}

bool dfs(int node, vector<bool> &vis, vector<int>&color, vector<int> adj[]) {
    vis[node] = true;
    for(int i=0; i<2; i++) {
        if(canColor(node, i, color, adj)) {
            color[node] = i;
            bool b = true;
            for(int next : adj[node]) {
                if(!vis[next]) b = b && dfs(next, vis, color, adj);
            }
            if(b) return true;
            else color[node] = -1;
        }
    }
    return false;
}

bool isBipartite(int V, vector<int>adj[]){
    vector<bool> vis(V, false);
    vector<int> color(V, -1);
    bool ans = true;
    for(int i=0; i<V; i++) {
        ans = ans && dfs(i, vis, color, adj);
        if(!ans) return false;
    }
    return ans;
}

int main() {
    int V, e;
    cout << "Enter number of nodes : ";
    cin >> V;
    bool graph[101][101] = {};
    cout << "Enter number of edges : ";
    cin >> e;
    for(int i=0; i<e; i++) {
        cout << "Enter nodes of edge " << i + 1 << " (Value lies b/w 0 to 100) : ";
        int a, b;
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }
    bool b = graphColoring(graph, 2 ,V);
    cout << boolalpha << b;
}
