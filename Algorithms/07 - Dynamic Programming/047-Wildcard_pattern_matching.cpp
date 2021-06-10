// PS : Given two strings 'str' and a wildcard pattern 'pattern' of length N and M respectively,  You have to print '1' if the wildcard pattern is matched with str else print '0' .
// The wildcard pattern can include the characters ‘?’ and ‘*’
// ‘?’ – matches any single character
// ‘*’ – Matches any sequence of characters (including the empty sequence)
// For eg - ba*a? can be converted to baaabab by replacing * with 'aab' and ? with 'b'

// Explanation : First of all create a DP table of size (m+1)*(n+1) and initially fill all with 0. dp[i][j] represents whether we can convert pattern[0,i] to string[0,j]. Since (0,0) means both are null strings,
// thus dp[0][0] = 1. Now from here on we traverse both strings in a double loop. There are 3 possibilities
// 1) pattern[i] is a normal character. In this case, the pattern matches iff pattern[i] = str[j] and the patterns before that match (i.e. dp[i-1][j-1] = 1)
// 2) If pattern[i] is a '?', then all we need is that dp[i-1][j-1] = 1 because we can convert the '?' into str[j] hence completing the match
// 3) In case pattern[i] = '*' then if any of dp[i-1][j-1], dp[i][j-1], dp[i-1][j] is 1, then dp[i-1][j-1] would be 1. This is because :-
//    (i) dp[i-1][j-1] = 1 means that strings up till the previous characters are matching, and hence we can replace '*' with str[j]
//    (ii) dp[i-1][j] = 1 means that pattern(0, i-1) itself constituted the string up till now. But since we can take '*' as empty as well, hence dp[i][j] will also be 1
//    (iii) dp[i][j-1] = 1 means that pattern(0, i) constitutes up till the str(0, j-1). Hence we can just append the str[j] character because '*' can be a sequence of characters as well
// A very important edge case here is the presence of leading '*'. If they are present, it means that up till that time, pattern can also make up an empty string. Hence, for all the leading '*', dp[i][0] would
// also be 1 (we can keep track of leading '*' using a boolean variable)

#include <bits/stdc++.h>
using namespace std;

int wildCard(string pattern,string str) {
    int n = str.length(), m = pattern.length();
    int dp[m+1][n+1] = {};
    dp[0][0] = 1;
    bool b = true;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(pattern[i-1] == '*') {
                if(b) dp[i][0] = 1;
                if(dp[i-1][j] == 1 || dp[i][j-1] == 1 || dp[i-1][j-1] == 1)
                    dp[i][j] = 1;
            }
            else if(pattern[i-1] == '?') {
                b = false;
                if(dp[i-1][j-1] == 1)
                    dp[i][j] = 1;
            }
            else {
                b = false;
                if(dp[i-1][j-1] == 1 && pattern[i-1] == str[j-1])
                    dp[i][j] = 1;
            }
        }
    }
    return dp[m][n];
}

int main() {
    string pattern = "***bb****a?";
    string str = "bbabab";
    int x = wildCard(pattern, str);
    if(x == 1) cout << "Possible to convert pattern to string";
    else cout << "Not possible to convert pattern to string";
}
