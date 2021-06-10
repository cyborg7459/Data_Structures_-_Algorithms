// PS : Given a string, calculate the number of insertions of characters at any position so as to convert the string into a palindrome
// Solution : Just like other string DP Solutions, create an n*n DP table, where dp[i][j] represents the number of insertions required for s[i,j]. Fill the base cases for 1 and 2-length substrings.
// After that, move diagonally and fill the elements in such a way :-
// If s[i] = s[j], then the number of insertions would be the same as insertions in s[i+1, j-1]
// If s[i] != s[j], then we have 2 options :-
// 1) Convert s[i+1, j] into a palindrome and then add ith character at end
// 2) Convert s[i, j-1] into a palindrome and then add jth character at start
// We have to choose the best out of these two

#include <bits/stdc++.h>
using namespace std;

int findMinInsertions(string S){
    int n = S.length();
    int dp[n][n] = {};
    for(int i=0; i<n; i++) {
        dp[i][i] = 0;
        if(i < n-1) {
            if(S[i] == S[i+1]) dp[i][i+1] = 0;
            else dp[i][i+1] = 1;
        }
    }
    int start_col = 2;
    while(start_col < n) {
        int x = 0, y = start_col;
        while(x < n && y < n) {
            if(S[x] == S[y]) dp[x][y] = dp[x+1][y-1];
            else dp[x][y] = min(1 + dp[x+1][y], 1 + dp[x][y-1]);
            x++;
            y++;
        }
        start_col++;
    }

    return dp[0][n-1];
}

int main() {
    cout << findMinInsertions("anasdad");
}
