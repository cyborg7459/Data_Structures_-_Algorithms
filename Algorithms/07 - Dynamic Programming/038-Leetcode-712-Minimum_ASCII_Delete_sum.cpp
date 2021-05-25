// PS : https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
// Explanation : Implementation is somewhat similar to Longest Common Subsequence, however in this case, instead of maximizing the length of the subsequence, we rather maximize the sum of
// ASCII values of the characters in the common subsequence. If this sum is maximized, then automatically the ASCII sum of the removed characters would be minimum

#include <bits/stdc++.h>
using namespace std;

int minimumDeleteSum(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    int dp[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            dp[i][j] = 0;
            if(i > 0) dp[i][j] = dp[i-1][j];
            if(j > 0) dp[i][j] = max(dp[i][j], dp[i][j-1]);
            if(s1[i] == s2[j]) {
                int val = s1[i];
                if(i > 0 && j > 0)
                    dp[i][j] = 2*val + dp[i-1][j-1];
                else
                    dp[i][j] = 2 * val;
            }
        }
    }
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += s1[i];
    for(int i=0; i<m; i++)
        sum += s2[i];
    return (sum - dp[n-1][m-1]);
}

int main() {
    cout << minimumDeleteSum("sea", "eat"); 
}
