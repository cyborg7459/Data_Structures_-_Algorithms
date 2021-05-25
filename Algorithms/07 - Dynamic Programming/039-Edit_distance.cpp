// PS : Our goal is to find the minimum steps required to convert one string into another. At each step, we can perform one of the following operations :-
// 1) Delete a character at any position
// 2) Add any character of our choice at any position
// 3) Replace a character with some other character

// Explanation : As base cases, we need to find how many steps are required to convert s1 into a null string, and a null string into s2. Thus, we'll have a table dp[n+1][m+1] where dp[i][j] represents
// the minimum steps required to convert s1[0, j] into s2[0, i]. The 0th index is taken as a null character intentionally for base case. Thus, dp[0][j] represents the number of operation required to convert
// s1[0,j] into a null string, which is obviously 'j' deletions. Similarly, dp[i][0] represents the number of operations required to convert a null string into s2[0,i] which is again 'i' additions. Now suppose
// we are currently at (i, j), i.e. we need to find the number of operations required to convert s1[0,j] to s2[0,i]. Suppose s1[j] = s2[i], thus the number of operations required would be same as those
// required to convert s1[0,j-1] to s2[0, i-1], and thus dp[i][j] = dp[i-1][j-1]. If the characters are not same, however, then we can do either of the 3 operations
// 1) Delete one character from s1 and then convert s1[0,j-1] into s2[0,i]. Thus, in the dp table it would mean moving towards left by one block
// 2) Replacing the character to make s1[j] equal to s2[i] and then converting s1[0, j-1] to s2[0, i-1]. In the dp table, this means moving diagonally up by 1 distance
// 3) Add an extra character to s1 and then make s1[0, j] convert to s2[0, i-1]. In the dp table this would mean moving up by one block
// Since we require the minimum number of steps, we'll choose whichever one is the minimum out of these. 1 is added because we perform the operation and then do the next conversion.

#include <bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2) {
    int n = word1.length();
    int m = word2.length();
    int dp[m+1][n+1];
    for(int i=0; i<=n; i++)
        dp[0][i] = i;
    for(int i=0; i<=m; i++)
        dp[i][0] = i;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(word1[j-1] == word2[i-1])
                dp[i][j] = dp[i-1][j-1];
            else {
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        }
    }
    return dp[m][n];
}

int main() {
    cout << minDistance("intention", "execution");
}
