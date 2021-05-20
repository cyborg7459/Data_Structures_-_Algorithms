// PS : https://leetcode.com/problems/guess-number-higher-or-lower-ii/

#include <bits/stdc++.h>
using namespace std;

int maxSumToPay(vector<vector<int>> &dp, int left, int right) {
	if(left >= right) return 0;
	if(dp[left][right] >= 0) return dp[left][right];
	int res = 1000000007;
	for(int root = left; root <= right; root++) {
		int k = root + max(maxSumToPay(dp, left, root-1), maxSumToPay(dp, root+1, right));
		res = min(res, k);
	}
	dp[left][right] = res;
	return res;
}

int getMoneyAmount(int n) {
	vector<vector<int>> dp;
	for(int i=0; i<=n; i++) {
		vector<int> temp;
		for(int j=0; j<=n; j++) {
			temp.push_back(-1);
		}
		dp.push_back(temp);
	}
	return maxSumToPay(dp, 1, n);
}

int main() {
	cout << getMoneyAmount(200) << endl;
}
