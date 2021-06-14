// PS : Implement the LCS problem in O(n) space complexity
// Explanation : Since in LCS, we always need only the previous row for our operations, hence we can just maintain a dp table of 2 rows. When we are at row 0, row 1 serves as previous row
// and vice-versa (hence instead of i-1, we can access the previous row by 1-i)

#include <bits/stdc++.h>
using namespace std;

int lcs(int x, int y, string s1, string s2) {
    int dp[2][y+1];
    for(int i=0; i<2; i++) {
        for(int j=0; j<=y; j++)
            dp[i][j] = 0;
    }
    int t = 0;
    for(int i=0; i<=x; i++) {
        for(int j=0; j<=y; j++) {
            if(i==0 || j==0) dp[t][j] = 0;
            else {
                if(s1[i-1] == s2[j-1]) dp[t][j] = 1 + dp[1-t][j-1];
                else dp[t][j] = max(dp[1-t][j], dp[t][j-1]);
            }
        }
        t = 1-t;
    }
    return dp[1-t][y];
}

int main() {
	cout << lcs(5, 10, "geeks", "fogerekswq");
}
