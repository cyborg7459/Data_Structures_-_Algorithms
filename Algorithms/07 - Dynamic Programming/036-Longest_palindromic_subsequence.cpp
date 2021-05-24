// PS : The difference b/w this problem and the previous one is that here we have to choose subsequence rather than substring
// Explanation : Here, instead of storing 0/1 in the dp, we store the the length of the longest palidromic subsequence in the substring starting from index i and ending at index j. Hence, for all
// i = j this value would be 1, and for all 2-length substrings, this value would be 2 in case the 2 characters are same, and 1 otherwise. These 2 form our base cases. Now, if we are looking at the
// substring [i,j] there are 2 cases :-
// 1) If s[i] != s[j], then no new palidromic subsequences would be formed in any smaller substring upon adding the ith and jth character. Hence, the longest palidromic subsequence would be the same
// as the LPS formed in the substrings [i+1, j] and [i, j-1]. Hence we'd take the maximum of these 2 values and store in the dp array
// 2) If s[i] = s[j], then the LPS would be 2 characters longer than the LPS formed in the substring [i+1, j-1].
// Since in this problem, we are moving left, as well as down separately, hence in order to have both the values updated before we access them, we have to traverse the dp array diagonal by diagonal.
// The answer would be stored in dp[0][n-1], i.e. the LPS formed in the substring from ith to (n-1)th character, i.e. the entire string

#include <bits/stdc++.h>
using namespace std;

int longestPalindromeSubseq(string s) {
	int n = s.length();
	int dp[n][n];
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			dp[i][j] = 0;
		}
	}
	for(int i=0; i<n; i++) {
		dp[i][i] = 1;
		if(i<n-1) {
			if(s[i] == s[i+1]) dp[i][i+1] = 2;
			else dp[i][i+1] = 1;
		}
	}
	for(int start = 2; start < n; start++) {
		int i = 0, j = start;
		while(i<n && j<n) {
			if(s[i] != s[j]) {
				if(j > 0)
					dp[i][j] = max(dp[i][j], dp[i][j-1]);
				if(i < n-1)
					dp[i][j] = max(dp[i][j], dp[i+1][j]);
			}
			else {
				dp[i][j] = 2 + dp[i+1][j-1];
			}
			i++;
			j++;
		}
	}
	return dp[0][n-1];
}

int main() {
	string s = "bbbab";
	cout << longestPalindromeSubseq(s);
}
