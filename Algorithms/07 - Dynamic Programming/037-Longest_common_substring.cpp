// PS : Different that longest common subsequence in the sense that here, we have to find substring, i.e. elements should be continuous
// Explanation : Here we will create a 2-D array, where dp[i][j] will represent the length of substring which are same for both the strings, the first substring ending as index 'i' in the
// first string , and index 'j' in the second string. Hence, if s1[i] != s2[j] then straightaway dp[i][j] = 0. If the 2 are same, however, we'll go back 1 character in both strings and
// dp[i][j] = 1 + dp[i-1][j-1]

#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstr (string S1, string S2, int n, int m) {
    int dp[n][m];
    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            dp[i][j] = 0;
            if(S1[i] != S2[j]) dp[i][j] = 0;
            else {
                if(i-1 >=0 && j-1 >=0) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = 1;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

int main() {
    cout << longestCommonSubstr("ABCDGH", "ACDGHR", 6, 6);
}
