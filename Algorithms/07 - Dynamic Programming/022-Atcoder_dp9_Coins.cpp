// Logic : dp[i][j] stores the probability of getting 'j' heads if 'i' coins are tossed. Thus the base case is dp[0,0] = 1. After that, for each (i,j), the value
// of probability would be dp[i-1][j-1] * P(i) + dp[i-1][j] * P'(i), i.e. if there are j-1 heads in i-1 tosses and heads in the the ith toss, or there being j heads
// in i-1 tosses and then the jth toss being tails

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define nl "\n"
#define int long long
#define loop(i,n) for(long long i=0;i<n;i++)
#define print(x) {for(auto t : x)\
                            cout << t << " ";\
                            cout << "\n";}
#define all(x) x.begin(), x.end()
#define o(x) cout << x << "\n"
#define fast ios_base::sync_with_stdio(false);\
                     cin.tie(NULL);
#define INF 1000000007

void solve() {
	int n;
	cin >> n;
	vector<double> prob;
	loop(i, n) {
		double d;
		cin >> d;
		prob.pb(d);
	}
	double dp[n+1][n+1] = {};
	dp[0][0] = 1;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=i; j++) {
			double p = 0;
			if(i != j) {
				double d1 = dp[i-1][j];
				double d2 = 1 - prob[i-1];
				p += (d1*d2);
			}
			if(j-1 >=0) {
				double d1 = dp[i-1][j-1];
				double d2 = prob[i-1];
				p += (d1*d2);
			}
			dp[i][j] = p;
		}
	}
	double ans = 0;
	for(int i=ceil((double)n/2); i<=n; i++) {
		ans += dp[n][i];
	}
	cout << setprecision(12) << ans << nl;
}

signed main()
{
    fast;
    int q = 1;
//	cin >> q;
    while(q--)
        solve();
}
