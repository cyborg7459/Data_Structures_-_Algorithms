// Explanation : Prim's algorithm is a greedy algorithm, hence we take whichever is the lowest cost edge which is available and valid at the moment. By available, it means that it must
// be connected to one of the nodes which has been explored up till now, and by valid, it means that the given edge should not create a cycle in the graph.
// The algorithm goes as follows :-
// 1) We initialise a min priority_queue storing the cost of the edge, and the pair of nodes that it connects. The cost is taken first so that the minimum cost edge is popped first
// We'll store the nodes of the edge as source and destination pairs
// 2) We choose any random node we want as the source, and push all it's connected nodes in the priority_queue. The chosen node would be source and connected nodes the destination
// 3) Now we start traversing the priority_queue
// 4) Pull out the edge with the lowest cost from the priority_queue. If both the nodes of this edge have been visited, then it means that using this edge would create a cycle. Hence, ignore
// this node and continue forward
// 5) If not, then add the cost of the edge, and mark both nodes as visited. Also update the vectors if you need to keep track of the connected nodes
// 6) Now, make the destination node as the source and explore all the nodes connected to it and push them in the priority_queue. Don't push visited nodes because in that case both nodes would
// have been visited so it would be ignored later on anyway. So, pushing that node will just consume unnecessary time and space
// 7) If by the end, any node is unvisited, it means that the graph was unconnected and minimum spanning tree isn't possible

#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[10005];

int mstCost = 0;
bool vis[10005] = {};
vector<int> nextNode[10005] = {};

void PrimsMST(int source) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for(pair<int, int> p : adj[source])
        pq.push({p.second, {source, p.first}});
    while(!pq.empty()) {
        pair<int, pair<int, int>> p = pq.top();
        pq.pop();
        int node_a = p.second.first;
        int node_b = p.second.second;
        int cost = p.first;
        if(vis[node_a] && vis[node_b])
            continue;
        mstCost += cost;
        nextNode[node_a].push_back(node_b);
        vis[node_a] = true;
        vis[node_b] = true;

        for(pair<int, int> next : adj[node_b]) {
            if(vis[next.first]) continue;
            else pq.push({next.second, {node_b, next.first}});
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    for(int i=0; i<e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    PrimsMST(0);
    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            cout << "It is not possible to create a spanning tree in the given graph\n";
            return 0;
        }
    }
    cout << "The cost of the minimum spanning tree is " << mstCost << endl;
    for(int i=0; i<n; i++) {
        for(int t : nextNode[i]) {
            cout << i << " -> " << t << endl;
        }
    }
}
