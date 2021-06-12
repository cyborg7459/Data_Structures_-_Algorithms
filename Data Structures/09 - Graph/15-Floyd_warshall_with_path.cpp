#include <bits/stdc++.h>
using namespace std;
#define inf 1000000007

pair<vector<vector<int>>, vector<vector<int>>> FloydWarshall(vector<vector<int>> & adj, int n) {
    vector<vector<int>> dp;
    vector<vector<int>> next;
    for(int i=0; i<n; i++) {
        vector<int> temp, temp1;
        for(int j=0; j<n; j++) {
            temp1.push_back(j);
            temp.push_back(adj[i][j]);
        }
        next.push_back(temp1);
        dp.push_back(temp);
    }
    for(int k=0; k < n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(dp[i][k] == inf || dp[k][j] == inf) continue;
				if(dp[i][k] + dp[k][j] < dp[i][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                    next[i][j] = k;
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
                    next[i][j] = -1;
                }
            }
        }
    }
    return {dp, next};
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
    pair<vector<vector<int>>, vector<vector<int>>> p = FloydWarshall(adj, n);
    vector<vector<int>> dist = p.first;
    vector<vector<int>> next = p.second;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << "Path b/w " << i << " and " << j << " : ";
            if(dist[i][j] == -1 * inf) cout << "Negative cycle. Cost of path is negative infinity";
            else if(dist[i][j] == inf) cout << "No path possible";
            else {
                cout << dist[i][j] << " cost : ";
                int t = i;
                while(t != j) {
                    cout << t << "->";
                    t = next[t][j];
                }
                cout << "Destination";
            }
            cout << endl;
        }
        cout << endl;
    }
}
