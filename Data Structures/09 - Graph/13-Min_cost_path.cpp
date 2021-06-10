// PS : In a graph where traversing through each cell has a different cost, find the minimum cost of traversing from top left to bottom right
// Explanation : This is the standard and highly important case of implementing a grid as a graph. We use the Dijkstra's algorithm for finding the minimum cost

#include<bits/stdc++.h>
using namespace std;

#define inf 1000000007

bool vis[505][505] = {};
vector<pair<int,int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool isValid(int x, int y, int n) {
    return (x>=0 && x<n && y>=0 && y<n && !vis[x][y]);
}

int minimumCostPath(vector<vector<int>>& grid) {
    int n = grid.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({grid[0][0], 0});
    int cost[n][n];
    memset(cost, inf, sizeof cost);
    cost[0][0] = grid[0][0];
    while(!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();
        int cur_cost = p.first;
        int x = (p.second)/n;
        int y = (p.second)%n;
        vis[x][y] = true;
        if(cost[x][y] < cur_cost) continue;
        for(pair<int, int> p1 : dir) {
            int x1 = x + p1.first;
            int y1 = y + p1.second;
            if(isValid(x1, y1, n)) {
                int new_cost = cur_cost + grid[x1][y1];
                if(new_cost < cost[x1][y1]) {
                    cost[x1][y1] = new_cost;
                    pq.push({new_cost, n*x1 + y1});
                }
            }
        }
    }
    return cost[n-1][n-1];
}

int main(){
	int n;
	cin >> n;
	vector<vector<int>>grid(n, vector<int>(n, -1));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> grid[i][j];
		}
	}
	int ans = minimumCostPath(grid);
	cout << ans;
}
