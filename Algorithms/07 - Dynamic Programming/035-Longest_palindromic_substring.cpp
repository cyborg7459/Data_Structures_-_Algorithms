// PS : We have to return the longest substring of the given string, such that the given substring is a palindrome
// Explanation : The DP array would be a 2-D array. A value of dp[i][j] = 1 represents that the substring starting from index i and ending at index j is a palindrome. Now, all single length substrings
// would obviously be palindromes. Apart from this, also check for 2-sized substrings and acoordingly update the dp array. Now, the condition for substring [i,j] to be a palindrome would be that
// s[i] = s[j] and the substring [i+1, j-1] is a palindrome. One important thing to notice is that since we're going i+1 and j-1, i.e. bottom left, hence we cannot go row wise in the iteration as the
// values would not have been updated. Hence, the traversal of the string must be columnwise

#include <bits/stdc++.h>
using namespace std;

string LongestPalindromicSubstring(string s) {
	int n = s.length();
	int dp[n][n] = {};
	for(int i=0; i<n; i++) {
		dp[i][i] = 1;
		if(i < n-1 && s[i] == s[i+1])
			dp[i][i+1] = 1;
	}
	for(int j=0; j<n; j++) {
		for(int i=0; i<=j; i++) {
			if(dp[i][j] == 1) continue;
			if(s[i] == s[j] && i+1<n && j-1>=0 && dp[i+1][j-1]==1) {
				dp[i][j] = 1;
			}
		}
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	int ans = 0, start = 0, end = 0;
	for(int i=0; i<n; i++) {
		for(int j=i; j<n; j++) {
			if(dp[i][j] == 1) {
				if(j - i > ans) {
					ans = j-i;
					start = i;
					end = j;
				}
			}
		}
	}
	string res;
	for(int i=start; i<=end; i++)
		res.push_back(s[i]);
	return res;
}

int main() {
	string s = "babad";
	cout << LongestPalindromicSubstring(s) << endl;
}
