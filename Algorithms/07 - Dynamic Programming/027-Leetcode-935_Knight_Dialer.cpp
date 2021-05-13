// PS : https://leetcode.com/problems/knight-dialer/
// Explanation : For each key, we know which keys we can move to next, and thus we can create a 2-D DP array where dp[i][j] represents the number of possible
// outcomes if we're currently on key 'i' and have 'j' steps left 

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000007

int numbersCount(int cur_no, int steps_left, vector<vector<int>> &v, vector<vector<int>> &dp) {
	if(dp[cur_no][steps_left] > -1) return dp[cur_no][steps_left];
	if(steps_left == 1) return 1;
	int ans = 0;
	for(auto num : v[cur_no]) {
		ans += numbersCount(num, steps_left-1, v, dp);
		ans %= INF;
	}
	dp[cur_no][steps_left] = ans;
	return ans;
}

signed main()
{
	int n = 3131;
	vector<vector<int>> v = {{4,6},{6,8},{7,9},{4,8},{3,9,0},{},{1,7,0},{6,2},{1,3},{4,2}};
	vector<vector<int>> dp;
	for(int i=0; i<10; i++) {
		vector<int> temp;
		for(int j=0; j<=n; j++) {
			temp.push_back(-1);
		}
		dp.push_back(temp);
	}
	int ans = 0;
	for(int i=0; i<10; i++) {
		ans += numbersCount(i, n, v, dp);
		ans %= INF;
	}
	cout << ans << endl;
}
