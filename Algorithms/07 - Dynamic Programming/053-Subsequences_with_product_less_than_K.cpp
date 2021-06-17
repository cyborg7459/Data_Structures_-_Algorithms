// PS : Given an array, our goal is to find the number of subseqences that have the product of elements smaller than 'k'
// Explanation : We create a dp[n+1][k+1] table where dp[i][j] represents the number of subseqences of the subarray[0, i] for which the product is lte j. Hence, the transition statement would be as
// follows. Firstly, dp[i][j] = dp[i-1][j] because the subseqences of the the smaller subarray would also be a part of the current subarray. Now, to this value, we need to add the new subarrays which
// form due to the addition of the ith element. This value would be given by dp[i-1][j/arr[i-1]]
// All columns are initialised to zero, but if j > arr[i-1] then we set it 1 (due to the fact that we can choose just that number as a subseqence)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4;
    int arr[n] = {4, 8, 7, 2};
    int k = 50;
    int dp[n+1][k+1] = {};
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            if(j > arr[i-1]) dp[i][j] = 1;
            dp[i][j] += dp[i-1][j] + dp[i-1][j/arr[i-1]];
        }
    }
    cout << dp[n][k];
}
