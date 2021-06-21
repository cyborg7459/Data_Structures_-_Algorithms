// PS : We have a given number 'k' and we have to divide it into 'n' distinct positions. The value of a position can be equal to 0, but it cannot exceed a given number 'm'. Find the number of different
// ways to divide
// Explanation : We can solve the given questions using dynamic programming. Create an (n+1)x(k+1) DP table, where dp[i][j] represents the number of ways of dividing j into i different positions. Now, the
// base case would be dp[i][0] = 1, because the number of ways of dividing i positions to the sum of zero is only 1, i.e. take all elements as zero. Similarly, dp[0][i] = 0 because the number of ways of
// dividing i into 0 positions is zero.
// Now we start filling the table row-wise. Filling a cell is just like the coin problem, as we know that we have possible values from 0 to m, thus dp[i][j] = dp[i-1][j-m] + dp[i-1][j-m+1] + ...... dp[i-1][j]
// This solution is of the time complexity O(n*k*m), which would give TLE under the given circumstances. Hence we need to optimise this. As we can observe, the possible numbers to add are continuous from
// dp[i-1][j-m] to dp[i-1][j], hence if we maintain a prefix sum array, then we can achieve the same sum in O(1) instead of O(m) just by doing pre[j] - pre[j-m-1]. Hence, at each step we update the prefix
// array according to the current row, and then use this array while calculating the next row.
// A very important point is that in subtraction modulus, always check whether the number has become negative or not

#include <bits/stdc++.h>
using namespace std;

#define inf 1000000007
int prefix[10005] = {};
int dp[1005][10005] = {};

int numberOfDistictDivisions(int n, int k, int m){
    for(int i=0; i<=n; i++) dp[i][0] = 1;

    int temp = 0;
    for(int i=0; i<=k ;i++) {
        temp += dp[0][i];
        temp %= inf;
        prefix[i] = temp;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            if(j-m-1 < 0)
                dp[i][j] = prefix[j]%inf;
            else {
                dp[i][j] = (prefix[j]%inf - prefix[j-m-1]%inf);
                if(dp[i][j] < 0) dp[i][j] += inf;
                else dp[i][j] %= inf;
            }
            dp[i][j] %= inf;
        }
        int sum = 0;
        for(int j=0; j<=k; j++) {
            sum += dp[i][j] % inf;
            sum %= inf;
            prefix[j] = sum;
        }
    }

    return dp[n][k]%inf;
}

int main() {
    int n = 2, k = 4, m = 2;
    cout << numberOfDistictDivisions(n, k, m);
}
