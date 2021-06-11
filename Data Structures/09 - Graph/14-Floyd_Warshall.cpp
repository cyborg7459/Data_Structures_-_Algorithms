// Theory : Floyd Warshall is a dynamic programming approach to find out the shortest distance between each pair of nodes. For this algorithm, it is preferred to represent the graph as an adjacency matrix
// rather than an adjacency list. We create a DP table of size n*n, with DP[i][j] representing the shortet distance between nodes i and j. Now, initially we just fill the values in DP table as the direct
// distance between node i and j. After this, we loop all nodes from 0 to n, and one by one mae that node an intermediate node for all paths, and see if that  improves the distance, i.e. for every node 'k',
// we check for every pair (i, j) that whether the distance between i and j decreases if we reduce if instead of going directly from i to j, we went from i to k and then k to j (this i to k and k to k themselves
// might also have branching)

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
				cout << "Checking for (" << i << "," << j << ")\n";
				int a = dp[i][j];
				cout << "Direct path : " << a << "\n";
				int b = dp[i][k];
				int c = dp[k][j];
				cout << "Path through " << k << " : " << b << " + " << c << " = " << b+c << endl;
				int x = min(a, b+c);
				cout << "Value set to " << x << endl << endl;
                dp[i][j] = x;
            }
        }
    }
    return dp;
}

int main() {
    vector<vector<int>> adj = {
        {0, 80, inf, 500},
        {inf, 0, 20, 100},
        {inf, inf, 0, 30},
        {inf, inf, inf, 0}
    };
    int n = adj.size();
    vector<vector<int>> dist = FloydWarshall(adj, n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(dist[i][j] == inf) cout << "* ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
