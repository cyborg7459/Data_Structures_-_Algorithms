// PS : Given the buying and selling prices of stock over 'n' days, find the maximum profit that can be acheived by making at most 2 transactions
// Explanation : The answer to this problem would be equal to the maximum of profit[0,i] + profit[i,n] for all 'i' from 0 to n, i.e. the maximum profit that can be achieved in the first i days plus the
// profit that can be achieved in the next (n-i) days. Hence, take 2 arrays and store these values. Max profit that can be acheived in first i days is equal to the maximum difference between 2 numbers
// such that the greater number occurs later than the smaller. Similarly, reverse traverse the array to generate arr2. Then maximize arr1[i] + arr2[i+1].
// At the end, also check arr1[n-1] in case the maximum profit is achievable in a single transaction itself (would happen in case of a sorted array)

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
	int n = prices.size();
	int arr1[n];
	int arr2[n];
	int mn = prices[0], mx = prices[n-1];

    arr1[0] = 0;
	for(int i=1; i<n; i++) {
		arr1[i] = arr1[i-1];
		if(prices[i] < mn) mn = prices[i];
		else arr1[i] = max(prices[i] - mn, arr1[i]);
	}

    arr2[n-1] = 0;
	for(int i=n-2; i>=0; i--) {
		arr2[i] = arr2[i+1];
		if(prices[i] > mx) mx = prices[i];
		else arr2[i] = max(arr2[i], mx - prices[i]);
	}

    int ans = 0;
	for(int i=0; i<n-1; i++) {
		ans = max(ans, arr2[i+1] + arr1[i]);
	}
	return max(ans, arr1[n-1]);
}

int main() {
	vector<int> prices = {5,4,3,2,1};
	cout << maxProfit(prices);
}
