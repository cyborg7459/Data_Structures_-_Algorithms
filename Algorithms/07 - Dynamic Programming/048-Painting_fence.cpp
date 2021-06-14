// PS : Given a fence with n posts and k colors, find out the number of ways of painting the fence such that at most 2 adjacent posts have the same color
// Explanation : This problem can be solved using dynamuic programming. Create a dp table of size (nx2), where dp[i][0] represents the number of ways of painting 'i' posts if the ith post's color is
// same as the previous post, and dp[i][1] represents the number when ith post is of some other color than the previous post. Hence the answer would be given by dp[n][0] + dp[n][1].
// Now, the first and second fences form the base cases :-
// 1) dp[1][0] = k
// 2) dp[1][1] = k
// 3) dp[2][1] = k
// 4) dp[2][2] = k(k-1)
// For subesquent posts, the dp statement is as follows -  Suppose we wish to color the post same as the previous post, then the previous post must have a different color than it's previous post
// due to the given condition that no more than 2 adjacent posts can have the same color. Also, we have only one choice of color in this case. Hence dp[i][0] = dp[i-1][1].
// If we wish to color the current post in a different color, then the previous post can be either of the same, or different color than it's previous post. Furthermore, for any color the previous
// post is, we have (k-1) options for the current post. Hence, dp[i][1] = (dp[i-1]][0] + dp[i-1][1]) * (k-1)

#include <bits/stdc++.h>
using namespace std;
#define inf 1000000007

long long countWays(int n, int k){
    if(n==1) return k;
    if(n==2) return k*k;
    long long dp[n+1][2];
    dp[1][0] = k;
    dp[1][1] = k;
    dp[2][0] = k;
    dp[2][1] = k*(k-1);
    for(int i=3; i<=n; i++) {
        dp[i][0] = dp[i-1][1] % inf;
        dp[i][1] = ((dp[i-1][0] + dp[i-1][1])%inf * (k-1)%inf) % inf;
    }
    return (dp[n][0] + dp[n][1]) % inf;
}

int main() {
    int n = 34554;
    int k = 73;
    cout << countWays(n, k);
}
