// PS : https://leetcode.com/problems/soup-servings/
// Explanation : In this problem, we successively keep taking all 4 cases while multiplying the probablility with 1/4 in each step. The important point
// here is that for n larger than a given value, the answer would almost be equal to 1, i.e. the absolute difference would become less than 10^-6 which
// is the required precision. Hence, after that we'll just take the answer as 1 (this is done to avoid TLE).

#include <bits/stdc++.h>
using namespace std;

#define INF 1000000007

double dp[5000][5000] = {};
double prob(int a, int b) {
	if(dp[a][b] > 0) return dp[a][b];
	if(a == 0 && b != 0) return 1.0;
	if(a == 0 && b == 0) return 0.5;
	if(a != 0 && b == 0) return 0.0;
	double ans = 0;
	ans += 0.25 * prob(a - min(a, 100), b);
	ans += 0.25 * prob(a - min(a, 75), b - min(b, 25));
	ans += 0.25 * prob(a - min(a, 50), b - min(b, 50));
	ans += 0.25 * prob(a - min(a, 25), b - min(b, 75));
	dp[a][b] = ans;
	return ans;
}

signed main()
{
	cout << fixed << setprecision(7);
	int n = 50;
	if(n >= 5000) {
		cout << 1 << endl;
		return 0;
	}
	cout << prob(n, n) << endl;
}
