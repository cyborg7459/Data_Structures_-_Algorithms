// PS : Given start time, end time and profit of several jobs, find the maximum profit achievable such that no two tasks overlap
// Explanation : First sort the tasks by their finish time, then use dynamic programming to check the maximum profit when we choose that task, and when we do not choose that task. In case the previous
// end is greater than current start, then we have only 1 choice, i.e. to not do that task

#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005] = {};
int maxProfit(vector<pair<pair<int, int>, int>> &v, int start, int prev_end, int n) {
	if(dp[start][prev_end] != 0) return dp[start][prev_end];
	if(start == n) return 0;
	int opt1 = 0, opt2 = 0;
	if(v[start].first.first >= prev_end)
		opt1 = v[start].second + maxProfit(v, start+1, v[start].first.second, n);
	opt2 = maxProfit(v, start+1, prev_end, n);
	dp[start][prev_end] = max(opt1, opt2);
	return max(opt1, opt2);
}

int main() {
	vector<pair<pair<int, int>, int>> v;
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		int a = rand() % 250;
		int b = rand() % 250;
		int c = rand() % 150;
		v.push_back({{min(a, b), max(a, b)}, c});
	}
	sort(v.begin(), v.end(), [](auto p1, auto p2) {
		return p1.first.second < p2.first.second;
	});
	cout << maxProfit(v, 0, 0, n) << endl;
}
