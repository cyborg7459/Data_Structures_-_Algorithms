// Theory : Floyd Warshall is a dynamic programming approach to find out the shortest distance between each pair of nodes. For this algorithm, it is preferred to represent the graph as an adjacency matrix
// rather than an adjacency list. We create a DP table of size n*n, with DP[i][j] representing the shortet distance between nodes i and j. Now, initially we just fill the values in DP table as the direct
// distance between node i and j. After this, we loop all nodes from 0 to n, and one by one mae that node an intermediate node for all paths, and see if that  improves the distance, i.e. for every node 'k',
// we check for every pair (i, j) that whether the distance between i and j decreases if we reduce if instead of going directly from i to j, we went from i to k and then k to j (this i to k and k to k themselves
// might also have branching)
// The second loop helps us determine the presence of negative cycles.
// IMPORTANT NOTE : In Bellman Ford, we were checking just for actual edges, while in Floyd Warshall, we are checking for all possible edges, even if those edges do not exist. Hence, we need actual infinity instead
// of a very large number, so that the value never changes (i.e. 1000000007 - 30 < 1000000007 would return true, but in case of infinity this should not happen). Hence, we need to continue in case we encounter infinity,
// else we'll get incorrect results and each node would seem to be in a nagative cycle even if a single negative cost edge is there

#include <bits/stdc++.h>
using namespace std;
#define inf 1000000007

vector<vector<int>> FloydWarshall(vector<vector<int>> & adj, int n) {
    vector<vector<int>> dp;
    for(int i=0; i<n; i++) {
        vector<int> temp;
        for(int j=0; j<n; j++) {
            temp.push_back(adj[i][j]);
        }
        dp.push_back(temp);
    }
    for(int k=0; k < n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(dp[i][k] == inf || dp[k][j] == inf) continue;
				if(dp[i][k] + dp[k][j] < dp[i][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }
    for(int k=0; k < n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(dp[i][k] == inf || dp[k][j] == inf) continue;
				if(dp[i][k] + dp[k][j] < dp[i][j]) {
                    dp[i][j] = -1 * inf;
                }
            }
        }
    }
    return dp;
}

int main() {
    vector<vector<int>> adj = {
        {0, 20, inf, inf, inf, inf, inf, inf},
        {inf, 0, 40, inf, inf, inf, inf, inf},
        {inf, inf, 0, 30, 10, inf, inf, inf},
        {inf, -100, inf, 0, inf, inf, inf, inf},
        {inf, inf, inf, inf, 0, 30, 70, 20},
        {inf, inf, inf, inf, inf, 0, inf, inf},
        {inf, inf, inf, inf, inf, inf, 0, inf},
        {inf, inf, inf, inf, inf, inf, 30, 0}
    };
    int n = adj.size();
    vector<vector<int>> dist = FloydWarshall(adj, n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(dist[i][j] == inf) cout << "* ";
            else if(dist[i][j] == -1*inf) cout << "# ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
