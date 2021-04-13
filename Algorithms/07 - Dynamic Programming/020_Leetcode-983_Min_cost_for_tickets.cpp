// PS : https://leetcode.com/problems/minimum-cost-for-tickets/
// Explanation : The solution is simple DP wherein for every day when you have to travel, choose the scenario which gives the minimum cost. The immportant thing to notice here
// is that we didn't do if(i-7 > 0) {...}, rather did dp[max(0, i-7)] because the former rules out the possibility of buying a 7-day or a 30-day pass on the first day

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

int mincostTickets(vector<int>& days, vector<int>& costs) {
	int dp[366] = {};
	for(int i=0; i<366; i++) {
		dp[i] = INF;
	}
	dp[0] = 0;
	for(int i=1; i<366; i++) {
		if(find(days.begin(), days.end(), i) == days.end())
			dp[i] = dp[i-1];
		else {
			int cost = dp[i-1] + costs[0];
			cost = min(cost, dp[max(0ll,i-7)] + costs[1]);
			cost = min(cost, dp[max(0ll,i-30)] + costs[2]);
			dp[i] = cost;
		}
	}
	return dp[365];
}

void solve() {
	vector<int> days = {1,4,6,7,8,20}, costs = {2,7,15};
	cout << mincostTickets(days, costs) << "\n";
}

signed main()
{
    fast;
    int q = 1;
//	cin >> q;
    while(q--)
        solve();
}
