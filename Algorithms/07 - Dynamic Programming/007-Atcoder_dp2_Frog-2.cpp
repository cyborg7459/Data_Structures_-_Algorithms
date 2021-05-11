#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000007

signed main()
{
	int n, k;
	cin >> n >> k;
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
		int temp = k, idx = i+1, best = INF;
		while(idx < n && temp--) {
			best = min(best, dp[idx] + abs(heights[idx] - heights[i]));
			idx++;
		}
		dp[i] = best;
	}
	cout << dp[0] << "\n";
}
