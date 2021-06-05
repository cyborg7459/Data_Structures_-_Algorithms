// PS : Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat
// can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the
// matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time.

// Explanation : A very basic implementation of backtracking problem, where we move to one of the 4 directions, check all the possible paths from there and then track
// back to check for other directions. The base cases are important here, i.e. we need to have (0,0) marked as visited before starting the recursion, and that the origin
// can be invalid as well so that needs to be checked

#include <bits/stdc++.h>
using namespace std;

vector<string> ans;
bool vis[5][5];

vector<pair<pair<int, int>, char>> dir = {{{1,0}, 'D'}, {{-1,0}, 'U'}, {{0,1}, 'R'}, {{0,-1}, 'L'}};

bool isValid(int x, int y, int r, int c, vector<vector<int>> &v) {
    return (x >=0 && x < r && y >= 0 && y < c && v[x][y] == 1);
}

void pathFinder(int x, int y, int r, int c, string cur, vector<vector<int>> &v) {
    if(x == r-1 && y == c-1) {
        ans.push_back(cur);
        return;
    }
    for(auto p : dir) {
        int i = x + p.first.first;
        int j = y + p.first.second;
        if(isValid(i,j,r,c,v)) {
            if(!vis[i][j]) {
                vis[i][j] = true;
                cur.push_back(p.second);
                pathFinder(i, j, r, c, cur, v);
                cur.pop_back();
                vis[i][j] = false;
            }
        }
    }
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            vis[i][j] = false;
        }
    }
    string cur = "";
    vis[0][0] = true;
    if(isValid(0,0,n,n,m))
        pathFinder(0,0,n,n,cur,m);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<vector<int>> v = {
        {1,1,1,1},
        {0,1,1,1},
        {1,1,1,1},
        {1,1,0,1}
    };
    vector<string> v1 = findPath(v, 4);
    for(string s : v1)
        cout << s << " ";
}
