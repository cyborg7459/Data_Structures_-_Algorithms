// PS : To find the minimum number of square numbers needed such that their sum is equal to the given number

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

int numSquares(int n) {
    vector<int> dp(n+1, INF);
    dp[0] = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j*j<=n; j++) {
            if(j*j > i) break;
            else dp[i] = min(dp[i], 1 + dp[i - j*j]);
        }
    }
    return dp[n];
}

void solve() {
	cout << numSquares(9999) << nl;
}

signed main()
{
    fast;
    int q = 1;
//	cin >> q;
    while(q--)
        solve();
}
