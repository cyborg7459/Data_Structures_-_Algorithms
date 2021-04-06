// Problem : You are given an array of binary strings strs and two integers m and n. Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
// Explanation : The wordings of the problem are like, find the maximum of something that can be obtained under the contstraint that something else does not exceed a particular value. Hence clearly,
// this problem, as well as other problems with similar wording, has an implementation like Knapsack 

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

int findMax(vector<string> &strs, int m, int n) {
	pair<int, int> dp[m+1][n+1];
	for(int i=0; i<=m; i++) {
		for(int j=0; j<=n; j++) {
			dp[i][j] = {0,0};
		}
	}
	dp[0][0] = {1, 0};
	for(int i=0; i<strs.size(); i++) {
		for(int j=m; j>=0; j--) {
			for(int k=n; k>=0; k--) {
				if(dp[j][k].first == 1) {
					int z = count(all(strs[i]), '0');
					int o = count(all(strs[i]), '1');
					if(j+z <= m && k+o <= n) {
						dp[j+z][k+o].first = 1;
						dp[j+z][k+o].second = max(dp[j+z][k+o].second, 1 + dp[j][k].second);
					}
				}
			}
		}
	}
	int ans = -1;
	for(int i=0; i<=m; i++) {
		for(int j=0; j<=n; j++) {
			cout << dp[i][j].first << "," << dp[i][j].second << " ";
			if(dp[i][j].first == 1)
				ans = max(ans, dp[i][j].second);
		}
		o("");
	}
	return ans;
}

void solve() {
	vector <string> v = {"10","0","1"};
	cout << findMax(v, 1, 1) << nl;
}

signed main()
{
    fast;
    int q = 1;
//	cin >> q;
    while(q--)
        solve();
}
