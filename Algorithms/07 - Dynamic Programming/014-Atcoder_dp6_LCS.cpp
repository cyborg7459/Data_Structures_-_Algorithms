// In problems regarding subsets, a useful approach to follow is take 2 scenarios for each element - whether we choose it, or we don't choose it - and then proceed with whichever one's more optimal
// for our solution. For example in this problem we've taken the maximum of all 3 scenarios, i.e. we don't choose element from string1, we don't choose elemet from string2, we choose both elements.
// The choices array helps in keeping track of our choices, i.e. whether we did pick that element or not which later helps us contruct back the required string

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

int dp[3000][3000];
int choices[3000][3000];

void solve() {
	string s, t;
	cin >> s >> t;
	dp[0][0] = 0;
	if(s[0] == t[0]) {
		dp[0][0] = 1;
		choices[0][0] = 2;
	}
	for(int i=0; i<s.length(); i++) {
		for(int j=0; j<t.length(); j++) {
			if(i > 0) {
				dp[i][j] = dp[i-1][j];
				choices[i][j] = 0;
			}
			if(j > 0) {
				if(dp[i][j-1] > dp[i][j]) {
					dp[i][j] = dp[i][j-1];
					choices[i][j] = 1;
				}
			}
			if(s[i] == t[j]) {
				int ans = 1;
				if(i > 0 && j > 0) {
					ans = 1 + dp[i-1][j-1];
				}
				if(ans > dp[i][j]) {
					dp[i][j] = ans;
					choices[i][j] = 2;
				}
			}
		}
	}
	string res;
	int i = s.length()-1, j = t.length()-1;
	while(i >= 0 && j >= 0) {
		if(choices[i][j] == 0) i--;
		else if(choices[i][j] == 1) j--;
		else if(choices[i][j] == 2) {
			res.pb(s[i]);
			i--;
			j--;
		}
	}
	reverse(all(res));
	o(res);
}

signed main()
{
    fast;
    int q = 1;
//	cin >> q;
    while(q--)
        solve();
}
