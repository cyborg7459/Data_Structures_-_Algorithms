// Dijksrta's algorithm is used to find the shortest path from the source node to each node in the graph.
// It works in O((n+e)logn) time
// Dijkstra's is based on the principle that once we visit a given node, we definitely put in its minimum value. Hence, this algorithm fails when the edges have negative values (if we remove
// the visited array then we can get correct answer, but that would decrease the efficiency of the algorithm)
// How we can say that once the node is visited, it is definitely the correct answer : Suppose we have an element waiting in the queue, if there is some other path better than that path in the
// queue, then definitely it will be added into the queue before that element is accessed. Not only that, it would be accessed first after addition as well since the priority_queue is
// implemented in such a way that shorter paths are popped off first.

#include <bits/stdc++.h>
using namespace std;
#define inf 1000000007
vector<pair<int, int>> adj[101];
bool vis[101] = {};

vector<int> Dijkstras(int source, int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n+1, inf);
    dist[source] = 0;
    pq.push({0, source});
    while(!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        int cur_dist = cur.first, cur_node = cur.second;
        vis[cur_node] = true;
        if(dist[cur_node] < cur_dist) continue;
        for(pair<int, int> node : adj[cur_node]) {
            if(vis[node.first]) continue;
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
