// Method of counting squares in a matrix is that for each element which is a 1, check the element to the left, top and top-left. The size of the square formed
// by taking the current element as bottom right vertex would then be equal to 1 more than the minimum sized square formed by the other 3 elements.

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

int maximalSquare(vector<vector<int>> &dp) {
	int ans = 0;
	int r = dp.size(), c = dp[0].size();
	for(int i=1; i<r; i++) {
		for(int j=1; j<c; j++) {
			if(dp[i][j] == 1)
				dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
		}
	}
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(dp[i][j] > ans)
				ans = dp[i][j];
		}
	}
	return ans*ans;
}

void solve() {
	vector<vector<int>> v = {{1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}};
	cout << maximalSquare(v) << nl;
}

signed main()
{
    fast;
    int q = 1;
//	cin >> q;
    while(q--)
        solve();
}
