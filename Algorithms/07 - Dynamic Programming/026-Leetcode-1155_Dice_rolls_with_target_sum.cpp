// PS : https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
// Solution : The question is different from the normal general case subset sum example in the respect that here we have to give the count of those subsets which have exactly
// 'd' elements in them. Hence the dp array becomes 2D and we can store the number of elements used to achieve the given sum 

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000007

signed main()
{
    int d=30, f=30, target=500;
	int dp[target+1][d+1] = {};
	dp[0][0] = 1;
	for(int i=0; i<=target; i++) {
		for(int j=0; j<d; j++) {
			for(int k=1; k<=f; k++) {
				if(i+k <= target) {
					dp[i+k][j+1] += dp[i][j];
					dp[i+k][j+1] %= INF;
				}
			}
		}
	}
	cout << dp[target][d] << endl;
}
