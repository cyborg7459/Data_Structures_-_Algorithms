#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000007

signed main()
{
	int n;
	cin >> n;
	vector<int> heights;
	for(int i=0; i<n; i++) {
		int h;
		cin >> h;
		heights.push_back(h);
	}
	int dp[n] = {};
	dp[n-1] = 0;
	dp[n-2] = abs(heights[n-1] - heights[n-2]);
	for(int i=n-3; i>=0; i--) {
		dp[i] = min(dp[i+1] + abs(heights[i] - heights[i+1]), dp[i+2] + abs(heights[i] - heights[i+2]));
	}
	cout << dp[0] << "\n";
}
