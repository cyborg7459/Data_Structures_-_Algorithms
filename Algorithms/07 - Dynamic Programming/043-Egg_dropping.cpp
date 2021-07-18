// PS : We have 'n' eggs and a 'k' storey building. There is a critical floor such that if an egg if dropped from a floor below it, it does not break, and vice versa. We need to find out the minimum
// number of attempts that we need to find out the critical floor in the worst case. If an egg is broken, we cannot use it again
// Example : Suppose we have only 1 egg, then we have only one choice that we start from the first floor and keep dropping, and the floor on which it breaks is the critical floor. Hence in the worst case,
// we need 'k' attempts to find the critical floor. If there are 3 floors, and more that 1 egg, then first we'll drop from the second floor. If the egg breaks, we'll drop a new egg from the first floor, and
// if it does not break, we'll drop the same egg from the 3rd floor. Hence in the worst case, we needed only 2 attempts.

// Solution : The given problem can be solved using dynamic programming. Create a DP table of (n+1) rows and (k+1) columns, where dp[i][j] represents the number of attempts required in case we have i eggs and
// j floors. For the base cases, it is obvious that if we have no eggs and k > 0, then we cannot find the critical floor, and hence dp[0][k] = inf. Similarly, if we have no floors, we need 0 attempts. We can
// also fill the columns for 1,2 and 3 floors as we know the answer for that. Now for a general point dp[i][j], we're having a building of 'j' floors and have 'i' eggs. What we do is that we, one by one, drop
// eggs from all floors from 1st to jth, and see which one gives the minimum answer. Hence we run a loop for that. Now suppose, in the loop we are at the xth floor (1 <= x <= j) and we drop the egg. Hence
// one move gone for dropping the egg. Now there are 2 possibilities
// 1) If the egg broke, then we have to find the answer for i-1 eggs and x-1 floors
// 2) If the egg did not break, then we have to find the answer for i eggs and j-x floors
// We'll choose the maximum of these 2 as we have to see the worst case. Thus we'll calculate max(dp[i-1][x-1], dp[i][j-x]) for each x and take the minimum of all. Then dp[i][j] = 1 + min

// One very important optimization in this problem is that instead of looping through all, we can apply binary search while looking for floors. This has got to do with the increasing nature of dp[i-1][x-1], and
// decreasing nature of dp[i][j-x] with the value of x (The standard solution has been commented in case you wish to see that). This new solution is of n*k*logk instead of nK^2

#include <bits/stdc++.h>
using namespace std;

#define INF 1000000007

int main() {
	int n = 10, k = 100;
	int dp[n+1][k+1] = {};
	for(int i=1; i<=k; i++) {
		dp[1][i] = i;
		dp[0][i] = INF;
	}
	for(int i=1; i<=n; i++) {
		dp[i][0] = 0;
		dp[i][1] = 1;
		dp[i][2] = 2;
		if(i != 1) dp[i][3] = 2;
	}
	for(int i=2; i<=n; i++) {
		for(int j=4; j<=k; j++) {
			dp[i][j] =INF;
			int add = INF;
			// for(int x=1; x<=j; x++) {
			// 	int a = dp[i-1][x-1];
			// 	int b = dp[i][j-x];
			// 	add = min(add, max(a, b));
			// }
			int low = 1, high = j;
			while(low <= high) {
				int mid = low + (high- low)/2;
				if(dp[i-1][low-1] < dp[i][j-low]) low = mid+1;
				else high = mid-1;
			}
			int opt1 = max(dp[i-1][low-1], dp[i][j-low]);
			int opt2 = max(dp[i-1][high-1], dp[i][j-high]);
			add = min(opt1, opt2);
			dp[i][j] = 1 + add;
		}
	}
	cout << dp[n][k];
}
