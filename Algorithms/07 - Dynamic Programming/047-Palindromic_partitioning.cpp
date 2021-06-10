// PS : Given a string, we have to find out the minimum number of positions we'll have to cut the string so that the different sections of the string thus formed are all palindromes
// Explanation : Very important problem, requires DP twice. First of all, create a grid of palindromic substrings in the string, i.e. a grid of n*n size where grid[i][j] represents whether the substring S(i,j) is
// a palindrome or not. Now we have to calculate the minimum number of cuts so that all segments are palindromes. Hence, we know using the grid, the points at which we can make cuts so that the string is a palindrome.
// We'll start from the full length of the string, and cut it at all positions possible, such that the right part is a palindrome. Then we'll recursively do the same for the left part of the string.
// Base case is that if grid[0][cur] = 1, which means that the left string is also a plaindrome and there's no need to cut it further

#include <bits/stdc++.h>
using namespace std;

int dp1[505] = {};

int minCuts(int cur, vector<vector<int>> &dp) {
    if(dp[0][cur] == 1) return 0;
    if(dp1[cur] > 0) return dp1[cur];
    int ans = 1000000007;
    for(int i = 1; i < dp.size(); i++) {
        if(dp[i][cur] == 1) {
            ans = min(ans, 1 + minCuts(i-1, dp));
        }
    }
    dp1[cur] = ans;
    return ans;
}

int palindromicPartition(string str) {
    int n = str.length();
    vector<vector<int>> dp;
    for(int i=0; i<n; i++) {
        vector<int> temp(n, 0);
        dp.push_back(temp);
    }
    for(int i=0; i<n; i++) {
        dp[i][i] = 1;
        if(i < n-1 && str[i] == str[i+1])
            dp[i][i+1] = 1;
    }
    int start_col = 2;
    while(start_col < n) {
        int i = 0, j = start_col;
        while(i < n &&  j < n) {
            if(str[i] == str[j] && dp[i+1][j-1] == 1) dp[i][j] = 1;
            i++;
            j++;
        }
        start_col++;
    }
    int ans = 0;
    int cur_end = n-1;
    return minCuts(n-1, dp);
}

int main() {
    cout << palindromicPartition("aabaajkefe");
}
