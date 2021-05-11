#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000007

signed main()
{
	int n, capacity;
	cin >> n >> capacity;
	pair<int, int> weights[n], dp[capacity+1] = {};
	for(int i=0; i<n; i++) {
		int w, v;
		cin >> w >> v;
		weights[i] = {w, v};
	}
	dp[0].first = 1;
	dp[0].second = 0;
	for(int i=0; i<n; i++) {
		for(int j = capacity; j>=0; j--) {
			if(j-weights[i].first >=0 && dp[j - weights[i].first].first == 1) {
				dp[j].first = 1;
				dp[j].second = max(dp[j].second, weights[i].second + dp[j - weights[i].first].second);
			}
		}
	}

	int mx = 0;
	for(int i=0; i<=capacity; i++) {
		if(dp[i].first==1 && dp[i].second > mx)
			mx = dp[i].second;
	}

	cout << mx << "\n";
}
