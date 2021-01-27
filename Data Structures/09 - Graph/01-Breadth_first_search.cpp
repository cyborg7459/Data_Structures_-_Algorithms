#include <bits/stdc++.h>
using namespace std;

int n = 0;
void bfs(vector<vector<int>> graph, int start) {
    queue<int> q;
    int visited[n+1] = {};
    q.push(start);
    cout << start << " ";
    visited[start] = 1;
    while(!q.empty()) {
        int vertex = q.front();
        q.pop();
        for(int j=1; j<=n; j++) {
            if(graph[vertex][j]==1 && visited[j]==0) {
                cout << j << " ";
                visited[j] = 1;
                q.push(j);
            }
        }
    }
}

int main() {
    n = 6;
    vector<vector<int>> graph = {
        {0,0,0,0,0,0,0},
        {0,0,1,1,0,0,0},
        {0,1,0,0,1,0,0},
        {0,1,0,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    bfs(graph, 3);
}
