// PS : We have to calculate the number of distict subsequences of s1 which are equal to s2

// Explanation : Similar to other string questions, we'll create a 2-D DP table where dp[i][j] represents the number of distict subsequences of s1[0,j] which are equal to s2[0,i]. Keep the first row
// and column extra for the base case. Now dp[0][i] would be all 1s, because there is only 1 distict subsequence which is null character (i.e. we choose no characters from s1). Similarly dp[i][0] would
// all be zeroes since there is no subsequence in empty string which is equal to s2[0,i]. obviously, dp[0][0] is equal to 1. Hence, our base cases are now complete.
// Now, suppose we are at (i,j). If the characters s1[j] and s2[i] are not same, then the number of distict subsequences would be same as the number of distict subsequences in s1[0, j-1] which were equal
// to s2[0,i] (since the addition of an extra character was no help). Thus, in the DP table it would mean the left number. Now if s1[j] = s2[i], then the favorable outcomes can occur in 2 ways :-
// 1) We don't take into consideration the current characters. The number of such subsequences would be equal to dp[i][j-1], i.e. the number of ways s2[0,i] was formed by subsequences of s1[0,j-1]
// 2) We take into consideration the current characters. The number of such subsequences would be equal to dp[i-1][j-1], i.e. the number of ways in which s2[0,i-1] was formed by subsequences of s1[0,j-1]
// Hence we'll add these 2 values to get the result

#include <bits/stdc++.h>
using namespace std;

unsigned long long numDistinct(string s, string t) {
    int n = s.length();
    int m = t.length();
    unsigned long long dp[m+1][n+1];
    for(int i=0; i<=m; i++)
        dp[i][0] = 0;
    for(int i=0; i<=n; i++)
        dp[0][i] = 1;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            dp[i][j] = dp[i][j-1];
            if(s[j-1] == t[i-1])
                dp[i][j] += dp[i-1][j-1];
        }
    }
    return dp[m][n];
}

int main() {
    cout << numDistinct("abbabababababababaaa", "abaa");
}
