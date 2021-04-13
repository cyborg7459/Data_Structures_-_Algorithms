// PS : https://leetcode.com/problems/dungeon-game/
// Explanation : In this problem, for each position in array, we have to calculate the minimum health needed to reach the bottom right from that point. Also, this minimum health should
// always be more than 0, hence there is the added step that even if the health required is less than zero, increase it to 1

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define nl "\n"
#define loop(i,n) for(long long i=0;i<n;i++)
#define print(x) {for(auto t : x)\
                            cout << t << " ";\
                            cout << "\n";}
#define all(x) x.begin(), x.end()
#define o(x) cout << x << "\n"
#define fast ios_base::sync_with_stdio(false);\
                     cin.tie(NULL);
#define INF 1000000007

int calculateMinimumHP(vector<vector<int>>& dungeon) {
	int m = dungeon.size();
	int n = dungeon[0].size();
	int dp[m][n];
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			dp[i][j] = INF;
		}
	}
	if(dungeon[m-1][n-1] > 0)
		dp[m-1][n-1] = 1;
	else
		dp[m-1][n-1] = abs(dungeon[m-1][n-1]) + 1;
	for(int i=m-1; i>=0; i--) {
		for(int j=n-1; j>=0; j--) {
			if(i+1 < m && dp[i+1][j] - dungeon[i][j] < dp[i][j])
				dp[i][j] = dp[i+1][j] - dungeon[i][j];
			if(j+1 < n && dp[i][j+1] - dungeon[i][j] < dp[i][j])
				dp[i][j] = dp[i][j+1] - dungeon[i][j];
			if(dp[i][j] <= 0)
				dp[i][j] = 1;
		}
	}
	return dp[0][0];
}

void solve() {
	vector<vector<int>> grid = {{5,23,-48,-21,-72,-62,-19,-55,-3,-93,-84,14,-34,46,-82,-46,39,26,47,-71,-46,-3,-59,-93,-13,-72,19,-43,-51,-2,-6,-53,12,-40,15,-94,37,-3,-32,-97}};
	cout << calculateMinimumHP(grid) << "\n";
}

signed main()
{
    fast;
    int q = 1;
//	cin >> q;
    while(q--)
        solve();
}
