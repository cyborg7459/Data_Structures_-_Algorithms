#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000007

signed main()
{
	int n, cap;
	cin >> n >> cap;
	int wts[n];
	int val[n];
	int max_val = 0;
	for(int i=0; i<n; i++) {
		cin >> wts[i];
		cin >> val[i];
		max_val += val[i];
	}

	pair<int, int> dp[max_val+1];
	dp[0].first = 1;
	dp[0].second = 0;
	for(int i=1; i<=max_val; i++) {
		dp[i].first = 0;
		dp[i].second = INF;
	}

	for(int i=0; i<n; i++) {
		for(int j = max_val; j>=0; j--) {
			if(j - val[i] >=0 && dp[j-val[i]].first == 1) {
				dp[j].first = 1;
				dp[j].second = min(dp[j].second, wts[i] + dp[j - val[i]].second);
			}
		}
	}

	for(int i = max_val; i>=0; i--) {
		if(dp[i].first == 1 && dp[i].second <= cap) {
			cout << i << "\n";
			return 0;
		}
	}

}
