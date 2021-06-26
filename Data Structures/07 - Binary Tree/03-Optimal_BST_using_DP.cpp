// PS : For a given set of keys, we know how many times each key would be searched. We have to arrange the keys in a Binary Search Tree in such a manner that the total cost of
// all search operations is minimized, where the cost of a single search operation is equal to the frequency of that element mulitplied by the level (root being level 1) of that
// element in the BST

// Explanation : First step would be to sort the keys and hence accordingly arrange the frequencies. Now we can run the unique BSTs implementation using dynamic programming, with
// the addition of the 'level' parameter. Hence the dp map now becomes pair<pair<int, int>, int> to accomodate level, as well as an extra parameter in the function

#include <bits/stdc++.h>
using namespace std;

int optimalCost(int l, int r, int level, vector<int> &freq, map<pair<pair<int, int>, int>, int> &dp) {
	if(dp.find({{l, r}, level}) != dp.end()) return dp[{{l, r}, level}];
	if(l > r) return 0;
	if(l == r) return freq[l-1]*level;
	int res = 1000000007;
	for(int root = l; root <= r; root++) {
		int cost = freq[root-1]*level + optimalCost(l, root-1, level+1, freq, dp) + optimalCost(root+1, r, level+1, freq, dp);
		res = min(res, cost);
	}
	dp[{{l, r}, level}] = res;
	return res;
}

int getMoneyAmount(int n, vector<int> freq) {
	map<pair<pair<int, int>, int>, int> dp;
	int ans = optimalCost(1, n, 1, freq, dp);
	return ans;
}

int main() {
	vector<int> keys = {75, 12, 64, 24, 45, 35, 28, 20, 10, 100};
	vector<int> freq = {44, 8, 30, 22, 12, 55, 8, 50, 34, 31};

	vector<pair<int, int>> sorted_keys;
	for(unsigned int i=0; i<keys.size(); i++)
		sorted_keys.push_back({keys[i], i});
	sort(sorted_keys.begin(), sorted_keys.end());

	vector<int> sorted_freq;
	for(unsigned int i=0; i<keys.size(); i++)
		sorted_freq.push_back(freq[sorted_keys[i].second]);

	cout << getMoneyAmount(10, sorted_freq);
}
