// PS : Given a string, we have to find the number of palindromic subsequences (they need not be unique)
// Explanation : The given problem can be solved using dynamic programming. The first step, as usual, is to create an n*n DP table, where dp[i][j] represents the number of palindromic
// subsequences in str[i, j]. Now, as the base cases, all dp[i][i] would be equal to 1. After that, move diagonally and fill the values by this logic :-
// 1) If str[i] != str[j], then simply we will add dp[i+1][j] and dp[i][j-1] because no new palindromic subsequences are formed. However, upon adding these 2, we add the palindromic subsequences
// lying in str[i+1, j-1] twice. Hence, we subtract that from the sum
// 2) If str[i] == str[j], then there are the following things to add :-
//    (i) All the subsequences which were already present. Hence we add dp[i+1][j] and dp[i][j-1]. However, this time we would not subtract the subsequences present in str[i+1, j-1]. This is because
//        for each of the subsequences, we can add str[i] and str[j] at the start and beginning to get a new palindromic subsequence. Hence, the fact that we added those subsequences twice is nullified
//        because we anyway need to add them twice due to the introduction of new subsequences
//    (ii) 1 new subsequence, i.e. just str[i] and str[j] combined is formed. Hence, we'll add 1 to the answer

// IMPORTANT POINT TO NOTE : Since here we are dealing with mod as well as subtraction, some errors may occur. For eg -> (11 + 12 - 9) % 10 = 4, but (11%10 + 12%10 - 9%10) = -6. Hence, we'll have to check
// that if dp[i][j] becomes negative after the subtraction step. If it does, we simply need to add inf to it.

#include <bits/stdc++.h>
using namespace std;
#define inf 1000000007

long long int  countPS(string str) {
    int n = str.length();
    long long int dp[n][n] = {};
    for(int i=0; i<n; i++) dp[i][i] = 1;
    int start_col = 1;
    while(start_col < n) {
        int i = 0, j = start_col;
        while(i<n && j<n) {
            if(str[i] == str[j])
                dp[i][j] = (dp[i+1][j]%inf + dp[i][j-1]%inf)%inf + 1;
            else {
                dp[i][j] = ((dp[i+1][j]%inf + dp[i][j-1]%inf)%inf - dp[i+1][j-1]%inf)%inf;
                if(dp[i][j] < 0) dp[i][j] += inf;
            }
            i++;
            j++;
        }
        start_col++;
    }
    return dp[0][n-1]%inf;
}

int main() {
    string str = "mmabasdjm";
    cout << countPS(str);
}
