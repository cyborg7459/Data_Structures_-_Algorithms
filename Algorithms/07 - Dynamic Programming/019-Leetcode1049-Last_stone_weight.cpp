// PS : https://leetcode.com/problems/last-stone-weight-ii/
// Description : We can solve the given problem using subset sum problem (like in Knapsack). First calculate the total sum of all stones and then calculate all the possible sums that can be generated
// using the given stones. Then, for each possible sum, we can assume that the stones forming that sum are in one group and the rest of the stones are in other group and we keep smashing stones of the
// 2 groups with each other until one stone is left. The weight of the remaining stone would be the difference betweeen the sum of the 2 groups, i.e. abs(sum1 - (total_sum - sum1)). Hence we just have
// to minimize this value. The closer the sum1 is to sum/2 the lesser that value would be. Hence we start from sum/2 and whichever sum is possible we use that


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

int lastStoneWeightII(vector<int>& stones) {
	int arr[1501] = {};
	int sum = 0;
	arr[0] = 1;
	loop(i, stones.size()) {
		sum += stones[i];
		for(int j=1500; j>=0; j--) {
			if(arr[j]==1 && stones[i] + j <= 1500) {
				arr[stones[i] + j] = 1;
			}
		}
	}
	int ans = INF;
	for(int i=sum/2; i>=0; i--) {
		if(arr[i] == 1) {
			int a = i;
			int b = sum - i;
			ans = min(ans, abs(a-b));
		}
	}
	return ans;
}

void solve() {
	vector<int> v = {2,1};
	cout << lastStoneWeightII(v) << "\n";
}

signed main()
{
    fast;
    int q = 1;
//	cin >> q;
    while(q--)
        solve();
}
