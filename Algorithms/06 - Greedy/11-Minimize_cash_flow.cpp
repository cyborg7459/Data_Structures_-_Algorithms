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
