// PS : We have a keyboard in which we can do one of the following actions each time
// 1) Type an 'A'
// 2) Select all (ctrl+a)
// 3) Copy all (ctrl+c)
// 4) Paste (ctrl+v)
// We have to find out the maximum number of A's that we can print in 'n' actions

// Explanation : Once we copy an element, that remains in out buffer and we can continue pasting the same element over and over until we copy some other. We'll use this fact in our solution.
// The idea here is to find optimal breakpoints, i.e. points at which we stop pasting and instead copy the content present. Optimal breakpoint means that the point at which copying and then
// pasting that same element up till the very end gives the maximum result.
// Base case is that from n = 1 to 6, the answer is the number itself. Now for the remaining 'n'. We can have the latest breakpoint at point (i-3), because it takes 3 actions to select, copy and
// paste. Hence, we'll traverse from i-3 backwards to the start of the array, and maximize the current value (by maximizing the value we make sure that we copied at optimal breakpoint)

#include <bits/stdc++.h>
using namespace std;

long long int optimalKeys(int n){
    if(n < 7) return n;
    int dp[n+1];
    for(int i=1; i<7; i++)  dp[i] = i;
    for(int i=7; i<=n; i++) {
        dp[i] = 0;
        for(int j = i-3; j>=1; j--) {
            int x = dp[j] * (i-j-1);
            dp[i] = max(dp[i], x);
        }
    }
    return dp[n];
}

int main() {
    cout << optimalKeys(21);
}
