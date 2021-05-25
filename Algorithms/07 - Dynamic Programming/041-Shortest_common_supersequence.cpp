// PS : Given 2 strings s1 and s2, we need to find the shortest string such that both s1 and s2 are subsequences of it

// Explanation : Just like any other string DP question, first step is to create a 2D DP table and fill it with base cases value. Here since we need to construct back the string instead of just
// giving the length, hence we also need to keep track of our choices at each step. Hence the table would store pair<int, int> values, with the first number depicting choice and the second depicting
// length of supersequence. Now, the base cases would be as follows :-
// 1) dp[0][i] represents the string that contains s1[0,i] and no part of s2, hence it's length would obviously be equal to i, and we arrived here from the left (i.e. previous character of s1)
// 2) Similaly, dp[i][0] would contain a string of length i, and we arrived from top
// 3) dp[0][0] is obviously equal to 0-length
// The choices are as follows:-
// 0 -> We've arrived from the top-left, i.e. (i-1, j-1)
// 1 -> We've arrived from the top, i.e. (i-1,j)
// 2 -> We've arrived from the left, i.e. (i,j-1)
// Once all base cases are done, we can start traversing. If the characters at s1 and s2 are same, then all we have to do is add that character to the string formed at dp[i-1][j-1]. Else, we'll see that
// which side, top or left has a shorter string. The left represents the superstring containing s1[0,j-1] and s2[0,i], hence we'll need to add s1[j] to it. Similarly, if we come from top, it means that we're
// adding s2[i-1] to the previous result.
// Now at the end, all we got to do is move back from (n,m) to (0,0) by pushing those characters which were added optimally (by seeing the choice number). This gives the string in reverse order, hence we'll
// reverse it back

#include <bits/stdc++.h>
using namespace std;

string shortestCommonSupersequence(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();
    pair<int, int> dp[m+1][n+1];
    dp[0][0] = {0,0};
    for(int i=1; i<=n; i++) {
        dp[0][i].first = 2;
        dp[0][i].second = 1 + dp[0][i-1].second;
    }
    for(int i=1; i<=m; i++) {
        dp[i][0].first = 1;
        dp[i][0].second = 1 + dp[i-1][0].second;
    }
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(str1[j-1] == str2[i-1]) {
                dp[i][j].first = 0;
                dp[i][j].second = 1 + dp[i-1][j-1].second;
            }
            else {
                if(dp[i-1][j].second <= dp[i][j-1].second) {
                    dp[i][j].first = 1;
                    dp[i][j].second = 1 + dp[i-1][j].second;
                }
                else {
                    dp[i][j].first = 2;
                    dp[i][j].second = 1 + dp[i][j-1].second;
                }
            }
        }
    }
    int i1 = n-1, i2 = m-1;
    string ans;
    int i = m, j = n;
    while(i>0 ||  j>0) {
        pair<int, int> p = dp[i][j];
        if(p.first == 0) {
            ans.push_back(str1[j-1]);
            i--;
            j--;
        }
        else if(p.first == 1) {
            ans.push_back(str2[i-1]);
            i--;
        }
        else {
            ans.push_back(str1[j-1]);
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    cout << shortestCommonSupersequence("iuawefkfbj", "aulfkhskudfhd");
}
