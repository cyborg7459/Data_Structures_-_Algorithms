// Explanation : Basic question of BFS. BFS is used here instead of DFS as we are searching for something. We need to return as soon as we first encounter the target node. Doing DFS here would give stack
// overflow due to excessive recursion in case of large inputs

#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int dist[2005][2005];
vector<pair<int, int>> dir = {{-1,2}, {-2,1}, {-2,-1},{-1,-2},{1,2},{2,1},{1,-2},{2,-1}};

bool isValid(int x, int y, int n) {
    return (x>0 && x<=n && y>0 && y<=n);
}

void bfs(int x, int y, int tx, int ty, int n, int num) {
    queue<pair<pair<int, int>, int>> q;
    q.push({{x, y}, 0});
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        int i = p.first.first, j = p.first.second, k = p.second;
        if(i == tx && j==ty) return;
        for(auto p1 : dir) {
            int x1 = i + p1.first, y1 = j + p1.second;
            if(isValid(x1, y1, n) && dist[x1][y1] > k+1) {
                dist[x1][y1] = k+1;
                q.push({{x1, y1}, k+1});
            }
        }
    }
}

int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N) {
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            dist[i][j] = 1000000007;
        }
    }

    int sx = KnightPos[0], sy = KnightPos[1];
    int ex = TargetPos[0], ey = TargetPos[1];

    if(!isValid(sx, sy, N) || !isValid(ex, ey, N)) return -1;
    bfs(sx, sy, ex, ey, N, 0);
    return dist[ex][ey];
}

int main() {
    vector<int> v1 = {4,5}, v2 = {1,1};
    int n = 6;
    cout << minStepToReachTarget(v1, v2, n);
}
