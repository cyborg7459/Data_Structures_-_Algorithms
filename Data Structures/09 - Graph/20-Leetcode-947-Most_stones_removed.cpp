// PS : https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
// Explanation : The logic behind this solution is that all the stones that can be traversed in one DFS are connected. Hence, we start from any one stone and then keep removing the conneted stone.
// However, the last stone of the group would be left because no connected stone would be remaining. Hence, for each DFS, 1 stone is left

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> vis;
vector<int> row[10005];
vector<int> col[10005];

bool isVisited(int x, int y) {
    auto it = find(vis.begin(), vis.end(), make_pair(x, y));
    return it != vis.end();
}

void dfs(int r, int c, vector<vector<int>>& stones) {
    vis.push_back({r, c});
    for(int i : row[r]) {
        int x = stones[i][0];
        int y = stones[i][1];
        if(!isVisited(x, y)) dfs(x, y, stones);
    }
    for(int i : col[c]) {
        int x = stones[i][0];
        int y = stones[i][1];
        if(!isVisited(x, y)) dfs(x, y, stones);
    }
}

int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    for(int i=0; i<n; i++) {
        int x = stones[i][0];
        int y = stones[i][1];
        row[x].push_back(i);
        col[y].push_back(i);
    }
    int cnt = 0;
    for(int i=0; i<n; i++) {
        int x = stones[i][0];
        int y = stones[i][1];
        if(!isVisited(x, y)) {
            cnt++;
            dfs(x, y, stones);
        }
    }
    return (n - cnt);
}

int main() {
    vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    cout << removeStones(stones);
}
