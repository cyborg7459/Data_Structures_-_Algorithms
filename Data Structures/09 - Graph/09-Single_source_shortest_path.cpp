// Explanation : The given algorithm is used to calculate the minimum distance of all nodes from the source in a directed acyclic graph.
// For this, we first need the topologicalSort of the given graph, starting from the required source (in case there are more than 1 independent sources, start from the one which we require here).
// Now for all the nodes in order of the topologicalSort, we traverse to all the nodes connected to it (no DFS, just the immediate neighbours) and update the distance in the answer array to minimum
// (the values are initially set to infinite).
// In case we have multiple sources, then we need to ensure that the required node is first used. Hence, it should come first in the topologicalSort, and hence, it should be taken last while
// calculating the topologicalSort (since the vector is reversed later)

#include <bits/stdc++.h>
using namespace std;
#define inf 1000000007

vector<pair<int, int>> adj[101] = {{}};

bool vis[101] = {};

void dfs(int cur, vector<int> &v) {
    vis[cur] = 1;
    for(pair<int, int> node : adj[cur]) {
        if(!vis[node.first]) {
            dfs(node.first, v);
        }
    }
    v.push_back(cur);
}

vector<int> topologicalSort(int N, int source) {
    vector<int> v = {};
    for(int i=1; i<=N; i++) {
        if(i == source) continue;
        if(!vis[i]) {
            dfs(i, v);
        }
    }
    dfs(source, v);
    reverse(v.begin(), v.end());
    return v;
}

vector<int> singleSourceShortestPath(vector<int> topSort, int n) {
    vector<int> ans(n + 1, inf);
    int start = topSort[0];
    ans[start] = 0;
    for(int i = 0; i < n; i++) {
        int num = topSort[i];
        for(pair<int, int> p : adj[num]) {
            int node = p.first;
            int weight = p.second;
            ans[node] = min(ans[node], ans[num] + weight);
        }
    }
    return ans;
}

int main() {
    int n, e;
    cin >> n >> e;

    for(int i=0; i<e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    vector<int> topSort = topologicalSort(n, 1);
    vector<int> ans = singleSourceShortestPath(topSort, n);

    cout << "Minimum distance from source :-\n";
    for(int i=1; i<=n; i++) {
        cout << "Node " << i << " : " << ans[i];
        cout << endl;
    }
}
