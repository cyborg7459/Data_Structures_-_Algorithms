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
	int n, w;
	cin >> n >> w;
	pair<int, int> dp[100001], arr[n];
	for(int i=0; i<n; i++) {
		int a, b;
		cin >> a >> b;
		arr[i] = {a, b};
	}
	for(int i=0; i<=100000; i++) {
		dp[i].first = 0;
		dp[i].second = INF;
	}
	dp[0] = {1, 0};
	for(int i = 0; i <= n; i++) {
		for(int x = 100000; x>=0; x--) {
			if(dp[x].first == 1 && x + arr[i].second <= 100000) {
				dp[x + arr[i].second].first = 1;
				dp[x + arr[i].second].second = min(dp[x + arr[i].second].second, dp[x].second + arr[i].first);
			}
		}
	}
	for(int i=100000; i>=0; i--) {
		if(dp[i].first == 1 && dp[i].second <= w) {
			o(i);
			return;
		}
	}
}

signed main()
{
    fast;
    int q = 1;
    while(q--)
        solve();
}
