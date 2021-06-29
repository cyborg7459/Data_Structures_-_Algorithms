// PS : https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/oliver-and-the-game-3/
// Explanation : Here the brute force solution would be to check whether the source lies between the origin and destination in case we move away from origin, or whether the destination lies between source and origin in case we move
// towards the origin. We can easily find the path using BFS. However, under the given constraints, this method would lead to TLE. Now, since the paths are all unique, i.e. there are no 2 ways of reaching a particular node,
// we can also use DFS. Hence, we use DFS and calculate the time of entering and exiting DFS for all nodes. What this does is that if the times for node 2 lies completely in between the times for node1, it would mean that
// node2 lies in the subtree of node 1. When moving away from origin, for a node we can reach all nodes in subtree, and when moving away from origin, we can reach all ancestors. Hence we can check accordingly in O(1)

#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int enter[100005];
int exitTime[100005];
bool vis[100005];

int timer = 0;

void dfs(int node) {
    vis[node] = true;
    enter[node] = timer;
    timer++;
    for(int next : adj[node]) {
        if(!vis[next]) dfs(next);
    }
    exitTime[node] = timer++;
}

bool func(int a, int b) {
    return (enter[a] < enter[b] && exitTime[a] > exitTime[b]);
}

int main() {
	int n;
	scanf("%d\n", &n);
	for(int i=0; i<n-1; i++) {
		int a, b;
		scanf("%d%d\n", &a, &b);
		adj[a].push_back(b);
	}
    dfs(1);
    int q;
    scanf("%d\n",&q );
    while(q--) {
        bool flag;
        int a, b, c;
        scanf("%d%d%d",&a, &b, &c);
        if(a == 0) flag = func(b, c);
        else flag = func(c, b);
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
}
