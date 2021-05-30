// Problem : https://www.geeksforgeeks.org/minimize-cash-flow-among-given-set-friends-borrowed-money/
// Explanation : In the greedy approach, our goal at each step is to settle the transaction between the person having the maximum due credit and the maximum due debit.
// This is because at the end, even though indirectly, the amount would go from one person to the other. Hence to minimize the cash flow, we make this transaction directly between
// the 2 of them

#include <bits/stdc++.h>
using namespace std;

int graph[3][3] = {{0,1000,2000}, {0,0,5000}, {0,0,0}};

void func(vector<int> &amount) {
	int mxi = max_element(amount.begin(), amount.end()) - amount.begin();
	int mni = min_element(amount.begin(), amount.end()) - amount.begin();
	if(amount[mxi] == 0 && amount[mni] == 0)
		return;
	int k = min(amount[mxi], -1*amount[mni]);
	amount[mxi] -= k;
	amount[mni] += k;
	cout << "Person " << mni+1 << " paid an amount of " << k << " to person " << mxi+1 << "\n";
	func(amount);
}

void minCashFlow(int n) {
	vector<int> amount(n);
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			amount[i] += (graph[j][i] - graph[i][j]);
		}
	}
	func(amount);
}

int main() {
	minCashFlow(3);
}
