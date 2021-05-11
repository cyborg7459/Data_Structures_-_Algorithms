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

signed main()
{
    int n;
	cin >> n;
	int dp[n+1];
	for(int i=10; i<=n; i++)
		dp[i] = INF;
	for(int i=0; i<=9 && i<=n; i++)
		dp[i] = 1;
	for(int i=10; i<=n; i++) {
		int temp = i;
		while(temp > 0) {
			int k = temp % 10;
			temp /= 10;
			if(k > 0)
				dp[i] = min(dp[i], 1 + dp[i-k]);
		}
	}
	o(dp[n]);
}
