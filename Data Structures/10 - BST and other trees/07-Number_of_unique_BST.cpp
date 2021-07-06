// Explanation : This problem can be solved in quadratic time using dynamic programming. Suppose we have 'n' elements and we have to find out the nunber of BSTs possible. We take i a root, then elements
// [1,i-1] belong in the left subtree and elements [i+1, n] belong to the right subtree. The total number of trees possible would be the multiplication of the number of subrees possible on both sides,
// i.e. dp[n-i] * dp[i-1]. We can make each of the elements from [1,n] as roots, hence we'll add the answer for all. Note that the DP statement is so becuase the number of BSTs formed by using keys from
// [5,8] would be same as that using the keys [1,4]. Hence dp[i-j] serves our purpose

#include<bits/stdc++.h>
using namespace std;

unsigned long long numTrees(int N) {
    unsigned long long dp[N+1] = {};
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=N; i++) {
        for(int j=1; j<=i; j++) {
            dp[i] += dp[i-j] * dp[j-1];
            dp[i] %= 1000000007;
        }
    }
    return dp[N];
}

int main(){
    int n;
    cin>>n;
    cout<< numTrees(n);
}
