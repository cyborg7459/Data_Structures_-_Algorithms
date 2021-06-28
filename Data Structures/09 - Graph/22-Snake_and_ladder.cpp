// Explanation : First of all we create an adjacency list to depict all the cells one can go from a given cell. If the current cell is the foot of a ladder of the mouth of a snake, then only one
// destination is possible, and in all other cases, we can go to the 6 next cells. Now, we start from the first cell and do dfs, visiting all cells we can while keeping track of the number of moves.
// In case we are at the mount of snake or foot of ladder, the number of moves does not increase by 1 because we directly go from there to the next node in that move only. In all other cases, the
// number of moves increases by 1

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[31];
int tries[31];
int ans = 1000000007;

void dfs(int cell, int num) {
    if(cell > 30) return;
    if(tries[cell] < num) return;
    tries[cell] = num;
    if(adj[cell].size() == 1) dfs(adj[cell][0], num);
    else {
        for(int next : adj[cell]) {
            dfs(next, num+1);
        }
    }
    return;
}

int minThrow(int N, int arr[]){
    memset(tries, 1000000007, sizeof tries);
    int idx = 0;
    for(int i=0; i<N; i++) {
        int a = arr[idx++];
        int b = arr[idx++];
        adj[a].push_back(b);
    }
    for(int i=1; i<=30; i++) {
        if(adj[i].size() == 0) {
            for(int t = i+1; t<=i+6; t++) {
                adj[i].push_back(t);
            }
        }
    }

    dfs(1, 0);
    return tries[30];
}

int main() {
    int N = 8;
    int arr[2*N] = {3, 22, 5, 8, 11, 26, 20, 29, 17, 4, 19, 7, 27, 1, 21, 9};
    cout << minThrow(N, arr);
}
