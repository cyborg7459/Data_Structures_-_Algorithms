// BellmanFord algorithm is used in the case negative cycles are present in the graph, or even in acyclic graphs in some special cases where due to negative weights of paths, Dijkstra's algorithm cannot find the
// minimum possible path. In BellmanFord, we traverse through all edges 'n' times, while updating the dist array every time. After this, we repeat the process. If a better path is found for a given node during
// the second time, it means that it is in a negative cycle and hence the value would be negative infinity
// Time complexity for BellmanFord is clearly O(n*e) and the space complexity is O(n)

#include <bits/stdc++.h>
using namespace std;
#define inf 1000000007

vector<pair<int, int>> adj[105];

vector<int> BellmanFord(int n, int e, int source) {
    vector<int> dist(n, inf);
    dist[source] = 0;
    for(int cnt = 0; cnt < n; cnt++) {
        for(int i=0; i<n; i++) {
            for(pair<int, int> p : adj[i]) {
                int node = p.first;
                int distance = p.second;
                dist[node] = min(dist[node], dist[i] + distance);
            }
        }
    }
    for(int cnt = 0; cnt < n; cnt++) {
        for(int i=0; i<n; i++) {
            for(pair<int, int> p : adj[i]) {
                int node = p.first;
                int distance = p.second;
                if(dist[i] + distance < dist[node])
                    dist[node] = -1 * inf;
            }
        }
    }
    return dist;
}

int main() {
    int n, e;
    cin >> n >> e;
    for(int i = 0; i < e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    vector<int> distances = BellmanFord(n, e, 0);
    for(int t : distances)
        cout << t << " ";
    cout << endl;
}
