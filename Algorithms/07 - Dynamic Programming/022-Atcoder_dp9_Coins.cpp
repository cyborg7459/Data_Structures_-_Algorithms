// Logic : dp[i][j] stores the probability of getting 'j' heads if 'i' coins are tossed. Thus the base case is dp[0,0] = 1. After that, for each (i,j), the value
// of probability would be dp[i-1][j-1] * P(i) + dp[i-1][j] * P'(i), i.e. if there are j-1 heads in i-1 tosses and heads in the the ith toss, or there being j heads
// in i-1 tosses and then the jth toss being tails

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000007

signed main()
{
	cout << fixed << setprecision(12);
	int n;
	cin >> n;
	double prob[n];
	for(int i=0; i<n; i++)
		cin >> prob[i];
	double dp[n+1][n+1] = {};
	for(int i=0; i<=n; i++)
		dp[0][i] = 0;
	dp[0][0] = 1;
	double prod = 1;
	for(int i=1; i<=n; i++) {
		prod *= (1 - prob[i-1]);
		dp[i][0] = prod;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(j > i) dp[i][j] = 0;
			else {
				double p = prob[i-1];
				dp[i][j] = p * dp[i-1][j-1] + (1-p)*dp[i-1][j];
			}
		}
	}
	double ans = 0;
	for(int i = n/2 + 1; i<=n; i++) {
		ans += dp[n][i];
	}
	cout << ans << "\n";
}
