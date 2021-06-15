// Explanation : Kruskal's algorithm is used to determine the minimum cost spanning tree in a graph. The algorithm is a greedy one. What we do basically is that we select the edge with the minimum
// cost, and if the addition of that edge does not create a cycle, then we insert that edge in the MST. This step is repeated until we get the complete MST.
// The edges are taken, along with the connecting nodes in a min heap, so that the selection of minimum edge is of logarithmic order. Once we remove the cheapest edge, we check whether connecting the
// 2 nodes creates a cycle or not. This can be achieved by using the union find algorithm. The union find algorithm helps us divide elements of an array into subset, where we can find the parent
// element of each element, as well as create the union of 2 subsets. A subset is represented in such a way that the parent element stores the value of -x, where x is the number of elements in that
// subset. The rest of the elements store the index of their immediate parent (we can visualise this using a tree)
//              5           1
//             /             \
//            4               6
//           / \               \
//          2   3               7
// In this case, [2,3,4,5] is a single subset, and [1,6,7] is another subset of the superset [1,2,3,4,5,6,7]. The 1-based array would look like this - [-3, 4, 4, 5, -4, 1, 6]
// Hence we can find the parent element of the subset by following the values until a negative value is reached. If we need to create the union of 2 sets, we simply attach the parent of one set to the
// parent of other as it's child. Hence the parent value of one is updated to make a size equal to -(x+y), and the value of parent of the second subset now points to the parent of first subset. We generally
// take the parent of larger subset (and hence lower value as it is negative), as the parent while finding union
// Now, in case of graphs, all the nodes that are connected can be considered to be the part of a single subset. When we connect two nodes, the we take the union of the 2 subsets because now those 2 subsets
// combine to form a single subset. Thus, if 2 nodes already have the same parent, then we know that joining them would generate a cycle, and hence we can skip those edges

#include <bits/stdc++.h>
using namespace std;

class Disjoint_set {
public:
    int n;
    vector<int> s;
    Disjoint_set(int N) {
        n = N;
        for(int i=0; i<N; i++)
            s.push_back(-1);
    }
    int find_parent(int idx) {
        while(s[idx] > 0)
            idx = s[idx];
        return idx;
    }
    void union_set(int a, int b) {
        if(s[a] < s[b]) {
            s[a] += s[b];
            s[b] = a;
        }
        else {
            s[b] += s[a];
            s[a] = b;
        }
    }
};

vector<pair<int, int>> adj[10005];
vector<pair<int, int>> edges;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
int minCost = 0;

void KruskalMST(int n) {
    Disjoint_set ds(n);
    while(!pq.empty()) {
        pair<int, pair<int, int>> p = pq.top();
        pq.pop();
        int cost = p.first;
        int node_a = p.second.first;
        int node_b = p.second.second;
        if(ds.find_parent(node_a) == ds.find_parent(node_b)) continue;
        else {
            minCost += cost;
            edges.push_back({node_a, node_b});
            if(edges.size() == n-1) return;
            node_a = ds.find_parent(node_a);
            node_b = ds.find_parent(node_b);
            ds.union_set(node_a, node_b);
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
        pq.push({w, {a, b}});
    }
    KruskalMST(n);
    cout << "Cost of minimum spanning tree : " << minCost << endl;
    for(pair<int, int> p : edges)
        cout << "Edge betweeen node " << p.first << " and node " << p.second << endl;
}
