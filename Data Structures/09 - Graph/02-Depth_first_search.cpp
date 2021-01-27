#include <bits/stdc++.h>
using namespace std;

int n = 6;
vector<vector<int>> graph = {
    {0,0,0,0,0,0,0},
    {0,0,1,1,0,0,0},
    {0,1,0,0,1,0,0},
    {0,1,0,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0}
};

int visited[7] = {};
void dfs(int vertex) {
    cout << vertex << " ";
    visited[vertex] = 1;
    for(int i=1; i<=n; i++) {
        if(graph[vertex][i]==1 && visited[i]==0)
            dfs(i);
    }
}

int main() {
    dfs(6);
}
