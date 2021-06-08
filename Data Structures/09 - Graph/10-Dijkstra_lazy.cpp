#include <bits/stdc++.h>
using namespace std;
#define inf 1000000007
vector<pair<int, int>> adj[101];

vector<int> Dijkstras(int source, int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n+1, inf);
    dist[source] = 0;
    pq.push({0, source});
    while(!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        int cur_dist = cur.first, cur_node = cur.second;
        if(dist[cur_node] < cur_dist) continue;
        for(pair<int, int> node : adj[cur_node]) {
            int new_dist = cur_dist + node.second;
            if(new_dist < dist[node.first]) {
                dist[node.first] = new_dist;
                pq.push({new_dist, node.first});
            }
        }
    }
    return dist;
}

int main() {
    int n, e;
    cin >> n >> e;
    for(int i=0; i<e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    vector<int> ans = Dijkstras(1, n);
    cout << "Shortest distanct from source :-\n";
    for(int i=1; i<=n; i++) {
        cout << "Node " << i << " : " << ans[i] << endl;
    }
}
