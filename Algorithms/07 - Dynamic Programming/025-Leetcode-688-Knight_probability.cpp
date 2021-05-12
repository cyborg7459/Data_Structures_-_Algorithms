// PS : https://leetcode.com/problems/knight-probability-in-chessboard/
// Explanation : In this problem, we only need to know which are the blocks where the knight can be after k-1 moves. Hence, first of all we create the prob array which stores
// the probability of staying in board after 1 move from the given block. After that, using dynamic programming, we calculate the number of ways in which one can stay inside
// the board if we're on a given block with 1 move remaining. We add this number for all the blocks that are possible after k-1 moves. Now, out of 8^k positions, we have the
// calculated number of options, thus we can easily find the probability

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000007

int sum = 0;
double prob[100][100] = {};
vector<pair<int, int>> moves = {{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};

double calculate_sum(int i, int j, int r, int c, int moves_left, map<pair<pair<int, int>, int>, int> &dp) {
	if(i < 0 || i>=r || j<0 || j>=c) return 0;
	if(moves_left == 1) return prob[i][j]*8;
	if(dp.find({{i, j}, moves_left}) != dp.end()) {
		return dp[{{i,j}, moves_left}];
	}
	double ans = 0;
	for(pair<int, int> p : moves) {
		int x = i + p.first;
		int y = j + p.second;
		ans += calculate_sum(x, y, r, c, moves_left-1, dp);
	}
	dp[{{i,j}, moves_left}] = ans;
	return ans;
}

signed main()
{
	int n, k, row, column;
	cout << "Enter edge size of chess board (limit is 25) : ";
	cin >> n;
	if(n > 25) {
		cout << "Limit exceeded\n";
		return 0;
	}
	cout << "Enter number of moves (limit is 100) : ";
	cin >> k;
	if(k > 100) {
		cout << "Limit exceeded\n";
		return 0;
	}
	cout << "Enter starting row : ";
	cin >> row;
	if(row < 1 || row > n) {
		cout << "Out of bounds\n";
		return 0;
	}
	row--;
	cout << "Enter starting column : ";
	cin >> column;
	if(column < 1 || column > n) {
		cout << "Out of bounds\n";
		return 0;
	}
	column--;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			double cnt = 0;
			for(pair<int, int> p : moves) {
				int x = i + p.first;
				int y = j + p.second;
				if(x>=0 && x<n && y>=0 && y<n)
					cnt++;
			}
			prob[i][j] = cnt/8;
		}
	}
	map<pair<pair<int, int>, int>, int> dp;
	if(k == 0) {
		cout << 1.0000 << endl;
		return 0;
	}
	double sum = calculate_sum(row, column, n, n, k, dp);
	while(k--) {
		sum /= 8;
	}
	cout << sum << endl;
}
