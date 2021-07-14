// PS : Given three strings, find whether the third string can be created by interweaving all characters of the other 2 strings, while maintaing the relative order between them
// Explanation : Create the dp table of (n+1)x(m+1) size, where dp[i][j] stores the length 'l' representing that we can interweaving str1[0, i) and str2[0, j) to form str3 up till 'l' length.
// Initialise the table with all zero values. Now suppose we are at a point (i, j) and have already achieved str up till length 'l'. Now, if we find str3[l] in either of the 2 strings, then we can
// proceed further. If this character is achieved from str1, then dp[i+1][j] = l+1, and if the character is achieved from str2, then dp[i][j+1] = l+1. In case both are there, then we will take both
// because we cannot be sure of taking one and leaving out another. In case the value of dp[i+1][j] or dp[i][j+1] is already greater, do not update

#include <bits/stdc++.h>
using namespace std;

bool isInterleave(string A, string B, string C) {
    int n = A.length(), m = B.length();
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            if(i+1 <= n && A[i] == C[dp[i][j]])
                dp[i+1][j] = max(dp[i+1][j], dp[i][j] + 1);
            if(j+1 <= m && B[j] == C[dp[i][j]])
                dp[i][j+1] = max(dp[i][j+1], dp[i][j] + 1);
        }
    }
    return (dp[n][m] == C.length());
}

int main() {
    cout << boolalpha << isInterleave("bx", "by", "bbxy");
}
