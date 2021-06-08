#include <bits/stdc++.h>
using namespace std;
#define inf 1000000007
vector<pair<int, int>> adj[101];
bool vis[101] = {};

pair<vector<int>, vector<int>> Dijkstras(int source, int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n+1, inf);
    vector<int> prev(n+1, -1);
    dist[source] = 0;
    pq.push({0, source});
    while(!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        int cur_dist = cur.first, cur_node = cur.second;
        if(vis[cur_node]) continue;
        vis[cur_node] = true;
        if(dist[cur_node] < cur_dist) continue;
        for(pair<int, int> node : adj[cur_node]) {
            int new_dist = cur_dist + node.second;
            if(new_dist < dist[node.first]) {
                dist[node.first] = new_dist;
                prev[node.first] = cur_node;
                pq.push({new_dist, node.first});
            }
        }
    }
    return {dist, prev};
}

int main() {
    int n, e;
    cin >> n >> e;
    for(int i=0; i<e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    pair<vector<int>, vector<int>> p = Dijkstras(1, n);
    vector<int> ans = p.first;
    vector<int> prev = p.second;
    cout << "Shortest distanct from source :-\n";
    for(int i=1; i<=n; i++) {
        cout << "Node " << i << " : " << ans[i] << endl;
        vector<int> path;
        path.push_back(i);
        int k = prev[i];
        while(k != -1) {
            path.push_back(k);
            k = prev[k];
        }
        reverse(path.begin(), path.end());
        cout << "Path : ";
        for(int t : path) cout << t << " ";
        cout << endl << endl;
    }
}
