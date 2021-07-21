// PS : Given a 3 x A board,  find the number of ways to color it using at most 4 colors such that no 2 adjacent boxes have same color. Diagonal neighbors are not treated as adjacent boxes.
// Return the ways modulo 10e9 + 7 as the answer grows quickly.
// Solution : There are 36 total triplets in which the first and second, and second and third colors are different. Now, for each column, what we can do is set the color of the column to a triplet,
// and then for the previous column, chooose only those triplets which satisfy the condition. Hence, we get a recursive relation. So we start from the rightmost column and one by one color it with
// all triplets and then go back to the previous column. If we reach the first column simply return 1 because we can go no further back

#include <bits/stdc++.h>
using namespace std;

#define inf 1000000007

struct triplet {
    int x;
    int y;
    int z;
    triplet(int _x, int _y, int _z) {
        x = _x;
        y = _y;
        z = _z;
    }
};

int dp[100005][4][4][4];

int func(int i, int j, int k, int cur, vector<struct triplet> &v) {
    if(cur == 1) return 1;
    if(dp[cur][i][j][k] != -1) return dp[cur][i][j][k];
    int ans = 0;
    for(int x=0; x<v.size(); x++) {
        triplet t = v[x];
        if(t.x != i && t.y != j && t.z != k) {
            ans += func(t.x, t.y, t.z, cur-1, v);
            ans %= inf;
        }
    }
    dp[cur][i][j][k] = ans;
    return ans;
}

int solve(int A) {
    memset(dp, -1, sizeof dp);
    vector<struct triplet> v;
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            if(j == i) continue;
            for(int k=0; k<4; k++) {
                if(k == j) continue;
                triplet t(i, j, k);
                v.push_back(t);
            }
        }
    }
    int ans = 0;
    for(triplet t : v) {
        ans += func(t.x, t.y, t.z, A, v);
        ans %= inf;
    }
    return ans;
}

int main() {
    int N;
    cin >> N;
    cout << solve(N);
}
